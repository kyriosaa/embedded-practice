#include <Arduino.h>

int LED_PIN = 12;

void setup() {
  // Set LED pin to output
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  Serial.println("LED on");
  delay(2000);
  digitalWrite(LED_PIN, LOW);
  Serial.println("LED off");
  delay(1000);
}