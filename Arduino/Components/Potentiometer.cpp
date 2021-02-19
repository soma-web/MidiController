#include "Arduino.h"
#include "Potentiometer.h"

Potentiometer::Potentiometer(int pin){
    _pin = pin;
}

void Potentiometer::begin()
{
    pinMode(_pin, INPUT);
    _rawValue = analogRead(_pin);
    _initialized = true;
}

bool Potentiometer::read(){    
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

int Potentiometer::getRawValue(){
    return _rawValue;
}

double Potentiometer::getNormalizedValue(){   
    return normalize(getRawValue());
}

double Potentiometer::normalize(double value){
    return (value - _minValue) / (_maxValue - _minValue);
}

void Potentiometer::forceUpdate(){
    
}

bool Potentiometer::stateChanged(){
    return _stateChanged;
}

String Potentiometer::toString(){
    String state = "";
    state += "Fader: Raw (" + String(getRawValue());
    state += ") => Normalized ("; 
    state += String(getNormalizedValue(), 3);
    state += ") changed: ";
    state += stateChanged() ? "true": "false";
    return state;
}