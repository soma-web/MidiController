#ifndef AbstractTransportController_h
#define AbstractTransportController_h

#include "Arduino.h"

using MidiControlChangeCallback        = void (*)(byte channel, byte, byte);

class AbstractTransportController
{
    public:
        virtual void begin()  = 0;
        virtual void read() = 0;
        virtual void sendControllChange(byte inControlNumber, byte inControlValue,int inChannel)  = 0;
        virtual void sendNoteOn(byte note, byte velocity, int inChannel)  = 0;
        virtual void sendNoteOff(byte note, byte velocity, int inChannel)  = 0;
        virtual void addReceiveCallBack(MidiControlChangeCallback fptr)  = 0;
};

#endif