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
// MidiFader eqRotary0(A0, 0, midiController);
// MidiFader eqRotary1(A1, 1, midiController);
// MidiFader eqRotary2(A2, 2, midiController);
// MidiFader eqRotary3(A3, 3, midiController);
// MidiFader eqRotary4(A4, 4, midiController);
// MidiFader eqRotary5(A5, 5, midiController);
// MidiFader eqRotary6(A6, 6, midiController);
// MidiFader eqRotary7(A7, 7, midiController);
// MidiFader eqRotary8(A8, 8, midiController);
// MidiFader eqRotary9(A9, 9, midiController);
// MidiFader eqRotary10(A10, 10, midiController);
// MidiFader eqRotary11(A11, 11, midiController);
// MidiFader eqRotary12(A12, 12, midiController);
// MidiFader eqRotary13(A13, 13, midiController);

// MidiButton midiButton0(22, 50, midiController);
// MidiButton midiButton1(24, 51, midiController);
// MidiButton midiButton2(26, 52, midiController);
// MidiButton midiButton3(28, 53, midiController);
// MidiButton midiButton4(30, 54, midiController);
// MidiButton midiButton5(32, 55, midiController);
// MidiButton midiButton6(34, 56, midiController);
// MidiButton midiButton7(36, 57, midiController);

// MidiButton midiButton8(23, 58, midiController);
// MidiButton midiButton9(25, 59, midiController);
// MidiButton midiButton10(27, 60, midiController);
// MidiButton midiButton11(29, 61, midiController);
// MidiButton midiButton12(31, 62, midiController);
// MidiButton midiButton13(33, 63, midiController);

const int buttonPinArray[] = {
  22, 24, 26, 28, 30, 32, 34, 36, 23, 25, 27, 29, 31, 33,
};
const int buttonPinArraySize = 14;

const int faderPinArray[] = {
  A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13,
};
const int faderPinArraySize = 14;

const int midiComponentCount = faderPinArraySize + buttonPinArraySize;
AbstractHMI* midiComponentArray[midiComponentCount]; 


Button synchornizeButton(44);
void SynchronizeAll();
void SetupAbstractHMIArray();

void setup() 
{
  midiController.begin(); 
  // synchornizeButton.begin();

  SetupAbstractHMIArray();
}

void loop() 
{
  for(int i = 0; i < midiComponentCount; i++){
    midiComponentArray[i]->read();
  }

  // synchornizeButton.read();
  // if(synchornizeButton.stateChanged() && synchornizeButton.isPressed()){
  //   SynchronizeAll();
  // }

  delay(100);        // delay in between reads for stability
}

void SetupAbstractHMIArray()
{
  int midiComponentArrayPosition = 0;
  #ifdef DEBUG
  Serial.println("fader count: " + String(faderPinArraySize));
  Serial.println("button count: " + String(buttonPinArraySize));
  #endif

  //start fader with midiControllNbr 0
  int midiControllNbr = 0;
  for(int i = 0; i < faderPinArraySize; i++, midiComponentArrayPosition++){
    int midiControllNumber = midiControllNbr + i;
    midiComponentArray[i] = new MidiFader(faderPinArray[i], midiControllNumber, midiController);
    midiComponentArray[i]->begin();
  }

  //start buttons with contollNbr 50 
  midiControllNbr = 50;
  for(int i = 0; i < buttonPinArraySize; i++, midiComponentArrayPosition++){
    int midiControllNumber = midiControllNbr + i;
    midiComponentArray[midiComponentArrayPosition] = new MidiButton(buttonPinArray[i], midiControllNumber, midiController);
    midiComponentArray[midiComponentArrayPosition]->begin();
  }
}

/// force all midicomponents to send their current state
void SynchronizeAll()
{
  #ifdef DEBUG
  Serial.println("synchronizing all");
  #endif

  for(int i = 0; i < midiComponentCount; i++){
    midiComponentArray[i]->forceUpdate();
  }
}

