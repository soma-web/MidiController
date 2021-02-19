#include "USBMidiTransport.h"
#include "MidiFader.h"
#include "Potentiometer.h"
#include "Button.h"
#include "AbstractHMI.h"
#include "MidiButton.h"
#include "AbstractHMI.h"
#include "DebugController.h"
#include "AbstractTransportController.h"
#include "NullTransport.h"
/// avoid digital pin 52, this seems to be broken

#define DEBUG

#ifdef DEBUG
DebugController midiController;
NullTransport nulltransport;
#else
USBMidiTransport midiController;

#endif
const int buttonPinArray[] = {
  22, 24, 26, 28, 30, 32, 34, 36, 23, 25, 27, 29, 31, 33,
};
const int buttonPinArraySize = 14;

const int potentiometerPinArray[] = {
   A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13,
};
const int potentiometerPinArraySize = 14;

const int midiComponentCount = potentiometerPinArraySize;// + buttonPinArraySize;
AbstractHMI* midiComponentArray[midiComponentCount]; 


Button synchornizeButton(44);
void SynchronizeAll();
void SetupAbstractHMIArray();

void setup() 
{
  midiController.begin(); 
  SetupAbstractHMIArray();

  //synchornizeButton.begin();
}

void loop() 
{
  for(int i = 0; i < midiComponentCount; i++){
    midiComponentArray[i]->read();
  }

  // no hadware for that so we skip it atm
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
  Serial.println("fader count: " + String(potentiometerPinArraySize));
  Serial.println("button count: " + String(buttonPinArraySize));
  #endif

  //start fader with midiControllNbr 0
  int midiControllNbr = 0;
  for(int i = 0; i < potentiometerPinArraySize; i++, midiComponentArrayPosition++){
    int midiControllNumber = midiControllNbr + i;
    midiComponentArray[i] = new MidiFader(potentiometerPinArray[i], midiControllNumber, midiController);
    midiComponentArray[i]->begin();
  }

  //start buttons with contollNbr 50 
  midiControllNbr = 50;
  for(int i = 0; i < buttonPinArraySize; i++, midiComponentArrayPosition++){
    int midiControllNumber = midiControllNbr + i;
    midiComponentArray[midiComponentArrayPosition] = new MidiButton(buttonPinArray[i], midiControllNumber, nulltransport);
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

