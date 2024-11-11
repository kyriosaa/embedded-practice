#include <Arduino.h>

#define POTENTIOMETER A2
#define BUTTON 2

#define LED1 12
#define LED2 11
#define LED3 10

unsigned long previousTimeLED1Blink = millis();
unsigned long blinkDelay = 500;

int LED1State = LOW;

void setup()
{
  Serial.begin(9600);
  Serial.setTimeout(10);

  pinMode(POTENTIOMETER, INPUT);
  pinMode(BUTTON, INPUT);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop()
{
  // set LED1 blink rate to serial monitor input
  if (Serial.available() > 0)
  {
    int data = Serial.parseInt();
    if ((data >= 100) && (data <= 1000))
    {
      blinkDelay = data;
    }
  }
  unsigned long timeNow = millis();
  if (timeNow - previousTimeLED1Blink > blinkDelay)
  {
    // sets LEDState to HIGH after the initial function
    if (LED1State == LOW)
    {
      LED1State = HIGH;
    }
    else
    {
      LED1State = LOW;
    }
    digitalWrite(LED1, LED1State);
    previousTimeLED1Blink += blinkDelay;
  }

  // set LED2 brightness from potentiometer
  int potentiometerValue = analogRead(POTENTIOMETER);
  int LED2Brightness = potentiometerValue / 4;

  analogWrite(LED2, LED2Brightness);

  // power on LED3 when button is pressed
  if (digitalRead(BUTTON) == LOW)
  {
    digitalWrite(LED3, HIGH);
  }
  else
  {
    digitalWrite(LED3, LOW);
  }
}
