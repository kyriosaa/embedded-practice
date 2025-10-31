#include <WiFi.h>
#include <esp_wpa2.h>
#include <WebServer.h>
#include <ArduinoJson.h>
#include <SPIFFS.h>

// creds are loaded from SPIFFS
String ssid = "";
String username = "";
String password = "";
String identity = "";

// SPIFFS read
String API_KEY;

const int MOTOR_PIN1 = 12;
const int MOTOR_PIN2 = 13;
const int MOTOR_PWM = 14;

// port 80
WebServer server(80);

void handlePostData();
void handleOptions();

void setup() {
  Serial.begin(115200);

  // init SPIFFS
  if (!SPIFFS.begin(true)) {
    Serial.println("SPIFFS mount failed.");
    return;  
  }
  Serial.println("SPIFFS mounted successfully.");

    // Load WiFi config from JSON file
  File configFile = SPIFFS.open("/wifi_config.json", "r");
  if (!configFile) {
    Serial.println("Failed to open /wifi_config.json.");
    return;
  }
  StaticJsonDocument<200> configDoc;
  DeserializationError configError = deserializeJson(configDoc, configFile);
  configFile.close();
  if (configError) {
    Serial.println("Failed to parse /wifi_config.json.");
    return;
  }
  ssid = configDoc["ssid"] | "";
  username = configDoc["username"] | "";
  password = configDoc["password"] | "";
  identity = configDoc["identity"] | "";
  Serial.println("WiFi config loaded from SPIFFS.");
  
  // load API key
  File keyFile = SPIFFS.open("/api_key.txt", "r");
  if (!keyFile) {
    Serial.println("Failed to open /api_key.txt");
    return; 
  }
  API_KEY = keyFile.readString();
  keyFile.close(); 
  API_KEY.trim();
  Serial.println("API key loaded from SPIFFS.");
  
  pinMode(MOTOR_PIN1, OUTPUT);
  pinMode(MOTOR_PIN2, OUTPUT);
  pinMode(MOTOR_PWM, OUTPUT);
  digitalWrite(MOTOR_PIN1, LOW);
  digitalWrite(MOTOR_PIN2, LOW);
  analogWrite(MOTOR_PWM, 0);
  
  // WiFi conn
  WiFi.disconnect(true);
  WiFi.mode(WIFI_STA);
  
  // enterprise wifi authentication (PEAP)
  esp_wifi_sta_wpa2_ent_set_identity((uint8_t *)identity.c_str(), identity.length());
  esp_wifi_sta_wpa2_ent_set_username((uint8_t *)username.c_str(), username.length());
  esp_wifi_sta_wpa2_ent_set_password((uint8_t *)password.c_str(), password.length());
  esp_wifi_sta_wpa2_ent_enable();
  
  WiFi.begin(ssid.c_str());
  Serial.print("Connecting to Enterprise WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("\nConnected to WiFi");
  Serial.print("Local IP: ");
  Serial.println(WiFi.localIP());
  Serial.println("Access via: http://140.124.249.112:80/api/data"); // UPDATE IF NETWORK CHANGE

  // register handlers
  server.on("/api/data", HTTP_POST, handlePostData);
  server.on("/api/data", HTTP_OPTIONS, handleOptions);
  
  server.enableCORS(true);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();  // ESP32 standby until receives request
}

void handlePostData() {
  // verify API key
  if (!server.hasHeader("Authorization")) {
    server.send(401, "application/json", "{\"error\":\"Missing API key\"}");
    return;
  }
  String authHeader = server.header("Authorization");
  if (authHeader != String("Bearer ") + API_KEY) {
    server.send(403, "application/json", "{\"error\":\"Invalid API key\"}");
    return;
  }

  String body = server.arg("plain");
  Serial.println("Received POST data:");
  Serial.println(body);

  StaticJsonDocument<200> doc;
  DeserializationError error = deserializeJson(doc, body);
  if (error) {
    server.send(400, "application/json", "{\"error\":\"Invalid JSON\"}");
    return;
  }

  const char* command = doc["command"];
  int speed = doc["speed"] | 0;

  // command exec
  if (strcmp(command, "motor_on") == 0) {
    digitalWrite(MOTOR_PIN1, HIGH);
    digitalWrite(MOTOR_PIN2, LOW);
    analogWrite(MOTOR_PWM, constrain(speed, 0, 255));
    Serial.printf("Motor ON at speed %d\n", speed);
  } else if (strcmp(command, "motor_off") == 0) {
    digitalWrite(MOTOR_PIN1, LOW);
    digitalWrite(MOTOR_PIN2, LOW);
    analogWrite(MOTOR_PWM, 0);
    Serial.println("Motor OFF");
  } else {
    server.send(400, "application/json", "{\"error\":\"Unknown command\"}");
    return;
  }

  server.send(200, "application/json", "{\"status\":\"success\",\"message\":\"Command executed\"}");
}

void handleOptions() {
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.sendHeader("Access-Control-Allow-Methods", "POST, GET, OPTIONS");
  server.sendHeader("Access-Control-Allow-Headers", "Content-Type, Authorization");
  server.send(204);
}