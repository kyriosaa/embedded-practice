#include <Arduino.h>

#define BUTTON 2

unsigned long previousButtonChange = millis();
unsigned long debounceDelay = 50;

byte buttonState = LOW;

void setup()
{
  Serial.begin(9600);

  pinMode(BUTTON, INPUT);
}

void loop()
{
  unsigned long timeNow = millis();
  if (timeNow - previousButtonChange > debounceDelay)
  {
    byte newButtonState = digitalRead(BUTTON);
    if (newButtonState != buttonState)
    {
      previousButtonChange = timeNow;
      buttonState = newButtonState;
      if (buttonState == HIGH)
      {
        Serial.println("Button is pressed");
      }
      else
      {
        Serial.println("Button is released");
      }
    }
  }
}
