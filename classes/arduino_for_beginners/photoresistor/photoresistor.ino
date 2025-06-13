#define PHOTORESISTOR_PIN A0

void setup() {
  Serial.begin(115200);

}

void loop() {
  Serial.println(analogRead(PHOTORESISTOR_PIN));
  delay(100);
}
