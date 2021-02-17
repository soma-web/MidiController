#ifndef MidiButton_h
#define MidiButton_h

#include "Arduino.h"
#include "Button.h"
#include "AbstractTransportController.h"
   
class MidiButton : public Button
{
  public:
    MidiButton(int pin, int midiControlNumber, AbstractTransportController &midiController, int midiChannel = 1);
    void begin();
    bool read();  
    void sendMidiCommand();
  protected:      
    AbstractTransportController *_midiController;    
    int _midiControlNumber;    
    int _midiChannel;

};

#endif