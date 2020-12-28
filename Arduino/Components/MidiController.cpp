#include "Arduino.h"
#include "MidiController.h"
#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE(); // Create an instance of the midi library

MidiController::MidiController(){
    
}

void MidiController::begin()
{
     MIDI.begin(0);
     _initialized = true;
}

void MidiController::sendControllChange(byte inControlNumber, byte inControlValue,int inChannel)
{
    MIDI.sendControlChange(inControlNumber, inControlValue, inChannel);
}

void MidiController::sendNoteOn(byte note, byte velocity ,int inChannel)
{
    MIDI.sendNoteOn(note, velocity, inChannel);
}

void MidiController::sendNoteOff(byte note, byte velocity,int inChannel)
{
    MIDI.sendNoteOff(note, velocity, inChannel);
}