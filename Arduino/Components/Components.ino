#include "Potentiometer.h"
#include "Button.h"
#include "AbstractHMI.h"
#include "MidiFader.h"
#include "MidiController.h"
#include "MidiButton.h"
#include "DebugController.h"
#include "AbstractTransportController.h"

#define DEBUG
//Button button(DD7);
#ifdef DEBUG
DebugController midiController;
#else
MidiController midiController;
#endif
// //equilizer rotary potis
MidiFader eqRotary0(A0, 0, midiController);
// MidiFader eqRotary1(A1, 1, midiController);
// MidiFader eqRotary2(A2, 2, midiController);
// MidiFader eqRotary3(A3, 3, midiController);
// MidiFader eqRotary4(A4, 4, midiController);
// MidiFader eqRotary5(A5, 5, midiController);


void setup() 
{

  midiController.begin();

  eqRotary0.begin();
  // eqRotary1.begin();
  // eqRotary2.begin();
  // eqRotary3.begin();
  // eqRotary4.begin();
  // eqRotary5.begin();  
}


void loop() 
{
  eqRotary0.read();
  // eqRotary1.read();
  // eqRotary2.read();
  // eqRotary3.read();
  // eqRotary4.read();
  // eqRotary5.read();  

  // int pinvalue = analogRead(A0);
  // Serial.println("AO Value");
  // Serial.println(pinvalue);

 
  delay(100);        // delay in between reads for stability
}

