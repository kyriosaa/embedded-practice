#include <Arduino.h>

#define POTENTIOMETER_PIN A2
#define LED_PIN 11

void setup()
{
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  // analogRead -> 0...1023
  // analogWrite -> 0...255

  int potentiometerValue = analogRead(POTENTIOMETER_PIN);
  int LEDBrightness = potentiometerValue / 4;

  analogWrite(LED_PIN, LEDBrightness);

  Serial.println(analogRead(POTENTIOMETER_PIN));
}