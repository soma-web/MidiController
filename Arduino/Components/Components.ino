#include <MIDI.h>
#include "Potentiometer.h"
#include "Button.h"
#include "AbstractHMI.h"
#include "MidiFader.h"
#include "MidiController.h"

Button button(DD7);
MidiController midiController;
MidiFader midiFader(A0, 2, midiController);

//AbstractHMI* abstractArray[] = {&button, &fader};

void setup() {
  #ifdef DEBUG
    // initialize serial communication at 9600 bits per second: 
    Serial.begin(9600); 
  #endif

    button.begin();
    midiController.begin();
    midiFader.begin();
}

// the loop routine runs over and over again forever:
void loop() {

  midiFader.read();
  button.read();

  #ifdef MIDI_ON
  if(button.stateChanged())
  {
    int value = 0;
    if(button.isPressed())
    {
      value = 127;
    }
    midiController.sendControllChange(3, value, 1);
  #endif

  #ifdef DEBUG
    Serial.println(button.toString());
    Serial.println(fader.toString());
  #endif
  delay(200);        // delay in between reads for stability
}

