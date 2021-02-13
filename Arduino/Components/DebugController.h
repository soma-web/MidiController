#ifndef DebugController_h
#define DebugController_h

#include "Arduino.h"
#include "AbstractTransportController.h"

class DebugController : public  AbstractTransportController
{
    public:
        DebugController();
        void begin() override;
        void sendControllChange(byte inControlNumber, byte inControlValue,int inChannel) override;
        void sendNoteOn(byte note, byte velocity, int inChannel) override;
        void sendNoteOff(byte note, byte velocity, int inChannel) override;
};

#endif