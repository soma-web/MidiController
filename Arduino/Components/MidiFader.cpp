#include "Arduino.h"
#include "MidiFader.h"
#include "AbstractTransportController.h"

MidiFader::MidiFader(int pin, int midiControlNumber, AbstractTransportController &midiController, bool invert = false, int midiChannel = 1) : Potentiometer(pin){
    _midiControlNumber = midiControlNumber;
    _midiChannel = midiChannel;
    _midiController = &midiController;  
    _invert = invert; 
}

void MidiFader::begin(){
    Potentiometer::begin();
}

bool MidiFader::read(){
    bool returnValue = Potentiometer::read();
    if(_stateChanged){
        sendMidiCommand();
    }
}

void MidiFader::sendMidiCommand(){
    _midiController->sendControllChange(_midiControlNumber, getNormalizedValue() * 127, _midiChannel);
}

void MidiFader::forceUpdate(){
    sendMidiCommand();
}