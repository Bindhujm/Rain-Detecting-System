/*
  Rain Detection System
  This sketch reads the output from a rain sensor module and activates an LED,
  a buzzer, and a motor when rain is detected.
  The sensitivity can be adjusted via the potentiometer on the sensor module.
*/

// Define the pins for the components
const int rainSensorDigitalPin = 2; // Digital output pin of the rain sensor
const int rainSensorAnalogPin = A0; // Analog output pin of the rain sensor
const int ledPin = 8;               // Pin connected to the LED
const int buzzerPin = 9;            // Pin connected to the buzzer
const int motorPin = 10;            // Pin connected to the motor control module

// Threshold for rain detection (can be adjusted)
const int rainThreshold = 400; // Adjust this value based on your sensor's sensitivity

void setup() {
  // Initialize Serial Communication for debugging
  Serial.begin(9600);

  // Set the pin modes
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(motorPin, OUTPUT);
  pinMode(rainSensorDigitalPin, INPUT);
}

void loop() {
  // Read the analog value from the rain sensor
  int analogValue = analogRead(rainSensorAnalogPin);

  // Print the analog value to the Serial Monitor for debugging and calibration
  Serial.print("Analog Value: ");
  Serial.println(analogValue);

  // Check if the analog value indicates rain
  if (analogValue < rainThreshold) {
    // Rain is detected
    Serial.println("Rain Detected!");

    // Activate the alerts
    digitalWrite(ledPin, HIGH);   // Turn on the LED
    tone(buzzerPin, 1000);        // Activate the buzzer with a 1000Hz tone
    digitalWrite(motorPin, HIGH); // Turn on the motor
  } else {
    // No rain is detected
    Serial.println("No Rain Detected.");

    // Deactivate the alerts
    digitalWrite(ledPin, LOW);    // Turn off the LED
    noTone(buzzerPin);            // Turn off the buzzer
    digitalWrite(motorPin, LOW);  // Turn off the motor
  }

  // A small delay to avoid spamming the Serial Monitor
  delay(200);
}