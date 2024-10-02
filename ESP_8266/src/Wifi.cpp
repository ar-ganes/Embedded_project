/*#include <Arduino.h>
#include <ESP8266WiFi.h>

// WiFi credentials
const char* ssid = "Zed";           // Replace with your WiFi SSID
const char* password = "Wireless4U!";  // Replace with your WiFi Password

// Define GPIO pin for the LED
const int LED_PIN = 14;   // Change this to your desired GPIO pin (e.g., GPIO14 or GPIO16)

// Timing variables for LED blinking
unsigned long previousMillis = 0;

// LED blink intervals based on signal strength
const long strongInterval = 0;      // Steady ON (no interval)
const long mediumInterval = 500;    // Blink every 500 ms for medium signal
const long weakInterval = 1500;     // Blink every 1500 ms for weak signal

void setup() {
  // Initialize Serial Monitor for debugging
  Serial.begin(9600);
  delay(1000);  // Wait for 1 second to allow Serial Monitor to initialize

  // Initialize LED pin as an output
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);  // Turn off the LED initially

  // Connect to WiFi
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);

  // Wait until connected
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("\nWiFi connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Get the current WiFi signal strength (RSSI)
  long rssi = WiFi.RSSI();
  Serial.print("Current RSSI: ");
  Serial.print(rssi);  // Print the RSSI value
  Serial.print(" dBm, Signal Strength: ");

  // Determine the LED behavior and print signal strength category
  long interval;  // Set the blink interval based on signal strength

  if (rssi >= -50) {
    // Strong signal: Turn on the LED steadily
    interval = strongInterval;
    Serial.println("Strong");
  } else if (rssi >= -70) {
    // Medium signal: Blink twice per second (500 ms)
    interval = mediumInterval;
    Serial.println("Medium");
  } else {
    // Weak signal: Blink twice every three seconds (1500 ms)
    interval = weakInterval;
    Serial.println("Weak");
  }

  // Control the LED based on the interval
  unsigned long currentMillis = millis();

  if (interval == 0) {
    // Steady ON for strong signal
    digitalWrite(LED_PIN, HIGH);
  } else {
    // Blink for medium and weak signals
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      digitalWrite(LED_PIN, !digitalRead(LED_PIN));  // Toggle LED state
    }
  }

  // Wait for a short period before the next signal strength check
  delay(1000);
}*/
