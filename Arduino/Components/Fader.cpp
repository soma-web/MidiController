#include "Arduino.h"
#include "Fader.h"

Fader::Fader(int pin){
    _pin = pin;
}

void Fader::begin()
{
    pinMode(_pin, INPUT);
    _rawValue = analogRead(_pin);
    _initialized = true;
}

bool Fader::read(){    
    if(_initialized == false) {
        Serial.println("begin() not called");
        return false;
    }
    _stateChanged = false;
    int oldValue = _rawValue;
    if(abs(analogRead(_pin) - oldValue) > _threshold ){
         _rawValue = analogRead(_pin);
        _stateChanged = true;
    }
    return true;   
}

int Fader::getRawValue(){
    return _rawValue;
}

double Fader::getNormalizedValue(){   
    return normalize(getRawValue());
}

double Fader::normalize(double value){
    return (value - _minValue) / (_maxValue - _minValue);
}

bool Fader::stateChanged(){
    return _stateChanged;
}

String Fader::toString(){
    String state = "";
    state += "Fader: Raw (" + String(getRawValue());
    state += ") => Normalized ("; 
    state += String(getNormalizedValue(), 3);
    state += ") changed: ";
    state += stateChanged() ? "true": "false";
    return state;
}