#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define LCD_ADDRESS 0x27

LiquidCrystal_I2C lcd(LCD_ADDRESS, 16, 2);

int lineState = 1;

// func declaration
void lcdPrint();

void setup() {
  Serial.begin(115200);

  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop() {
  if(Serial.available() > 0) {
    String serialString = Serial.readString();

    if(serialString.length() <= 16) {
      lcdPrint(serialString);
    }
  }
}

void lcdPrint(String serialString) {
  // remove previous text by adding space
  for(int i = serialString.length(); i < 17; i++) {
    serialString = serialString + " ";
  }
  lcd.print(serialString);

  if(lineState == 1) {
    lcd.setCursor(0, 1);
    lineState = 0;
  } else {
    lcd.setCursor(0, 0);
    lineState = 1;
  }
}
