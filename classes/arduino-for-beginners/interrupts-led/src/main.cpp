#include <Arduino.h>

#define BUTTON 2
#define LED 12

volatile unsigned long lastTimeButtonReleased = millis();
unsigned long debounceDelay = 50;

byte LEDState = LOW;
volatile bool buttonReleased = false;

void toggleLED()
{
  if (LEDState == LOW)
  {
    LEDState = HIGH;
  }
  else
  {
    LEDState = LOW;
  }
  digitalWrite(LED, LEDState);
}

void buttonReleaseInterrupt()
{
  unsigned long timeNow = millis();
  if (timeNow - lastTimeButtonReleased > debounceDelay)
  {
    lastTimeButtonReleased = timeNow;
    buttonReleased = true;
  }
}

void setup()
{
  pinMode(BUTTON, INPUT);
  pinMode(LED, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(BUTTON), buttonReleaseInterrupt, FALLING);
}

void loop()
{
  if (buttonReleased)
  {
    buttonReleased = false;
    toggleLED();
  }
}
