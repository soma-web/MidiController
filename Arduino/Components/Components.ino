#include <MIDI.h>
#include "Potentiometer.h"
#include "Button.h"
#include "AbstractHMI.h"
#include "MidiFader.h"
#include "MidiController.h"

#define MIDI_ON
#define C3 48

// #ifdef MIDI_ON
//   MIDI_CREATE_DEFAULT_INSTANCE(); // Create an instance of the midi library
// #endif

// 0 Analog pin
Potentiometer fader(A0);
//digital 7 pin
Button button(DD7);
MidiController midiController;
AbstractHMI* abstractArray[] = {&button, &fader};

void setup() {
  #ifdef DEBUG
    // initialize serial communication at 9600 bits per second: 
    Serial.begin(9600); 
  #endif

  // #ifdef MIDI_ON
  //   MIDI.begin(MIDI_CHANNEL_OMNI); // Begin MIDI and listen to all channels
  // #endif

    fader.begin();
    button.begin();
    midiController.begin();
}

// the loop routine runs over and over again forever:
void loop() {
  fader.read();  
  button.read();

  #ifdef MIDI_ON
  if(button.stateChanged())
  {
    int value = 0;
    if(button.isPressed())
    {
      value = 127;
    }
    //MIDI.sendControlChange(2, value, 1);
    midiController.sendControllChange(2, value, 1);
  }

  if(fader.stateChanged())
  {
    // MIDI.sendControlChange(1, fader.getNormalizedValue()*127, 1);
    midiController.sendControllChange(2, fader.getNormalizedValue() * 127, 1);
  }

  #endif

  #ifdef DEBUG
    Serial.println(button.toString());
    Serial.println(fader.toString());
  #endif
  delay(200);        // delay in between reads for stability
}

