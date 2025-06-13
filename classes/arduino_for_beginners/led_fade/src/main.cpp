#include <Arduino.h>

#define LED_PIN 11

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  for (int i = 0; i <= 255; i++)
  {
    analogWrite(LED_PIN, i);
    Serial.println(i);
    delay(5);
  }

  for (int i = 255; i >= 0; i--)
  {
    analogWrite(LED_PIN, i);
    Serial.println(i);
    delay(5);
  }
}
