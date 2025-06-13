#include <EEPROM.h>

#define LED_PIN 10
#define POTENTIOMETER_PIN A2
#define EEPROM_ADDRESS_MAX_INTENSITY 350
#define MAX_BRIGHTNESS_DEFAULT 255

byte maxBrightness;

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(10);
  pinMode(LED_PIN, OUTPUT);

  maxBrightness = EEPROM.read(EEPROM_ADDRESS_MAX_INTENSITY);
  if(maxBrightness == 0) {
    maxBrightness = MAX_BRIGHTNESS_DEFAULT;
  }

}

void loop() {
  if(Serial.available() > 0) {
    int data = Serial.parseInt();

    if(data >= 0 && data < 256) {
      EEPROM.write(EEPROM_ADDRESS_MAX_INTENSITY, data);
      maxBrightness = data;
    }
  }

  byte LED_BRIGHTNESS = analogRead(POTENTIOMETER_PIN / 4);
  if(LED_BRIGHTNESS > maxBrightness) {
    LED_BRIGHTNESS = maxBrightness;
  }
  analogWrite(LED_PIN, LED_BRIGHTNESS);

}
