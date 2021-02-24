using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MidiRemoteWindowsAppliaction
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            var form = new VoiceMeterMidi();
            Log.Init();
            MidiController midiController = new MidiController(new InputIndicator(form.Indicator, "BackColor"));
            Application.Run(form);
        }
    }
}
