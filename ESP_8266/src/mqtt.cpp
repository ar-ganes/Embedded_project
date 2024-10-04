/*#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// Wi-Fi credentials
const char* ssid = "Zed";               // Your Wi-Fi SSID
const char* password = "Wireless4U!";   // Your Wi-Fi Password

// MQTT Broker details
const char* mqtt_server = "broker.hivemq.com";   // HiveMQ Public Broker
const int mqtt_port = 1883;                      // MQTT port
const char* mqtt_topic = "esp8266/gps";          // Topic to publish GPS data

// Create a WiFi client object
WiFiClient espClient;

// Create an MQTT client object
PubSubClient client(espClient);

// Dummy GPS coordinates
double latitude = 37.7749;   // Static latitude value
double longitude = -122.4194; // Static longitude value

// Function to connect to Wi-Fi
void setup_wifi() {
  Serial.print("Connecting to Wi-Fi: ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

// Function to connect to the MQTT broker
void reconnect() {
  // Loop until connected to MQTT broker
  while (!client.connected()) {
    Serial.print("Connecting to MQTT broker...");
    // Create a unique client ID for MQTT connection
    String clientId = "ESP8266Client-" + String(random(0xffff), HEX);
    if (client.connect(clientId.c_str())) {
      Serial.println("Connected to MQTT!");
    } else {
      Serial.print("Failed, rc=");
      Serial.print(client.state());
      Serial.println(" Trying again in 5 seconds...");
      delay(5000);
    }
  }
}

void setup() {
  // Initialize Serial Monitor for debugging
  Serial.begin(115200);
  
  // Connect to Wi-Fi
  setup_wifi();

  // Set up MQTT server
  client.setServer(mqtt_server, mqtt_port);
}

void loop() {
  // Reconnect to MQTT broker if disconnected
  if (!client.connected()) {
    reconnect();
  }
  client.loop();  // Maintain MQTT connection

  // Create a JSON string with dummy GPS data
  String payload = "{\"latitude\": " + String(latitude, 6) + ", \"longitude\": " + String(longitude, 6) + "}";
  
  // Publish GPS data to the MQTT topic
  Serial.print("Publishing GPS data: ");
  Serial.println(payload);
  if (client.publish(mqtt_topic, payload.c_str())) {
    Serial.println("GPS data sent successfully!");
  } else {
    Serial.println("Failed to send GPS data.");
  }

  // Update dummy values (optional, for demonstration)
  latitude += 0.0001;  // Increment latitude slightly
  longitude -= 0.0001; // Decrement longitude slightly

  delay(5000);  // Send every 5 seconds
}*/
