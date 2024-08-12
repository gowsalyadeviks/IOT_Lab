#include <dht11.h>
#include <SoftwareSerial.h>

#define DHT11PIN 7

dht11 DHT11;

// Create a SoftwareSerial object for Bluetooth communication
SoftwareSerial bluetooth(10, 11); // RX, TX pins for Bluetooth

void setup() {
  Serial.begin(9600);          // Start the serial communication with the computer
  bluetooth.begin(9600);      // Start Bluetooth communication
}

void loop() {
  Serial.println();
  
  int chk = DHT11.read(DHT11PIN);
  Serial.print("Humidity (%): ");
  Serial.println((float)DHT11.humidity, 2);
  
  Serial.print("Temperature  (C): ");  
  Serial.println((float)DHT11.temperature, 2);
  
  // Send data to Bluetooth
  bluetooth.print("Humidity: ");
  bluetooth.print((float)DHT11.humidity, 2);
  bluetooth.print("%, Temperature: ");
  bluetooth.print((float)DHT11.temperature, 2);
  bluetooth.println("C");

  delay(2000);
}
