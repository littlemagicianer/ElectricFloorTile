#include <SPI.h>

// Definitions
#define SENSOR_PIN 36   // VP Pin
#define CS_PIN     5    // Chip Select for FRAM

void setup() {
  Serial.begin(115200); // Higher speed is better for ESP32

  // Set up pins
  pinMode(CS_PIN, OUTPUT);
  digitalWrite(CS_PIN, HIGH);

  // Initialize SPI
  SPI.begin(); 

  // ESP32 ADC can be a bit jumpy; this ensures 12-bit (0-4095)
  analogReadResolution(12);

  Serial.println("System Ready. Logging VP to FRAM...");
}

void loop() {
  // 1. Read the analog value from VP
  int val = (analogRead(SENSOR_PIN));
  double volt = val*3.3/4096;
  // 2. Log to Serial Monitor so we can see it
  Serial.print("Sensor Value: ");
  Serial.println(volt);

  // 3. Write to FRAM (Simplified for this tutorial)
  // Note: We use 0x06 (WREN) and 0x02 (WRITE) commands for FM25W256
  digitalWrite(CS_PIN, LOW);
  SPI.transfer(0x06); // Write Enable
  digitalWrite(CS_PIN, HIGH);

  digitalWrite(CS_PIN, LOW);
  SPI.transfer(0x02); // Write Command
  SPI.transfer(0x00); // Address High
  SPI.transfer(0x00); // Address Low (Writing to the very beginning)
  SPI.transfer(val >> 8);   // High byte
  SPI.transfer(val & 0xFF); // Low byte
  digitalWrite(CS_PIN, HIGH);

  delay(1500); // Wait 1 seconds between logs
}