#ifndef Fader_h
#define Fader_h

#include "Arduino.h"

class Fader
{
  public:
    Fader(int pin);
    void begin();
    bool read();
    int getRawValue();
    double getNormalizedValue();
    bool stateChanged();
    String toString();
  private:
    double normalize(double value);
    int _pin;
    double _maxValue = 1023;
    double _minValue = 0;
    int _threshold = 2;
    int _rawValue;
    bool _initialized;
    bool _stateChanged;
 
};

#endif