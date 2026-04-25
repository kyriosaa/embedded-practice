#include <Arduino.h>

#define RED_PIN 8
#define YELLOW_PIN 9
#define BLUE_PIN 10

#define RED_BUTTON 5
#define YELLOW_BUTTON 6
#define BLUE_BUTTON 7

void setup()
{
  Serial.begin(9600);

  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  pinMode(RED_BUTTON, INPUT);
  pinMode(YELLOW_BUTTON, INPUT);
  pinMode(BLUE_BUTTON, INPUT);
}

void handleRed()
{
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);
  Serial.println("RED");
  delay(200);
}

void handleYellow()
{
  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, HIGH);
  digitalWrite(BLUE_PIN, LOW);
  Serial.println("YELLOW");
  delay(200);
}

void handleBlue()
{
  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(BLUE_PIN, HIGH);
  Serial.println("BLUE");
  delay(200);
}

void loop()
{
  if (digitalRead(RED_BUTTON) == HIGH)
  {
    handleRed();
  }
  else if (digitalRead(YELLOW_BUTTON) == HIGH)
  {
    handleYellow();
  }
  else if (digitalRead(BLUE_BUTTON) == HIGH)
  {
    handleBlue();
  }
}
