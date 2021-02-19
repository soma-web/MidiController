#include "USBMidiTransport.h"
#include <MIDI.h>


MIDI_CREATE_DEFAULT_INSTANCE();

void USBMidiTransport::begin()
{
     MIDI.begin(0);
}

void USBMidiTransport::sendControllChange(byte inControlNumber, byte inControlValue,int inChannel)
{
    MIDI.sendControlChange(inControlNumber, inControlValue, inChannel);
}

void USBMidiTransport::sendNoteOn(byte note, byte velocity ,int inChannel)
{
    MIDI.sendNoteOn(note, velocity, inChannel);
}

void USBMidiTransport::sendNoteOff(byte note, byte velocity,int inChannel)
{
    MIDI.sendNoteOff(note, velocity, inChannel);
}