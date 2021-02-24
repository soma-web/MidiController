#ifndef USBMidiTransport_h
#define USBMidiTransport_h

#include "AbstractTransportController.h"
#include <midi_Defs.h>



class USBMidiTransport : public AbstractTransportController
{
    public:
        void begin() override;
        void read() override;
        void sendControllChange(byte inControlNumber, byte inControlValue,int inChannel) override;
        void sendNoteOn(byte note, byte velocity, int inChannel) override;
        void sendNoteOff(byte note, byte velocity, int inChannel) override;
        void addReceiveCallBack(MidiControlChangeCallback fptr) override;

        void HandleControlChange(byte channel, byte number, byte value);
};

#endif