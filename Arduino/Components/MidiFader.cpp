#include "Arduino.h"
#include "MidiFader.h"
#include "MidiController.h"

MidiFader::MidiFader(int pin, int midiControlNumber, MidiController &midiController, int midiChannel = 1) : Potentiometer(pin){
    _midiControlNumber = midiControlNumber;
    _midiChannel = midiChannel;
    _midiController = midiController;
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
    _midiController.sendControllChange(_midiControlNumber, getNormalizedValue() * 127, _midiChannel);
}