#include <Arduino.h>

void setup()
{
  Serial.begin(9600);
  Serial.setTimeout(10);
}

void loop()
{
  if (Serial.available() > 0)
  {
    String var = Serial.readString();
    Serial.println(var);
  }
}
