#include <Arduino.h>

#define BUTTON 2

void setup()
{
  Serial.begin(9600);

  pinMode(BUTTON, INPUT);
}

void loop()
{
  digitalRead(BUTTON);
}
