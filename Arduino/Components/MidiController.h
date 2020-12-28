#ifndef MidiController_h
#define MidiController_h

#include "Arduino.h"

#include <MIDI.h>

class MidiController
{
    public:
        MidiController();
        void begin();
        void sendControllChange(byte inControlNumber, byte inControlValue,int inChannel);
        void sendNoteOn(byte note, byte velocity, int inChannel);
        void sendNoteOff(byte note, byte velocity, int inChannel);

    private:
        bool _initialized;
};

#endif