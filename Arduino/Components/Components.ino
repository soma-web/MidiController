#include "Fader.h"
#include "Button.h"

Fader fader(A0);
//digital 7 pin, 35ms to deboounce, 
// is pullup see: https://easybtn.earias.me/docs/introduction
Button button(DD7);

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600); 
  fader.begin();
  button.begin();
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  fader.read();
  int sensorValue = fader.getValue();
  // print out the value you read:
  Serial.print("Fader value: ");
  Serial.println(sensorValue);
  

  
  button.read();
  Serial.print("Is button pressed: ");
  Serial.println(button.isPressed());
  Serial.print("Button state changed ");
  Serial.println(button.stateChanged());
  delay(100);        // delay in between reads for stability
}

