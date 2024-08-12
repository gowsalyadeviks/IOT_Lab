int soundSensor = A0; // Use analog pin A0 for the sound sensor
int LED = 3;          // Digital pin for the LED
int threshold = 1000;  // Set a threshold value for detecting loud sounds

void setup() 
{
  pinMode(LED, OUTPUT);       // Set the LED pin as OUTPUT
  Serial.begin(9600);         // Start serial communication for debugging
}

void loop()
{
  int soundValue = analogRead(soundSensor); // Read the analog value from the sound sensor
  
  // Calculate a basic decibel value
  float decibelValue = (soundValue / 1023.0) * 100; // Scale to 0-100 dB for demonstration
  
  // Print detailed information to the Serial Monitor
  Serial.print("Sound Value: ");
  Serial.print(soundValue);
  Serial.print(" | Decibel Value: ");
  Serial.print(decibelValue);
  Serial.print(" dB | ");
  
  // Check if the sound value exceeds the threshold
  if (soundValue > threshold)
  {
    digitalWrite(LED, HIGH); // Turn the LED on
    Serial.println("Status: Loud Sound Detected! LED ON");
  }
  else
  {
    digitalWrite(LED, LOW);  // Turn the LED off
    Serial.println("Status: No Loud Sound. LED OFF");
  }
  
  delay(500); // Small delay to avoid rapid toggling
}
