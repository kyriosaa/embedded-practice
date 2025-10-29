// Sends signal thru WiFi when button is pressed

#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "IcePick15";
const char* password = "qwertyasdf";

// other ESP32's IP addr
const char* serverIP = "http://172.20.10.3/motor";

// config
const int BUTTON_PIN = 4;
bool lastButtonState = HIGH;
bool currentButtonState = HIGH;

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("\nConnected to WiFi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  currentButtonState = digitalRead(BUTTON_PIN);
  
  if (lastButtonState == HIGH && currentButtonState == LOW) {
    Serial.println("Button pressed! Sending signal...");
    sendMotorCommand();
    delay(200); // debounce
  }
  
  lastButtonState = currentButtonState;
  delay(50);
}

void sendMotorCommand() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(serverIP);
    
    int httpResponseCode = http.GET();
    
    if (httpResponseCode > 0) {
      Serial.print("Signal sent successfully. Response code: ");
      Serial.println(httpResponseCode);
    } else {
      Serial.print("Error sending signal: ");
      Serial.println(httpResponseCode);
    }
    
    http.end();
  } else {
    Serial.println("WiFi not connected!");
  }
}