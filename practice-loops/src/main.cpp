#include <Arduino.h>

void setup() {
  Serial.begin(9600);

  // For loop has 3 parameters
  // (int i = 0) means that the variable i starts at 0
  // (i < 10) means that as long as i is less than 10, this function will run
  // (i++) is the same as (i + 1), where 1 will be added to i after the function runs once

  // for loops are great if we know exactly how many times we want the function to run
  // ex: Making a screen print a message 100 times
  for (int i = 0; i < 10; i++) {
    Serial.println("Hello for");
  }

  // while loops are great if we dont know exactly when the function should stop running
  // ex: Making a screen print a message until a certain threshold is met in another variable (such as humidity value)
  int i = 0;
  while (i < 10) {
    Serial.println("Hello while");
    i++;
  }
}

void loop() {
  
}
