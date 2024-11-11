#include <Arduino.h>

#define LED1 12
#define LED2 11
#define LED3 10

unsigned long previousTimeLED1Blink = millis();
unsigned long timeIntervalLED1Blink = 600;

unsigned long previousTimeLED2Blink = millis();
unsigned long timeIntervalLED2Blink = 1200;

unsigned long previousTimeLED3Blink = millis();
unsigned long timeIntervalLED3Blink = 1800;

int LED1State = LOW;
int LED2State = LOW;
int LED3State = LOW;

void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop()
{
  // toggle LED1
  unsigned long timeNow = millis();
  if (timeNow - previousTimeLED1Blink > timeIntervalLED1Blink)
  {
    if (LED1State == LOW)
    {
      LED1State = HIGH;
    }
    else
    {
      LED1State = LOW;
    }
    digitalWrite(LED1, LED1State);
    previousTimeLED1Blink += timeIntervalLED1Blink;
  }

  // toggle LED2
  if (timeNow - previousTimeLED2Blink > timeIntervalLED2Blink)
  {
    if (LED2State == LOW)
    {
      LED2State = HIGH;
    }
    else
    {
      LED2State = LOW;
    }
    digitalWrite(LED2, LED2State);
    previousTimeLED2Blink += timeIntervalLED2Blink;
  }

  // toggle LED3
  if (timeNow - previousTimeLED3Blink > timeIntervalLED3Blink)
  {
    if (LED3State == LOW)
    {
      LED3State = HIGH;
    }
    else
    {
      LED3State = LOW;
    }
    digitalWrite(LED3, LED3State);
    previousTimeLED3Blink += timeIntervalLED3Blink;
  }
}
