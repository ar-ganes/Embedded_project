/*#include <Arduino.h>
#include <ESP8266WiFi.h>

// Define GPIO pins for the LEDs
const int LED1 = 14;    // GPIO14, connect the first LED here
const int LED2 = 16;    // GPIO16, connect the second LED here

// Variables to store the last time LEDs were updated
unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;

// Define the blink intervals for each LED (in milliseconds)
const long interval1 = 500;  // Blink interval for LED1 (500 ms)
const long interval2 = 300;  // Blink interval for LED2 (300 ms)

void setup() {
  // Initialize Serial Monitor for debugging
  Serial.begin(9600);
  delay(1000);  // Wait for 1 second to allow Serial Monitor to initialize
  Serial.println("Starting ESP8266...");

  // Print debug messages for verification
  Serial.println("Checking Serial Monitor...");
  Serial.println("Initialization complete.");

  // Print the MAC Address of the ESP8266
  Serial.print("MAC Address: ");
  Serial.println(WiFi.macAddress());

  // Print a confirmation message
  Serial.println("Setup Complete!");

  // Initialize the LED pins as outputs
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

  // Turn off the LEDs initially
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
}

void loop() {
  // Get the current time in milliseconds
  unsigned long currentMillis = millis();

  // Check if it's time to toggle LED1
  if (currentMillis - previousMillis1 >= interval1) {
    // Save the last time LED1 was toggled
    previousMillis1 = currentMillis;

    // Toggle LED1
    digitalWrite(LED1, !digitalRead(LED1));  // Invert the current state of LED1
  }

  // Check if it's time to toggle LED2
  if (currentMillis - previousMillis2 >= interval2) {
    // Save the last time LED2 was toggled
    previousMillis2 = currentMillis;

    // Toggle LED2
    digitalWrite(LED2, !digitalRead(LED2));  // Invert the current state of LED2
  }

  // Optional: Print status to Serial Monitor every second
  if (currentMillis % 1000 < 50) {
    Serial.println("Blinking LEDs...");
  }
}*/
