#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_TinyUSB.h>  // Required for Feather NRF52 to use USB Serial

#define I2C_SLAVE_ADDRESS 0x65  // Feather NRF52 I2C Address (101 in decimal)

void receiveEvent(int numBytes) {
  if (Serial) {
    Serial.println("Data received from master.");
    if (numBytes > 0) {
      byte masterAddress = Wire.read();  // Read and print master's address
      Serial.print("Master I2C address received: 0x");
      Serial.println(masterAddress, HEX);
    }
  }
}

void setup() {
  // Start USB Serial communication for Feather NRF52
  Serial.begin(115200);
  while (!Serial) {
    delay(10);  // Wait for Serial to connect
  }

  // Join the I2C bus as a slave device
  Wire.begin(I2C_SLAVE_ADDRESS);

  // Set up event handlers for I2C communication
  Wire.onReceive(receiveEvent);  // Register handler for receiving data

  Serial.println("Feather NRF52 I2C slave initialized.");
}

void loop() {
  delay(1000);  // Slow down the loop
}