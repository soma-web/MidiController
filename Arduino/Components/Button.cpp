#include "Arduino.h"
#include "Button.h"

Button::Button(int pin, boolean invert = true, boolean pullup = false)
{
    _pin = pin;
    _delay = 50;
    _state = _lastState = _reading = (invert ^ digitalRead(_pin));
    _last = millis();
    _count = 0;
    _invert = invert;
}

void Button::begin()
{      
    _initialized = true;
}

bool Button::read(){    
    _reading = _invert ^ digitalRead(_pin); // get current button state.
    _stateChanged = false;
    if (_reading != _lastState)
    {                   // detect edge: current vs last state:
        _last = millis(); // store millis if change was detected.
        _wait = true;     // Just to avoid calling millis() unnecessarily.
    }

    if (_wait && (millis() - _last) > _delay)
    { // after the delay has passed:
        if (_reading != _state)
        {                    // if the change wasn't stored yet:
            _count++;          // Stores each change.
            _state = _reading; // store the button state change.
            _wait = false;
            _stateChanged = true;
        }
    }
    _lastState = _reading;
    return _state; 
}

bool Button::isPressed(){
    return _state;
}

bool Button::stateChanged(){
    return _stateChanged;
}

void Button::resetCount(){
     _count = 0;
}

unsigned int Button::count(){
     return _count; 
}