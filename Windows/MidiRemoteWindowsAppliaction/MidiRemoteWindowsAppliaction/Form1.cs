using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MidiRemoteWindowsAppliaction
{
    public partial class VoiceMeterMidi : Form
    {
        private bool toggle;

        public Panel Indicator { get => panelMidiIn; }

        public VoiceMeterMidi()
        {
            InitializeComponent();
            btConfig.Click += new EventHandler(this.OnConfigButtonClick);
            //panelMidiIn.DataBindings.Add("BackColor", this, "Background");
            Console.WriteLine("Init");
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
