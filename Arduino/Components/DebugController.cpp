#include "Arduino.h"
#include "DebugController.h"


DebugController::DebugController(){
    
}

void DebugController::begin()
{
    Serial.begin(9600);
}

void DebugController::sendControllChange(byte inControlNumber, byte inControlValue,int inChannel)
{
    Serial.println("<SendControllChange> ControllNumber: " + String(inControlNumber) + " ControlValue: " + String(inControlValue) + " Channel: " + String(inChannel)); 
}

void DebugController::sendNoteOn(byte note, byte velocity ,int inChannel)
{
    Serial.println("<SendNoteOn> Note: " + String(note) + " Velocity: " + String(velocity) + " Channel: " + String(inChannel)); 
}

void DebugController::sendNoteOff(byte note, byte velocity,int inChannel)
{
    Serial.println("<SendNoteOff> Note: " + String(note) + " Velocity: " + String(velocity) + " Channel: " + String(inChannel)); 
}