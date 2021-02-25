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
            Log.Init();
            var form = new VoiceMeterMidi();
            var indicator = new InputIndicator(form.Indicator, "BackColor");
            var connectionInfo = new ConnectionInfo();
            form.SetConnectionInfo(connectionInfo);
            MidiController midiController = new MidiController(indicator, connectionInfo);
            form.SetMidiController(midiController);
            Application.Run(form);

            Log.Debug("Programm", "Closing");
            midiController.Dispose();
        }
    }
}
