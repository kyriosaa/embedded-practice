#include <Arduino.h>

#define ECHO 11
#define TRIGGER 10

unsigned long lastTimeUltrasonicTrigger = millis();
unsigned long ultrasonicTriggerDelay = 100;

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
    unsigned long timeBegin = millis();
    double durationMicros = pulseIn(ECHO, HIGH);
    unsigned long timeEnd = millis();
    unsigned long codeDuration = timeEnd - timeBegin;
    Serial.print("Duration");
    Serial.println(codeDuration);
    double distance = durationMicros / 58.0; // 58.0 for cm, 148.0 for inches
    return distance;
}

void setup()
{
    Serial.begin(9600);
    pinMode(ECHO, INPUT);
    pinMode(TRIGGER, OUTPUT);
}

void loop()
{
    unsigned long timeNow = millis();
    if (timeNow - lastTimeUltrasonicTrigger > ultrasonicTriggerDelay)
    {
        lastTimeUltrasonicTrigger += ultrasonicTriggerDelay;
        triggerUltrasonicSensor();               // trigger sensor
        Serial.println(getUltrasonicDistance()); // read pulse on echo pin
    }
}
