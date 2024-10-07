/*#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266httpUpdate.h>

// Wi-Fi credentials
const char* ssid = "Zed";
const char* password = "Wireless4U!";

// OTA server details
const char* firmware_version_url = "http://192.168.0.215/version.txt";  // Replace with your actual server address
const char* firmware_bin_url = "http://192.168.0.215/firmware.bin";     // Replace with your actual server address

// Define the current firmware version
#define CURRENT_FIRMWARE_VERSION 2

// Function prototypes
void checkForUpdates();
void performOTAUpdate();

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Connect to Wi-Fi
  Serial.print("Connecting to Wi-Fi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to Wi-Fi!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Check for OTA firmware updates
  checkForUpdates();
}

void loop() {
  // No loop actions needed for basic OTA functionality
}

void checkForUpdates() {
  Serial.println("Checking for firmware updates...");

  // Create WiFiClient object
  WiFiClient client;

  // Create HTTPClient object
  HTTPClient httpClient;

  // Use the updated begin() method with WiFiClient and URL
  httpClient.begin(client, firmware_version_url);  // Correct usage of begin()

  int httpCode = httpClient.GET();  // Make GET request

  if (httpCode == HTTP_CODE_OK) {
    String serverVersion = httpClient.getString();  // Read version number from the file
    int latestVersion = serverVersion.toInt();

    Serial.print("Current firmware version: ");
    Serial.println(CURRENT_FIRMWARE_VERSION);
    Serial.print("Available firmware version: ");
    Serial.println(latestVersion);

    // If a new version is available, initiate OTA update
    if (latestVersion > CURRENT_FIRMWARE_VERSION) {
      Serial.println("New firmware available. Starting OTA update...");
      performOTAUpdate();
    } else {
      Serial.println("Firmware is up to date.");
    }
  } else {
    Serial.print("Failed to check for updates. HTTP error: ");
    Serial.println(httpCode);
  }
  httpClient.end();
}

void performOTAUpdate() {
  // Use a WiFiClient object to pass to the update function
  WiFiClient client;

  // Use the correct update function with the WiFiClient object
  t_httpUpdate_return ret = ESPhttpUpdate.update(client, firmware_bin_url);

  switch (ret) {
    case HTTP_UPDATE_FAILED:
      Serial.printf("OTA update failed. Error (%d): %s\n", ESPhttpUpdate.getLastError(), ESPhttpUpdate.getLastErrorString().c_str());
      break;
    case HTTP_UPDATE_NO_UPDATES:
      Serial.println("No updates available.");
      break;
    case HTTP_UPDATE_OK:
      Serial.println("Update successful! Rebooting...");
      ESP.restart();
      break;
  }
}*/