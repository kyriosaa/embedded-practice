#include <EEPROM.h>

#define LED_RED 10
#define LED_YELLOW 9
#define LED_BLUE 8

#define BUTTON_RED 7
#define BUTTON_YELLOW 6
#define BUTTON_BLUE 5

#define EEPROM_ADDRESS_LED_SWITCH 200

#define LED_RED_STATE 1
#define LED_YELLOW_STATE 2
#define LED_BLUE_STATE 3

byte ledState;

// func declarations
void handleRed();
void handleYellow();
void handleBlue();

void setup() {
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(BUTTON_RED, INPUT);
  pinMode(BUTTON_YELLOW, INPUT);
  pinMode(BUTTON_BLUE, INPUT);

  ledState = EEPROM.read(EEPROM_ADDRESS_LED_SWITCH);
  switch(ledState) {
    case 1:
      digitalWrite(LED_RED, HIGH);
      break;
    case 2:
      digitalWrite(LED_YELLOW, HIGH);
      break;
    case 3:
      digitalWrite(LED_BLUE, HIGH);
      break;
  }

}

void loop() {
  if(digitalRead(BUTTON_RED) == HIGH) {
    handleRed();
  } 
  else if(digitalRead(BUTTON_YELLOW) == HIGH) {
    handleYellow();
  } 
  else if(digitalRead(BUTTON_BLUE) == HIGH) {
    handleBlue();
  }
}

void handleRed() {
  int data = LED_RED_STATE;
  EEPROM.write(EEPROM_ADDRESS_LED_SWITCH, data);
  digitalWrite(LED_RED, HIGH);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_BLUE, LOW);
}

void handleYellow() {
  int data = LED_YELLOW_STATE;
  EEPROM.write(EEPROM_ADDRESS_LED_SWITCH, data);
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_YELLOW, HIGH);
  digitalWrite(LED_BLUE, LOW);
}

void handleBlue() {
  int data = LED_BLUE_STATE;
  EEPROM.write(EEPROM_ADDRESS_LED_SWITCH, data);
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_BLUE, HIGH);
}
