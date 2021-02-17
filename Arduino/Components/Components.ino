#include "Potentiometer.h"
#include "Button.h"
#include "AbstractHMI.h"
#include "MidiFader.h"
#include "MidiController.h"
#include "MidiButton.h"
#include "DebugController.h"
#include "AbstractTransportController.h"
///avoid digital pin 52, this seems to be broken

#define DEBUG
//Button button(DD7);
#ifdef DEBUG
DebugController midiController;
#else
MidiController midiController;
#endif
// //equilizer rotary potis
MidiFader eqRotary0(A0, 0, midiController);
MidiFader eqRotary1(A1, 1, midiController);
MidiFader eqRotary2(A2, 2, midiController);
MidiFader eqRotary3(A3, 3, midiController);
MidiFader eqRotary4(A4, 4, midiController);
MidiFader eqRotary5(A5, 5, midiController);
MidiFader eqRotary6(A6, 6, midiController);
MidiFader eqRotary7(A7, 7, midiController);
MidiFader eqRotary8(A8, 8, midiController);
MidiFader eqRotary9(A9, 9, midiController);
MidiFader eqRotary10(A10, 10, midiController);
MidiFader eqRotary11(A11, 11, midiController);
MidiFader eqRotary12(A12, 12, midiController);
MidiFader eqRotary13(A13, 13, midiController);

MidiButton midiButton0(22, 50, midiController);
MidiButton midiButton1(24, 51, midiController);
MidiButton midiButton2(26, 52, midiController);
MidiButton midiButton3(28, 53, midiController);
MidiButton midiButton4(30, 54, midiController);
MidiButton midiButton5(32, 55, midiController);
MidiButton midiButton6(34, 56, midiController);
MidiButton midiButton7(36, 57, midiController);

MidiButton midiButton8(23, 58, midiController);
MidiButton midiButton9(25, 59, midiController);
MidiButton midiButton10(27, 60, midiController);
MidiButton midiButton11(29, 61, midiController);
MidiButton midiButton12(31, 62, midiController);
MidiButton midiButton13(33, 63, midiController);


void setup() 
{
  midiController.begin();

  eqRotary0.begin();
  eqRotary1.begin();
  eqRotary2.begin();
  eqRotary3.begin();
  eqRotary4.begin();
  eqRotary5.begin();  
  eqRotary6.begin();  
  eqRotary7.begin();  
  eqRotary8.begin();  
  eqRotary9.begin();  
  eqRotary10.begin();  
  eqRotary11.begin();  
  eqRotary12.begin();  
  eqRotary13.begin();  


  midiButton0.begin();
  midiButton1.begin();
  midiButton2.begin();
  midiButton3.begin();
  midiButton4.begin();
  midiButton5.begin();
  midiButton6.begin();
  midiButton7.begin();
  midiButton8.begin();
  midiButton9.begin();
  midiButton10.begin();
  midiButton11.begin();
  midiButton12.begin();
  midiButton13.begin();
}


void loop() 
{
  eqRotary0.read();
  eqRotary1.read();
  eqRotary2.read();
  eqRotary3.read();
  eqRotary4.read();
  eqRotary5.read();  
  eqRotary6.read();  
  eqRotary7.read();  
  eqRotary8.read();  
  eqRotary9.read();  
  eqRotary10.read();  
  eqRotary11.read();  
  eqRotary12.read();  
  eqRotary13.read();  

  midiButton0.read();
  midiButton1.read();
  midiButton2.read();
  midiButton3.read();
  midiButton4.read();
  midiButton5.read();
  midiButton6.read();
  midiButton7.read();
  midiButton8.read();
  midiButton9.read();
  midiButton10.read();
  midiButton11.read();
  midiButton12.read();
  midiButton13.read();


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

