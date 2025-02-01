#include <Arduino.h>

const int sensorPin = 2;
const int ledPin = 13;
int previousState = LOW;
int currentState = LOW;


void setup(){
  pinMode(sensorPin,INPUT);
  pinMode(ledPin,OUTPUT);
  Serial.begin(115200);
}

void loop(){
  previousState = currentState;
  currentState = digitalRead(sensorPin);

  if (previousState == HIGH and currentState == LOW){
    Serial.println("Sound detected");
    digitalWrite(ledPin,HIGH);
    delay(500);
    digitalWrite(ledPin,LOW);
  }
}