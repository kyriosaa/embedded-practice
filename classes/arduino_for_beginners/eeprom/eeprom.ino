#include <EEPROM.h>

void setup() {
  Serial.begin(115200);

  // EEPROM.write(0, 44);
  // EEPROM.write(200, 150);

  Serial.println(EEPROM.read(0));
  Serial.println(EEPROM.read(89));
  Serial.println(EEPROM.read(200));

}

void loop() {

}
