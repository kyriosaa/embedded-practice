// receives signal and controls motor

#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "IcePick15";
const char* password = "qwertyasdf";

const int MOTOR_PIN1 = 12;  // IN1
const int MOTOR_PIN2 = 13;  // IN2
const int MOTOR_PWM = 14;   // Enable/PWM pin

// port 80
WebServer server(80);

const int motorSpeed = 200;  // 0-255
const int motorRunTime = 3000;  

void setup() {
  Serial.begin(115200);
  pinMode(MOTOR_PIN1, OUTPUT);
  pinMode(MOTOR_PIN2, OUTPUT);
  pinMode(MOTOR_PWM, OUTPUT);
  
  // start at off state
  digitalWrite(MOTOR_PIN1, LOW);
  digitalWrite(MOTOR_PIN2, LOW);
  analogWrite(MOTOR_PWM, 0);
  
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("\nConnected to WiFi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  Serial.println("Use this IP in ESP32A's serverIP variable");
  
  server.on("/motor", handleMotorRequest);
  
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}

void handleMotorRequest() {
  Serial.println("Motor command received!");
  digitalWrite(MOTOR_PIN1, HIGH);
  digitalWrite(MOTOR_PIN2, LOW);
  analogWrite(MOTOR_PWM, motorSpeed);
  Serial.println("Motor ON");
  
  // reply back to other unit
  server.send(200, "text/plain", "Motor activated");
  
  delay(motorRunTime);
  
  digitalWrite(MOTOR_PIN1, LOW);
  digitalWrite(MOTOR_PIN2, LOW);
  analogWrite(MOTOR_PWM, 0);
  
  Serial.println("Motor OFF");
}