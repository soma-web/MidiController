using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MidiRemoteWindowsAppliaction
{
    public class ConnectionInfo : INotifyPropertyChanged
    {
        public event PropertyChangedEventHandler PropertyChanged;

        public enum ConnectionStatus
        {
            None,
            Disconnected,
            Connected,
        };

        private ConnectionStatus _concectionStatus;
        public ConnectionStatus Status
        {
            get
            {
                return _concectionStatus;
            }
            set
            {
                _concectionStatus = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("Status"));
            }
        }

        private String _deviceName = "No Device";
        public String DeviceName
        {
            get
            {
                return _deviceName;
            }
            set
            {
                _deviceName = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("DeviceName"));
            }
        }
    }
}
