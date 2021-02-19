#ifndef NullTransport_h
#define NullTransport_h

#include "AbstractTransportController.h"

class NullTransport : public AbstractTransportController
{
    public:
        void begin() override;
        void sendControllChange(byte inControlNumber, byte inControlValue,int inChannel) override;
        void sendNoteOn(byte note, byte velocity, int inChannel) override;
        void sendNoteOff(byte note, byte velocity, int inChannel) override;
};

#endif