#include <IRremote.h>
#include <LiquidCrystal_I2C.h>

#define LED_RED 12
#define LED_YELLOW 11
#define LED_BLUE 10

#define IR_RECEIVE_PIN 5
#define IR_BUTTON_0 25
#define IR_BUTTON_1 69
#define IR_BUTTON_2 70
#define IR_BUTTON_3 71

#define LCD_ADDRESS 0x27
LiquidCrystal_I2C lcd(LCD_ADDRESS, 16, 2);

// --- func declarations ---
void printCommand(int command);
// -------------------------

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();

  lcd.setCursor(0, 0);
  IrReceiver.begin(IR_RECEIVE_PIN);

  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
}

void loop() {
  if(IrReceiver.decode()) {
    IrReceiver.resume();

    int command = IrReceiver.decodedIRData.command;
    
    switch(command) {
      case IR_BUTTON_0:
        printCommand(command);
        lcd.print("Turn off all LEDs");
        digitalWrite(LED_RED, LOW);
        digitalWrite(LED_YELLOW, LOW);
        digitalWrite(LED_BLUE, LOW);
        break;
      case IR_BUTTON_1:
        printCommand(command);
        lcd.print("Toggle LED Red");
        digitalWrite(LED_RED, HIGH);
        digitalWrite(LED_YELLOW, LOW);
        digitalWrite(LED_BLUE, LOW);
        break;
      case IR_BUTTON_2:
        printCommand(command);
        lcd.print("Toggle LED Yellow");
        digitalWrite(LED_RED, LOW);
        digitalWrite(LED_YELLOW, HIGH);
        digitalWrite(LED_BLUE, LOW);
        break;
      case IR_BUTTON_3:
        printCommand(command);
        lcd.print("Toggle LED Blue");
        digitalWrite(LED_RED, LOW);
        digitalWrite(LED_YELLOW, LOW);
        digitalWrite(LED_BLUE, HIGH);
        break;
      default:
        printCommand(command);
        lcd.print("Invalid Input");
    }
  }
}

void printCommand(int command) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(command);
  lcd.setCursor(0, 1);
}
