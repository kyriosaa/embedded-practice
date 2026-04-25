#include <Arduino.h>

#define LED 12

int blinkDelay = 500;

int LEDState = LOW;

void setup()
{
  Serial.begin(115200);
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
  delay(blinkDelay);
}
