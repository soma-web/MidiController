#ifndef MidiFader_h
#define MidiFader_h

#include "Arduino.h"
#include "Potentiometer.h"
#include "AbstractTransportController.h"
   
class MidiFader : public Potentiometer
{
  public:
    MidiFader(int pin, int midiControlNumber, AbstractTransportController &midiController, int midiChannel = 1);
    void begin();
    bool read();
    void sendMidiCommand();
    void forceUpdate();
  protected:      
    AbstractTransportController *_midiController;    
    int _midiControlNumber;    
    int _midiChannel;

};

#endif