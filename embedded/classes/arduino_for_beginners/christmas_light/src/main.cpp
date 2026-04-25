#include <Arduino.h>

#define RED 12
#define YELLOW 11
#define BLUE 10
#define BUTTON 2

#define LED_PIN_ARRAY_SIZE 3

int LEDBlinkState = 1;

byte LEDPinArray[LED_PIN_ARRAY_SIZE] = {RED, YELLOW, BLUE};

void setLEDPinModes()
{
  for (int i = 0; i < LED_PIN_ARRAY_SIZE; i++)
  {
    pinMode(LEDPinArray[i], OUTPUT);
  }
}

void turnOffAllLEDs()
{
  for (int i = 0; i < LED_PIN_ARRAY_SIZE; i++)
  {
    digitalWrite(LEDPinArray[i], LOW);
  }
}

void toggleLEDs()
{
  if (LEDBlinkState == 1)
  {
    digitalWrite(RED, HIGH);
    digitalWrite(YELLOW, LOW);
    digitalWrite(BLUE, HIGH);
    LEDBlinkState = 2;
  }
  else
  {
    digitalWrite(RED, LOW);
    digitalWrite(YELLOW, HIGH);
    digitalWrite(BLUE, LOW);
    LEDBlinkState = 1;
  }
}

void setup()
{
  pinMode(BUTTON, INPUT);
  setLEDPinModes();
  turnOffAllLEDs();
}

void loop()
{
  if (digitalRead(BUTTON) == LOW)
  {
    toggleLEDs();
    delay(300);
  }
}