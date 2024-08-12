#include <SoftwareSerial.h> // Include the SoftwareSerial library for Bluetooth communication

int soundSensor = A0; // Use analog pin A0 for the sound sensor
int LED = 3;          // Digital pin for the LED
int threshold = 1020; // Set a threshold value for detecting loud sounds

// Create a SoftwareSerial object for Bluetooth communication
SoftwareSerial bluetoothSerial(10, 11); // RX, TX pins for Bluetooth module (adjust as needed)

void setup() 
{
  pinMode(LED, OUTPUT);          // Set the LED pin as OUTPUT
  bluetoothSerial.begin(9600);   // Start Bluetooth serial communication
  Serial.begin(9600);            // Start regular serial communication for debugging (optional)
}

void loop()
{
  int soundValue = analogRead(soundSensor); // Read the analog value from the sound sensor
  
  // Calculate a basic decibel value
  float decibelValue = (soundValue / 1023.0) * 100; // Scale to 0-100 dB for demonstration
  
  // Print detailed information to the Bluetooth Serial Monitor
  bluetoothSerial.print("Sound Value: ");
  bluetoothSerial.print(soundValue);
  bluetoothSerial.print(" | Decibel Value: ");
  bluetoothSerial.print(decibelValue);
  bluetoothSerial.print(" dB | ");
  
  // Check if the sound value exceeds the threshold
  if (soundValue > threshold)
  {
    digitalWrite(LED, HIGH); // Turn the LED on
    bluetoothSerial.println("Status: Loud Sound Detected! LED ON");
  }
  else
  {
    digitalWrite(LED, LOW);  // Turn the LED off
    bluetoothSerial.println("Status: No Loud Sound. LED OFF");
  }
  
  delay(500); // Small delay to avoid rapid toggling
}
