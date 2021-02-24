using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MidiRemoteWindowsAppliaction
{
    public class InputIndicator : INotifyPropertyChanged
    {
        private Timer timer1;
        private int time;
        private const int maxTime = 500;
        private Color onInMapColor = Color.Green;
        private Color onNotInMapColor = Color.Violet;
        private Color offColor = Color.Transparent;

        public event PropertyChangedEventHandler PropertyChanged;

        private Color _background = Color.Red;
        public Color Background
        {
            get
            {
                return _background;
            }

            set
            {
                if(value != _background)
                {
                    _background = value;
                    PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("Background"));
                }
            }
        }
        public InputIndicator(IBindableComponent bindableComponent, string componentPropertyName)
        {
            InitTimer();
            bindableComponent.DataBindings.Add(componentPropertyName, this, "Background");
        }

        public void InitTimer()
        {
            timer1 = new Timer();
            timer1.Tick += new EventHandler(Update);
            timer1.Interval = 20; // in miliseconds
            timer1.Start();
        }

        private void Update(object sender, EventArgs e)
        {
            if(time < maxTime)
            {
                time += timer1.Interval;                
            }
            else
            {
                Background = offColor;
            }
        }

        public void TurnOn(bool bindedInput)
        {
            time = 0;
            Background = bindedInput ? onInMapColor : onNotInMapColor;
        }

        public void TurnOff()
        {
            Background = offColor;
        }

    }
}
