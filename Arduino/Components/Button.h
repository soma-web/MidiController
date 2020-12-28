#ifndef Button_h
#define Button_h

#include "Arduino.h"
#include "AbstractHMI.h"
   
class Button : public AbstractHMI
{
  public:
    Button(int pin, boolean invert = false, boolean pullup = false);
    void begin();
    bool read();
    bool isPressed();
    bool stateChanged();
    unsigned int count();
    void resetCount();
    String toString();
  protected:    
    int _pin;
    byte _state, _lastState, _reading;
    unsigned int _count;
    unsigned long _delay, _last;
    boolean _wait;
    boolean _invert;
    boolean _initialized;    
    boolean _stateChanged;
};

#endif