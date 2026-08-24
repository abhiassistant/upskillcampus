// Industrial IoT Telemetry & Threshold Filtering Node
// Microcontroller: ESP32 / Arduino Framework
#include <Arduino.h>

const int SENSOR_PIN = 34; // ADC pin for analog sensor
const int RELAY_PIN = 23;  // Digital output for relay drive
const int THRESHOLD_VAL = 500;

void setup() {
    Serial.begin(115200);
    pinMode(SENSOR_PIN, INPUT);
    pinMode(RELAY_PIN, OUTPUT);
    digitalWrite(RELAY_PIN, LOW);
}

void loop() {
    int rawVal = analogRead(SENSOR_PIN);
    Serial.print("Sensor Telemetry Value: ");
    Serial.println(rawVal);

    // Edge processing threshold evaluation
    if (rawVal > THRESHOLD_VAL) {
        digitalWrite(RELAY_PIN, HIGH);
        Serial.println("ALERT: Threshold exceeded! Actuator triggered.");
    } else {
        digitalWrite(RELAY_PIN, LOW);
    }
    
    delay(100); // 100ms sampling rate
}