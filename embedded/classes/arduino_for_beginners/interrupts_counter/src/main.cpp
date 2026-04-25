#include <Arduino.h>

#define BUTTON 2

volatile unsigned long lastTimeButtonPressed = millis();
unsigned long debounceDelay = 50;

volatile bool buttonPressed = false;

int counter = 0;

void buttonPressedInterrupt()
{
    unsigned long timeNow = millis();
    if (timeNow - lastTimeButtonPressed > debounceDelay)
    {
        lastTimeButtonPressed = timeNow;
        buttonPressed = true;
    }
}

void setup()
{
    Serial.begin(9600);
    pinMode(BUTTON, INPUT);
    attachInterrupt(digitalPinToInterrupt(BUTTON),
                    buttonPressedInterrupt,
                    RISING);
}

void loop()
{
    if (buttonPressed)
    {
        buttonPressed = false;
        counter++;
        Serial.print("Counter is: ");
        Serial.println(counter);
    }
}
