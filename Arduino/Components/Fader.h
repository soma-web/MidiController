#ifndef Fader_h
#define Fader_h

#include "Arduino.h"

class Fader
{
  public:
    Fader(int pin);
    void begin();
    bool read();
    int getValue();
    int getRawValue();
  private:
    int _pin;
    double _maxValue = 1023;
    double _minValue = 0;
    int _rawValue;
    bool _initialized;
 
};

#endif