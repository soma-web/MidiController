using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MidiRemoteWindowsAppliaction
{
    [Flags]
    public enum BindingDir
    {
        ToBoard = 1,
        FromBoard = 2,
        TwoWay = 3,
    }
}
