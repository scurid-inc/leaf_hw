#define MQ135_PIN 34 // Analog pin for MQ-135
float R0 = 1.0; // Replace with your R0 value obtained from calibration
float S = 0.2; // Replace with your sensitivity factor obtained from calibration

void setup() {
  Serial.begin(115200);
  pinMode(MQ135_PIN, INPUT);
}

void loop() {
  int sensorValue = analogRead(MQ135_PIN);
  float concentration = ((sensorValue / R0) - 1) / S; // Simplified formula

  Serial.println("Calibrated Concentration: " + String(concentration));
  delay(1000);
}
