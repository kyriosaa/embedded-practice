#include <Arduino.h>
#include <EEPROM.h>

#define POTENTIOMETER A2
#define LED 10
#define EEPROM_MEMORY 350
#define MAX_BRIGHTNESS_DEFAULT 255

unsigned long previousTimeLEDBlink = millis();
byte maxBrightness = 255;

void setup()
{
  Serial.begin(9600);
  Serial.setTimeout(10);

  pinMode(LED, OUTPUT);

  maxBrightness = EEPROM.read(EEPROM_MEMORY);
  if (maxBrightness == 0)
  {
    maxBrightness = MAX_BRIGHTNESS_DEFAULT;
  }
}

void loop()
{
  // LED on pin 10 - fade in/out from potentiometer
  // max brightness from serial
  // save max brightness variable to EEPROM

  if (Serial.available() > 0)
  {
    int data = Serial.parseInt();
    if ((data >= 0) && (data < 256))
    {
      EEPROM.write(EEPROM_MEMORY, data);
      maxBrightness = data;
    }
  }

  byte LEDBrightness = analogRead(POTENTIOMETER) / 4;
  if (LEDBrightness > maxBrightness)
  {
    LEDBrightness = maxBrightness;
  }
  analogWrite(LED, LEDBrightness);
}
