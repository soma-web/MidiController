#include "Arduino.h"
#include "MidiButton.h"
#include "MidiController.h"

MidiButton::MidiButton(int pin, int midiControlNumber, MidiController &midiController, int midiChannel = 1) : Button(pin){
    _midiControlNumber = midiControlNumber;
    _midiChannel = midiChannel;
    _midiController = midiController;
}

void MidiButton::begin(){
    Button::begin();
}

bool MidiButton::read(){
    bool returnValue = Button::read();
    if(_stateChanged){
        sendMidiCommand();
    }
}

void MidiButton::sendMidiCommand(){
    int value = Button::isPressed() ? 127 : 0;
    _midiController.sendControllChange(_midiControlNumber, value, _midiChannel);
}