#include <Arduino.h>

#define BUTTON_PIN 2
#define LED_PIN 11

void setup()
{
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  if (digitalRead(BUTTON_PIN) == HIGH)
  {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Button is pressed");
  }
  else
  {
    digitalWrite(LED_PIN, LOW);
    Serial.println("Button is not pressed");
  }
  delay(100);
}