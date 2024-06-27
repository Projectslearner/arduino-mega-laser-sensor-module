/*
    Project name : Ardiuno Mega Laser Distance Sensor
    Modified Date: 27-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/arduino-mega-laser-sensor-module
*/

#include <Wire.h>
#include <Adafruit_VL53L0X.h>

// Initialize the sensor
Adafruit_VL53L0X lox = Adafruit_VL53L0X();

void setup() {
  // Initialize serial communication
  Serial.begin(115200);
  
  // Initialize I2C communication
  Wire.begin();

  // Initialize the VL53L0X sensor
  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while (1);
  }

  Serial.println(F("VL53L0X Sensor Initialized"));
}

void loop() {
  // Declare a variable to hold measurement data
  VL53L0X_RangingMeasurementData_t measure;

  // Perform a ranging test
  lox.rangingTest(&measure, false);

  // Check if the measurement is valid
  if (measure.RangeStatus != 4) {
    // Print the distance in millimeters
    Serial.print("Distance (mm): ");
    Serial.println(measure.RangeMilliMeter);
  } else {
    // Print an out of range message
    Serial.println("Out of range");
  }

  // Delay for 1 second
  delay(1000);
}
