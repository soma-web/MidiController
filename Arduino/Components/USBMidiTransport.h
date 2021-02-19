#ifndef USBMidiTransport_h
#define USBMidiTransport_h

#include "AbstractTransportController.h"

class USBMidiTransport : public AbstractTransportController
{
    public:
        void begin() override;
        void sendControllChange(byte inControlNumber, byte inControlValue,int inChannel) override;
        void sendNoteOn(byte note, byte velocity, int inChannel) override;
        void sendNoteOff(byte note, byte velocity, int inChannel) override;
};

#endif