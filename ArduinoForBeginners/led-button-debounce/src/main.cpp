#include <Arduino.h>

#define BUTTON 2
#define BLUE 10
#define YELLOW 11
#define RED 12

unsigned long previousBlink = millis();
unsigned long blinkDelay = 1000;
byte blinkState = LOW;

unsigned long previousButtonChange = millis();
unsigned long debounceDelay = 50;
byte buttonState = LOW;

int toggleLEDState = 1;

void setup()
{
  pinMode(BLUE, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);

  pinMode(BUTTON, INPUT);
  buttonState = digitalRead(BUTTON);
}

void blinkYELLOW()
{
  if (blinkState == HIGH)
  {
    blinkState = LOW;
  }
  else
  {
    blinkState = HIGH;
  }
  digitalWrite(YELLOW, blinkState);
}

void switchREDBLUE()
{
  if (toggleLEDState == 1)
  {
    toggleLEDState = 2;
    digitalWrite(RED, LOW);
    digitalWrite(BLUE, HIGH);
  }
  else
  {
    toggleLEDState = 1;
    digitalWrite(RED, HIGH);
    digitalWrite(BLUE, LOW);
  }
}

void loop()
{
  unsigned long timeNow = millis();
  if (timeNow - previousBlink > blinkDelay)
  {
    previousBlink += blinkDelay;
    blinkYELLOW();
  }

  if (timeNow - previousButtonChange > debounceDelay)
  {
    byte newButtonState = digitalRead(BUTTON);
    if (newButtonState != buttonState)
    {
      previousButtonChange = timeNow;
      buttonState = newButtonState;
      if (buttonState == HIGH)
      {
        switchREDBLUE();
      }
    }
  }
}
