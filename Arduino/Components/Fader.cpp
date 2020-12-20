#include "Arduino.h"
#include "Fader.h"

Fader::Fader(int pin){
    _pin = pin;
}

void Fader::begin()
{
    pinMode(_pin, INPUT);
    _initialized = true;
}

bool Fader::read(){    
    if(_initialized == false) {
        Serial.println("begin() not called");
        return false;
    }
    _rawValue = (double)analogRead(_pin);
    return true;
   
}

int Fader::getRawValue(){
    return _rawValue;
}

int Fader::getValue(){
    int value = (getRawValue() / _maxValue) * 100.;
    return (int)value;
}