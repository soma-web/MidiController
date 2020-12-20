#include "Fader.h"
#include "Button.h"

// 0 Analog pin
Fader fader(A0);

//digital 7 pin
Button button(DD7);

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600); 
  fader.begin();
  button.begin();
}

// the loop routine runs over and over again forever:
void loop() {
  fader.read();
  Serial.println(fader.toString());

  
  button.read();
  Serial.println(button.toString());
  delay(100);        // delay in between reads for stability
}

