#include <Arduino.h>

#define BLUE 6
#define YELLOW 5
#define RED 4
#define ECHO 2
#define TRIGGER 10

unsigned long lastTimeUltrasonicTrigger = millis();
unsigned long ultrasonicTriggerDelay = 100;

volatile unsigned long pulseInTimeBegin;
volatile unsigned long pulseInTimeEnd;
volatile bool newDistanceAvaliable = false;

void triggerUltrasonicSensor()
{
  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);
}

double getUltrasonicDistance()
{
  double durationMicros = pulseInTimeEnd - pulseInTimeBegin;
  double distance = durationMicros / 58.0; // 58.0 for cm, 148.0 for inches
  return distance;
}

void echoPinInterrupt()
{

  if (digitalRead(ECHO) == HIGH)
  {
    // rising = start measuring
    pulseInTimeBegin = micros();
  }
  else
  {
    // falling = stop measuring
    pulseInTimeEnd = micros();
    newDistanceAvaliable = true;
  }
}

void powerLEDsFromDistance(double distance)
{
  if (distance >= 25)
  {

    digitalWrite(BLUE, HIGH);
    digitalWrite(YELLOW, LOW);
    digitalWrite(RED, LOW);
  }
  else if (distance >= 10)
  {
    digitalWrite(BLUE, LOW);
    digitalWrite(YELLOW, HIGH);
    digitalWrite(RED, LOW);
  }
  else
  {
    digitalWrite(BLUE, LOW);
    digitalWrite(YELLOW, LOW);
    digitalWrite(RED, HIGH);
  }
}

void setup()
{
  Serial.begin(9600);
  pinMode(ECHO, INPUT);
  pinMode(TRIGGER, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(ECHO),
                  echoPinInterrupt,
                  CHANGE);
}

void loop()
{
  unsigned long timeNow = millis();

  if (timeNow - lastTimeUltrasonicTrigger > ultrasonicTriggerDelay)
  {
    lastTimeUltrasonicTrigger += ultrasonicTriggerDelay;
    triggerUltrasonicSensor(); // trigger sensor
  }

  if (newDistanceAvaliable)
  {
    newDistanceAvaliable = false;
    double distance = getUltrasonicDistance();
    powerLEDsFromDistance(distance);
    Serial.println(distance);
  }
}