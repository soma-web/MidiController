﻿using MidiRemoteWindowsAppliaction.Configuration;
using Sanford.Multimedia.Midi;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;

namespace MidiRemoteWindowsAppliaction
{
    public class MidiController : IDisposable
    {
        private Config config;
        private Dictionary<int, BindingLine> inputMap;

        private VmClient voiceMeter;
        private OutputDevice outputDevice;
        private InputDevice inputDevice;

        private static List<IDisposable> disps = new List<IDisposable>();

        private Action<Exception> OnError;
        private bool running;

        private Timer updateTimer;
        private InputIndicator inputIndindicator;
        private ConnectionInfo connectionInfo;
        public MidiController(InputIndicator inputIndindicator, ConnectionInfo connectionInfo, Action<Exception> errorHandler = null)
        {
            this.inputIndindicator = inputIndindicator;
            this.connectionInfo = connectionInfo;

            OnError += errorHandler;
            config = Config.Load();
            inputMap = config.Bindings.Where(x => (x.Dir & BindingDir.FromBoard) != 0).ToDictionary(x => x.ControlId);

            InitVoiceMeter();
            InitOutputDevice();
            InitInputputDevice();
            InitTimer();
            Log.Debug(this, "All initialised");
        }

        public void Dispose()
        {
            Log.Debug(this, "Exiting...");
            //Thread.Sleep(5000);
            running = false;
            foreach (var x in disps)
            {
                x?.Dispose();
            }
            Log.Debug(this, "Cleanup done...");
        }

        public void Reconnect()
        {
            running = false;
            disps.Clear();
            inputDevice.Dispose();
            outputDevice.Dispose();
            InitOutputDevice();
            InitInputputDevice();
            running = true;
        }

        public void SendSyncCommand()
        {
            outputDevice?.Send(new ChannelMessage(ChannelCommand.Controller, 0, 99, 99));
        }

        private void Update(object sender, EventArgs e)
        {
            if (!running) return;

            if (voiceMeter.Poll())
            {
                foreach (var x in config.Bindings.Where(x => (x.Dir & BindingDir.ToBoard) != 0))
                {
                    var vmVal = voiceMeter.GetParam(x.VoicemeeterParam);
                    var scaled = Scale(vmVal, x.VmFrom, x.VmTo, x.ControlFrom, x.ControlTo);
                    outputDevice.Send(new ChannelMessage(ChannelCommand.Controller, 0, x.ControlId, (int)scaled));
                }
            }
        }

        private void OnMidiCommandReceived(object sender, ChannelMessageEventArgs e)
        {
            var m = e.Message;
            Log.Debug(this, "e.Message channel:" + e.Message.MidiChannel + " " + e.Message.Message);
            if (m.MessageType == MessageType.Channel && m.Command == ChannelCommand.Controller)
            {
                Log.Debug(this, "m.Data1 " + m.Data1 + " Data2 " + m.Data2);
                inputIndindicator.TurnOn(inputMap.ContainsKey(m.Data1));

                if (inputMap.ContainsKey(m.Data1))
                {
                    var v = inputMap[m.Data1];
                    if (v.FullRangeToggle)
                    {
                        var current = voiceMeter.GetParam(v.VoicemeeterParam);
                        var setTo = m.Data2 > 50 ? 0 : 1;
                        Log.Debug(this, "FullRangeToggle: Set Param To: " + setTo);
                        voiceMeter.SetParam(v.VoicemeeterParam, setTo);
                    }
                    else if (v.ControlToggle && m.Data2 == v.ControlTo)
                    {
                        var current = voiceMeter.GetParam(v.VoicemeeterParam);
                        voiceMeter.SetParam(v.VoicemeeterParam, v.VmTo - current);
                        Log.Debug(this, "Toggle: Set Param To: " + (v.VmTo - current));
                    }
                    else if (!v.ControlToggle)
                    {
                        var scaledVal = Scale(m.Data2, v.ControlFrom, v.ControlTo, v.VmFrom, v.VmTo);
                        voiceMeter.SetParam(v.VoicemeeterParam, scaledVal);
                        Log.Debug(this, "SetParam No Toggle" + (scaledVal));
                    }
                }
            }
        }

        private void InitTimer()
        {
            running = true;
            updateTimer = new Timer();
            updateTimer.Tick += new EventHandler(Update);
            updateTimer.Interval = 20;
            updateTimer.Start();
        }

        void InitVoiceMeter()
        {
            voiceMeter = new VmClient();
            voiceMeter.OnClose(() =>
            {
                foreach (var x in config.Bindings.Where(x => (x.Dir & BindingDir.ToBoard) != 0))
                {
                    outputDevice.Send(new ChannelMessage(ChannelCommand.Controller, 0, x.ControlId, (int)x.ControlFrom));
                }
            });
            disps.Add(voiceMeter);
        }

  

        void InitOutputDevice()
        {
            var outputId = GetMidiOutputDevice(config.DeviceName);
            if (outputId >= 0)
            {
                outputDevice = new OutputDevice(outputId);
            }
            disps.Add(outputDevice);
        }

        void InitInputputDevice()
        {
            var inputDevice = GetMidiInputDevice(config.DeviceName);
            var inputId = inputDevice.Item2;
            var inputName = inputDevice.Item1;
            if (inputId >= 0)
            {
                this.inputDevice = new InputDevice(inputId);
                this.inputDevice.Error += (sender, errArgs) => { connectionInfo.Status = ConnectionInfo.ConnectionStatus.Disconnected; Log.Debug(this, "Error: " + errArgs.Error + " from: " + sender); OnError?.Invoke(new Exception("Error: " + errArgs.Error + " from: " + sender)); };                
                this.inputDevice.ChannelMessageReceived += OnMidiCommandReceived;
                this.inputDevice.StartRecording();
                connectionInfo.Status = ConnectionInfo.ConnectionStatus.Connected;
                connectionInfo.DeviceName = inputName;
            }
            else
            {
                Log.Debug(this, "No Input Device Found");
            }
            disps.Add(this.inputDevice);
        }

        private int GetMidiOutputDevice(string partialDeviceName)
        {
            for (int i = 0; i < OutputDeviceBase.DeviceCount; i++)
            {
                var info = OutputDeviceBase.GetDeviceCapabilities(i);
                if (info.name.Contains(partialDeviceName))
                    return i;
            }
            OnError?.Invoke(new Exception($"Cannot find output midi device with '{partialDeviceName}' in the name."));
            return -1;
            //throw new Exception($"Cannot find output midi device with '{partialDeviceName}' in the name.");
        }

        private Tuple<string,int> GetMidiInputDevice(string partialDeviceName)
        {
            for (int i = 0; i < InputDevice.DeviceCount; i++)
            {
                var info = InputDevice.GetDeviceCapabilities(i);
                if (info.name.Contains(partialDeviceName))
                    return new Tuple<string, int>(info.name, i);
            }
            OnError?.Invoke(new Exception($"Cannot find input midi device with '{partialDeviceName}' in the name."));
            return new Tuple<string, int>(null, -1);
        }

        private static float Scale(float value, float fromMin, float fromMax, float toMin, float toMax)
        {
            var zeroToOne = ((value - fromMin) / (fromMax - fromMin));
            var ans = zeroToOne * (toMax - toMin) + toMin;
            //Console.WriteLine($"Scale {value} from {fromMin}..{fromMax} to {toMin}..{toMax}: {zeroToOne} {ans}");
            return ans;
        }

     
    }
}
