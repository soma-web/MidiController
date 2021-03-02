using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Microsoft.Win32;
using IWshRuntimeLibrary;

namespace MidiRemoteWindowsAppliaction
{
    public partial class VoiceMeterMidi : Form
    {
        public Panel Indicator { get => panelMidiIn; }

        private MidiController midiController;
        private static string shortcutPath = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.UserProfile), "AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\MidiRemote.lnk");

        //Startup registry key and value
        private static readonly string StartupKey = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run";
        private static readonly string StartupValue = "MidiRemoteController";

        public VoiceMeterMidi()
        {
            InitializeComponent();
            btConfig.Click += new EventHandler(this.OnConfigButtonClick);
            btReconnect.Click += new EventHandler(this.OnReconnectClick);
            startWithWindowsToolStripMenuItem.Click += new EventHandler(this.OnStartWithWindowsClicked);
            startWithWindowsToolStripMenuItem.Checked = System.IO.File.Exists(shortcutPath);

            //panelMidiIn.DataBindings.Add("BackColor", this, "Background");
            Console.WriteLine("Init");
        }

        private void OnStartWithWindowsClicked(object sender, EventArgs e)
        {
            startWithWindowsToolStripMenuItem.Checked = !startWithWindowsToolStripMenuItem.Checked;

            if (startWithWindowsToolStripMenuItem.Checked)
            {
                AddToAutoStart();
            }
            else
            {
                RemoveFromAutoStart();
            }
        }
        private void RemoveFromAutoStart()
        {
            System.IO.File.Delete(shortcutPath);
        }

        private void AddToAutoStart()
        {
            Log.Debug(this, "Adding shortcut");
            string shortcutto = System.Reflection.Assembly.GetExecutingAssembly().Location;

            var wsh = new IWshShell_Class();
            IWshRuntimeLibrary.IWshShortcut shortcut = wsh.CreateShortcut(shortcutPath) as IWshRuntimeLibrary.IWshShortcut;
            shortcut.TargetPath = shortcutto;
            shortcut.WorkingDirectory = Directory.GetParent(shortcutto).FullName;
            shortcut.Save();
        }

        private void OnReconnectClick(object sender, EventArgs e)
        {
            this.midiController.Reconnect();
        }

        internal void SetMidiController(MidiController midiController)
        {
            this.midiController = midiController;
        }

        public void SetConnectionInfo(ConnectionInfo connectionInfo)
        {
            lbDeviceName.DataBindings.Add("Text", connectionInfo, "DeviceName");
            lbConnectionStatus.DataBindings.Add("Text", connectionInfo, "Status");
        }

        private void OnConfigButtonClick(object sender, EventArgs e)
        {
            Process.Start(Log.path);
        }

        private void OnResize(object sender, EventArgs e)
        {
            //if the form is minimized  
            //hide it from the task bar  
            //and show the system tray icon (represented by the NotifyIcon control)  
            if (this.WindowState == FormWindowState.Minimized)
            {
                Hide();
                notifyIcon1.Visible = true;
            }
        }

        private void OnNotifyDoubleClick(object sender, MouseEventArgs e)
        {
            Show();
            this.WindowState = FormWindowState.Normal;
            notifyIcon1.Visible = false;
        }

        private void lbDeviceNameLabel_Click(object sender, EventArgs e)
        {

        }

        private void lbConnectionStatusLabel_Click(object sender, EventArgs e)
        {

        }

        private void btSync_Click(object sender, EventArgs e)
        {
            midiController.SendSyncCommand();
        }





        //private void OnKeyDown(object sender, KeyEventArgs e)
        //{
        //    if (e.KeyCode == Keys.A)
        //    {
        //        toggle = !toggle;
        //        Background = toggle ? Color.Blue : Color.Red;
        //        Console.WriteLine("A Pressed");
        //    }
        //}
    }
}
