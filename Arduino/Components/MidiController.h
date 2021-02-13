#ifndef MidiController_h
#define MidiController_h

#include "Arduino.h"

#include <MIDI.h>

class MidiController
{
    public:
        MidiController();
        virtual void begin();
        virtual void sendControllChange(byte inControlNumber, byte inControlValue,int inChannel);
        virtual void sendNoteOn(byte note, byte velocity, int inChannel);
        virtual void sendNoteOff(byte note, byte velocity, int inChannel);

    private:
        bool _initialized;
};

#endif