#ifndef MidiFader_h
#define MidiFader_h

#include "Arduino.h"
#include "Potentiometer.h"
#include "MidiController.h"
   
class MidiFader : public Potentiometer
{
  public:
    MidiFader(int pin, int midiControlNumber, MidiController &midiController, int midiChannel = 1);
    void begin();
    bool read();
  protected:      
    MidiController &_midiController;    
    int _midiControlNumber;    
    int _midiChannel;
    void sendMidiCommand();

};

#endif