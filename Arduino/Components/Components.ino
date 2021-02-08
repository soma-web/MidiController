#include <MIDI.h>
#include "Potentiometer.h"
#include "Button.h"
#include "AbstractHMI.h"
#include "MidiFader.h"
#include "MidiController.h"
#include "MidiButton.h"

#define DEBUG

//Button button(DD7);
MidiController midiController;
// //equilizer rotary potis
MidiFader eqRotary0(A0, 0, midiController);
MidiFader eqRotary1(A1, 1, midiController);
MidiFader eqRotary2(A2, 2, midiController);
MidiFader eqRotary3(A3, 3, midiController);
MidiFader eqRotary4(A4, 4, midiController);
MidiFader eqRotary5(A5, 5, midiController);

// AbstractHMI* abstractHMIArray[] = {
//   &eqRotary0,
//   &eqRotary1,
//   &eqRotary2,
//   &eqRotary3,
//   &eqRotary4,
//   &eqRotary5,  
// };

void setup() 
{
  // Serial.begin(9600);
  // Serial.write("alasd");
  midiController.begin();

  // for(int i = 0; i < sizeof(abstractHMIArray); i++){
  //   abstractHMIArray[i]->begin();
  // }

  eqRotary0.begin();
  eqRotary1.begin();
  eqRotary2.begin();
  eqRotary3.begin();
  eqRotary4.begin();
  eqRotary5.begin();  

  // pinMode(A0, INPUT);
  // pinMode(A1, INPUT);
  // pinMode(A2, INPUT);
  // pinMode(A3, INPUT);
  // pinMode(A4, INPUT);
  // pinMode(A5, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {


  // for(int i = 0; i < sizeof(abstractHMIArray); i++){
  //   abstractHMIArray[i]->read();
  // }
  eqRotary0.read();
  eqRotary1.read();
  eqRotary2.read();
  eqRotary3.read();
  eqRotary4.read();
  eqRotary5.read();  

  // int pinvalue = analogRead(A0);
  // Serial.println("AO Value");
  // Serial.println(pinvalue);

  // pinvalue = analogRead(A1);
  // Serial.println("A1 Value");
  // Serial.println(pinvalue);

  //  pinvalue = analogRead(A2);
  // Serial.println("A2 Value");
  // Serial.println(pinvalue);

  //  pinvalue = analogRead(A3);
  // Serial.println("A3 Value");
  // Serial.println(pinvalue);

  //  pinvalue = analogRead(A4);
  // Serial.println("A4 Value");
  // Serial.println(pinvalue);

  // pinvalue = analogRead(A5);
  // Serial.println("A5 Value");
  // Serial.println(pinvalue);


  delay(10);        // delay in between reads for stability
}

