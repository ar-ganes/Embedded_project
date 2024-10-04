/*#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>

// Wi-Fi credentials
const char* ssid = "Zed";
const char* password = "Wireless4U!";

// Create an instance of the web server
ESP8266WebServer server(80);

// Create a GPS object
TinyGPSPlus gps;

// Latitude and Longitude variables
double latitude = 0.0;
double longitude = 0.0;

// SoftwareSerial setup for GPIO4 and GPIO5
SoftwareSerial ss(4, 5);  // RX = GPIO4, TX = GPIO5

void handleRoot() {
  String html = "<html><head><title>ESP8266 GPS Data</title></head><body>";
  html += "<h1>ESP8266 GPS Data</h1>";
  html += "<p>Latitude: " + String(latitude, 6) + "</p>";
  html += "<p>Longitude: " + String(longitude, 6) + "</p>";
  html += "</body></html>";
  
  server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(115200);  // Serial Monitor for debugging
  delay(1000);
  Serial.println("Starting ESP8266 GPS Web Server...");

  // Initialize SoftwareSerial for GPS communication
  ss.begin(9600);  // Change to match your GPS baud rate

  // Connect to Wi-Fi
  Serial.print("Connecting to Wi-Fi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to Wi-Fi!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.begin();
  Serial.println("Web server started!");
}

void loop() {
  server.handleClient();

  if (ss.available() > 0) {
    Serial.print("Raw Data: ");
    while (ss.available() > 0) {
      char c = ss.read();
      Serial.print(c);  // Print raw GPS data to Serial Monitor

      if (gps.encode(c)) {
        if (gps.location.isValid()) {
          latitude = gps.location.lat();
          longitude = gps.location.lng();
          Serial.print("Latitude: ");
          Serial.println(latitude, 6);
          Serial.print("Longitude: ");
          Serial.println(longitude, 6);
        } else {
          Serial.println("Waiting for a valid GPS location...");
        }
      }
    }
    Serial.println();
  } else {
    Serial.println("No data from GPS module. Waiting...");
    delay(1000);
  }
}*/
