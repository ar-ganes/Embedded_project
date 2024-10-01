#include <Wire.h>

#define I2C_MASTER_ADDRESS 0x66  // Master address (Teensy)
#define I2C_SLAVE_ADDRESS 0x65   // Slave address (Feather NRF52)

// Declare the function before setup()
void scanI2CDevices();

void setup() {
  // Start Serial communication
  Serial.begin(9600);
  while (!Serial) { /* Wait for Serial Monitor */ }

  Serial.print("I2C Master address: 0x");
  if (I2C_MASTER_ADDRESS < 16) Serial.print("0");  // Add leading zero for single-digit addresses
  
  Serial.println(I2C_MASTER_ADDRESS, HEX);


  // Start I2C on alternate pins (SDA1 = 17, SCL1 = 16) using Wire1
  Wire1.begin();
  Wire1.setClock(100000);  // Set I2C clock speed to 100kHz

  // Step 1: Scan for I2C devices
  Serial.println("Scanning I2C devices on Teensy (Wire1 - SDA1/SCL1)...");
  scanI2CDevices();

  // Step 2: Send master's address to the detected slave
  Serial.println("Sending master address to the slave...");
  Wire1.beginTransmission(I2C_SLAVE_ADDRESS);
  Wire1.write(I2C_MASTER_ADDRESS);  // Send the master's address
  byte error = Wire1.endTransmission(false);

  // Step 3: Check if transmission was successful
  if (error == 0) {
    Serial.println("Master address sent successfully.");
  } else {
    Serial.print("Failed to send master address. Error code: ");
    Serial.println(error);
  }
}

void loop() {
  // Do nothing in the loop
  delay(1000);  // Slow down the loop for readability
}

// Define the scanI2CDevices function after loop
void scanI2CDevices() {
  byte error, address;
  int nDevices = 0;

  // Use Wire1 to scan the I2C bus on pins 17 and 16
  for (address = 1; address < 127; address++) {
    Wire1.beginTransmission(address);
    error = Wire1.endTransmission();

    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address < 16) Serial.print("0");
      Serial.println(address, HEX);
      nDevices++;
    }
  }

  if (nDevices == 0)
    Serial.println("No I2C devices found.");
  else
    Serial.println("I2C device scan complete.");
}