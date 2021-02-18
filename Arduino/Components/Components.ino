#include "Potentiometer.h"
#include "Button.h"
#include "AbstractHMI.h"
#include "MidiFader.h"
#include "MidiController.h"
#include "MidiButton.h"
#include "AbstractHMI.h"
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

MidiButton* testMidiButton;

Button synchornizrButton(44);

void SynchronizeAll();

int componentArraySize;
const int midiFaderCount = 13;
AbstractHMI* midiFaderArray[midiFaderCount]; 

const int midiButtonCount = 13;
AbstractHMI* midiButtonArray[midiButtonCount]; 

void setup() 
{
  midiController.begin();  

  for(int i = 0; i < midiFaderCount; i++){
    int analogPin = A0 + i;
    int midiControllNumber = 0 + i;
    midiFaderArray[i] = new MidiFader(analogPin, midiControllNumber, midiController);
    midiFaderArray[i]->begin();
  }

  for(int b = 0; b < midiButtonCount; b++){
    int digitalPin = 22 + b;
    int midiControllNumber = 50 + b;
    midiButtonArray[b] = new MidiButton(digitalPin, midiControllNumber, midiController);
    midiButtonArray[b]->begin();
  }

  // eqRotary0.begin();
  // eqRotary1.begin();
  // eqRotary2.begin();
  // eqRotary3.begin();
  // eqRotary4.begin();
  // eqRotary5.begin();  
  // eqRotary6.begin();  
  // eqRotary7.begin();  
  // eqRotary8.begin();  
  // eqRotary9.begin();  
  // eqRotary10.begin();  
  // eqRotary11.begin();  
  // eqRotary12.begin();  
  // eqRotary13.begin(); 
  
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

  synchornizrButton.begin();
}


void loop() 
{
  // eqRotary0.read();
  // eqRotary1.read();
  // eqRotary2.read();
  // eqRotary3.read();
  // eqRotary4.read();
  // eqRotary5.read();  
  // eqRotary6.read();  
  // eqRotary7.read();  
  // eqRotary8.read();  
  // eqRotary9.read();  
  // eqRotary10.read();  
  // eqRotary11.read();  
  // eqRotary12.read();  
  // eqRotary13.read();  
 
  for(int i = 0; i < midiFaderCount; i++){
    midiFaderArray[i]->read();
  }

  for(int b = 0; b < midiButtonCount; b++){
    midiButtonArray[b]->read();
  }

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


  synchornizrButton.read();

  if(synchornizrButton.stateChanged() && synchornizrButton.isPressed()){
    SynchronizeAll();
  }

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

void SynchronizeAll()
{
  #ifdef DEBUG
  Serial.println("synchronizing all");
  #endif
  eqRotary0.sendMidiCommand();
  eqRotary1.sendMidiCommand();
  eqRotary2.sendMidiCommand();
  eqRotary3.sendMidiCommand();
  eqRotary4.sendMidiCommand();
  eqRotary5.sendMidiCommand();  
  eqRotary6.sendMidiCommand();  
  eqRotary7.sendMidiCommand();  
  eqRotary8.sendMidiCommand();  
  eqRotary9.sendMidiCommand();  
  eqRotary10.sendMidiCommand();  
  eqRotary11.sendMidiCommand();  
  eqRotary12.sendMidiCommand();  
  eqRotary13.sendMidiCommand();  

  midiButton0.sendMidiCommand();
  midiButton1.sendMidiCommand();
  midiButton2.sendMidiCommand();
  midiButton3.sendMidiCommand();
  midiButton4.sendMidiCommand();
  midiButton5.sendMidiCommand();
  midiButton6.sendMidiCommand();
  midiButton7.sendMidiCommand();
  midiButton8.sendMidiCommand();
  midiButton9.sendMidiCommand();
  midiButton10.sendMidiCommand();
  midiButton11.sendMidiCommand();
  midiButton12.sendMidiCommand();
  midiButton13.sendMidiCommand();
}

