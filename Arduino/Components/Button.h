#ifndef Button_h
#define Button_h

#include "Arduino.h"
#include "AbstractHMI.h"
   
class Button : public AbstractHMI
{
  public:
    Button(uint8_t pin, boolean invert = false, boolean pullup = true);
    void begin();
    bool read();
    bool isPressed();
    bool stateChanged();
    unsigned int count();
    void resetCount();
    void forceUpdate();
    String toString();
  protected:    
    uint8_t _pin;
    byte _state, _lastState, _reading;
    unsigned int _count;
    unsigned long _delay, _last;
    boolean _wait;
    boolean _invert;
    boolean _initialized;    
    boolean _stateChanged;
    boolean _pullup;
};

#endif