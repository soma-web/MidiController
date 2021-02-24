using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MidiRemoteWindowsAppliaction
{
    public enum VbLoginResponse
    {
        OK = 0,
        OkVoicemeeterNotRunning = 1,
        NoClient = -1,
        AlreadyLoggedIn = -2,
    }
}
