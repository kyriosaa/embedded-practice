#include <Arduino.h>

unsigned long previousSerialPrint = millis();
unsigned long timeInterval = 500;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  unsigned long timeNow = millis();
  if (timeNow - previousSerialPrint > timeInterval)
  {
    Serial.println("Hello");
    Serial.println(millis());
    previousSerialPrint += timeInterval;
  }
}
