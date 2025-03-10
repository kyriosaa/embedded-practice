#include <IRremote.h>

#define IR__RECEIVE_PIN 5

#define IR_BUTTON_0 25
#define IR_BUTTON_1 69
#define IR_BUTTON_2 70
#define IR_BUTTON_3 71
#define IR_BUTTON_4 68
#define IR_BUTTON_5 64
#define IR_BUTTON_6 67
#define IR_BUTTON_7 7
#define IR_BUTTON_8 21
#define IR_BUTTON_9 9

#define IR_BUTTON_STAR  22
#define IR_BUTTON_HASH  13
#define IR_BUTTON_OK    28
#define IR_BUTTON_UP    24
#define IR_BUTTON_DOWN  82
#define IR_BUTTON_LEFT  8
#define IR_BUTTON_RIGHT 90

void setup() {
  Serial.begin(115200);
  IrReceiver.begin(IR__RECEIVE_PIN);
}

void loop() {
  if(IrReceiver.decode()) {
    IrReceiver.resume();

    int command = IrReceiver.decodedIRData.command;

    switch(command) {
      case IR_BUTTON_0:
        Serial.println("Button 0");
        break;
      case IR_BUTTON_1:
        Serial.println("Button 1");
        break;
      case IR_BUTTON_2:
        Serial.println("Button 2");
        break;
      case IR_BUTTON_3:
        Serial.println("Button 3");
        break;
      case IR_BUTTON_4:
        Serial.println("Button 4");
        break;
      case IR_BUTTON_5:
        Serial.println("Button 5");
        break;
      case IR_BUTTON_6:
        Serial.println("Button 6");
        break;
      case IR_BUTTON_7:
        Serial.println("Button 7");
        break;
      case IR_BUTTON_8:
        Serial.println("Button 8");
        break;
      case IR_BUTTON_9:
        Serial.println("Button 9");
        break;
      default:
        Serial.println("Please press a number button!");
        break;
    }
 
    // // not optimal and ugly
    // if(command == IR_BUTTON_0) {
    //   Serial.println("Button 0 was pressed!");
    // } else if(command == IR_BUTTON_1) {
    //   Serial.println("Button 1 was pressed!");
    // } else if(command == IR_BUTTON_2) {
    //   Serial.println("Button 2 was pressed!");
    // } else {
    //   Serial.println("Please press a number button!");
    // }

    // Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    // Serial.println(IrReceiver.decodedIRData.command);
    // Serial.println("---");
  }
}
