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
    Serial.println("<SendControllChange>" + String(inControlNumber) + " / " + String(inControlValue) + " / " + String(inChannel)); 
}

void DebugController::sendNoteOn(byte note, byte velocity ,int inChannel)
{
    Serial.println("<SendNoteOn>" + String(note) + " / " + String(velocity) + " / " + String(inChannel)); 
}

void DebugController::sendNoteOff(byte note, byte velocity,int inChannel)
{
    Serial.println("<SendNoteOff>" + String(note) + " / " + String(velocity) + " / " + String(inChannel)); 
}