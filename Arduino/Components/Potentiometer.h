#ifndef Fader_h
#define Fader_h

#include "Arduino.h"
#include "AbstractHMI.h"

class Potentiometer : public AbstractHMI
{
  public:
    Potentiometer(int pin);
    void begin();
    bool read();
    bool stateChanged();
    int getRawValue();
    double getNormalizedValue();
    void forceUpdate();
    String toString();
  protected:
    double normalize(double value);
    int _pin;
    double _maxValue = 1023;
    double _minValue = 0;
    int _threshold = 5;
    int _rawValue;
    bool _initialized;
    bool _stateChanged; 
};

#endif