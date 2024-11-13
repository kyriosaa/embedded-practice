#include <Arduino.h>

unsigned long timeBegin;

void setup()
{
  Serial.begin(9600);
  timeBegin = millis();

  // unsigned long timeBegin = micros();
  // delay(500);
  // unsigned long timeEnd = micros();
  // unsigned long duration = timeEnd - timeBegin;
  // Serial.print("The duration is:");
  // Serial.println(duration);
}

void loop()
{
  delay(1000);
  unsigned long timeNow = millis();
  unsigned long durationSinceStart = timeNow - timeBegin;
  Serial.println(durationSinceStart);
}
