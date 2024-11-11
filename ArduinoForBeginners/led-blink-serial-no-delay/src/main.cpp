#include <Arduino.h>

#define LED 12

unsigned long previousTimeLEDBlink = millis();
unsigned long blinkDelay = 500;

int LEDState = LOW;

void setup()
{
  Serial.begin(9600);
  Serial.setTimeout(10);

  pinMode(LED, OUTPUT);
}

void loop()
{
  if (Serial.available() > 0)
  {
    int data = Serial.parseInt();
    if ((data >= 100) && (data <= 1000))
    {
      blinkDelay = data;
    }
  }

  unsigned long timeNow = millis();
  if (timeNow - previousTimeLEDBlink > blinkDelay)
  {
    // sets LEDState to HIGH after the initial function
    if (LEDState == LOW)
    {
      LEDState = HIGH;
    }
    else
    {
      LEDState = LOW;
    }
    digitalWrite(LED, LEDState);
    previousTimeLEDBlink += blinkDelay;
  }
}
