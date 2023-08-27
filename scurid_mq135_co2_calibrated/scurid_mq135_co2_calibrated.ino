#define MQ135_PIN 34 // Connect A0 of MQ-135 to GPIO 34

void setup() {
  Serial.begin(115200); // Initialize Serial monitor with 115200 baud rate
  pinMode(MQ135_PIN, INPUT); // Initialize the MQ135_PIN as an input
}

void loop() {
  int sensorValue = analogRead(MQ135_PIN); // Read the value from sensor
  
  if(sensorValue == 0) {
    Serial.println("Sensor not connected or not functioning!");
  } else {
    Serial.println("Sensor Value: " + String(sensorValue)); // Print the sensor value
    
    // Convert the sensor value to concentration (this is a simplified calculation)
    // Note: For more accurate results, you should calibrate the sensor and possibly use additional hardware
    float concentration = (sensorValue / 4096.0) * 100.0;
    Serial.println("Concentration: " + String(concentration) + "%");
  }
  
  delay(1000); // Delay for 1 second
}
