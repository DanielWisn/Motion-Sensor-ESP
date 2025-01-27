#include <Arduino.h>
#include <NewPing.h>

const int trigPin = 4; 
const int echoPin = 2;
const int ledPin = 12;
const int maxDistance = 400;

long distance;

NewPing sonar(trigPin, echoPin, maxDistance);

void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);  
  pinMode(ledPin, OUTPUT);
}

void loop() {
  delay(600);
  distance = sonar.ping_cm();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if(distance < 40){
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
  }
}