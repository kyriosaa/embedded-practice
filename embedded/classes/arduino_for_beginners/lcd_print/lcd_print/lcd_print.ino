// #include <LiquidCrystal.h>

// for lcd screens that dont have I2C
// #define LCD_E_PIN A4
// #define LCD_RS_PIN A5
// #define LCD_D4_PIN 6
// #define LCD_D5_PIN 7
// #define LCD_D6_PIN 8
// #define LCD_D7_PIN 9

// -----------------------------------------------------------------

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define LCD_ADDRESS 0x27

LiquidCrystal_I2C lcd(LCD_ADDRESS, 16, 2);

int counter = 0;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Counter: ");

}

void loop() {
  lcd.setCursor(8, 0);
  lcd.print(counter);
  counter++;
  delay(500);

}
