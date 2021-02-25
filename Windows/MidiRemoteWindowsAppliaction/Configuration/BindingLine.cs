using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MidiRemoteWindowsAppliaction.Configuration
{
    public class BindingLine
    {
        public BindingDir Dir { get; set; }
        public int ControlId { get; set; }
        public string VoicemeeterParam { get; set; }
        public float ControlFrom { get; set; }
        public float ControlTo { get; set; }
        public bool ControlToggle { get; set; }
        public bool FullRangeToggle { get; set; }
        public float VmFrom { get; set; }
        public float VmTo { get; set; }
    }
}
