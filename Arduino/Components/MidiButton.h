#ifndef MidiButton_h
#define MidiButton_h

#include "Arduino.h"
#include "Button.h"
#include "MidiController.h"
   
class MidiButton : public Button
{
  public:
    MidiButton(int pin, int midiControlNumber, MidiController &midiController, int midiChannel = 1);
    void begin();
    bool read();
  protected:      
    MidiController &_midiController;    
    int _midiControlNumber;    
    int _midiChannel;
    void sendMidiCommand();

};

#endif