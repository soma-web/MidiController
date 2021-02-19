// #ifndef MidiController_h
// #define MidiController_h

// #ifndef MidiController_h
// #define MidiController_h

// #include "Arduino.h"
// #include "AbstractTransportController.h"
// #include <MIDI.h>

// class MidiController : public  AbstractTransportController
// {
//     public:
//         MidiController();
//         void begin() override;
//         void sendControllChange(byte inControlNumber, byte inControlValue,int inChannel) override;
//         void sendNoteOn(byte note, byte velocity, int inChannel) override;
//         void sendNoteOff(byte note, byte velocity, int inChannel) override;

//     private:
//         bool _initialized;
// };

// #endif