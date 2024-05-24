#include <SoftwareSerial.h>

// Bluetooth configuration
SoftwareSerial B(10, 11); // RX, TX

// Ultrasonic sensor and buzzer configuration
#define trigPin 9    // Trig Pin Of HC-SR04
#define echoPin 8    // Echo Pin Of HC-SR04
#define BUZ 13       // BUZZER

long duration, distance;

void setup() 
{
  // Initialize Bluetooth communication
  B.begin(9600);

  // Initialize Serial communication for debugging
  Serial.begin(9600);

  // Initialize pins for ultrasonic sensor and buzzer
  pinMode(BUZ, OUTPUT);
  pinMode(trigPin, OUTPUT); // Set Trig Pin As O/P To Transmit Waves
  pinMode(echoPin, INPUT);  // Set Echo Pin As I/P To Receive Reflected Waves
}

void loop() 
{
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Set the trigPin HIGH for 10 microseconds to send out a pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echoPin and calculate the distance
  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2; // Calculate the distance in centimeters

  // Print the distance to the Serial Monitor for debugging
  Serial.println(distance);

  // Send the distance data via Bluetooth
  B.print(distance);
  B.print(";");

  // If the distance is less than 15 cm, trigger the buzzer
  if (distance < 15) 
  {
    // Turn the buzzer on and off 5 times
    for (int i = 0; i < 5; i++)
    {
      digitalWrite(BUZ, HIGH);
      B.print("Danger");
      delay(50);
      digitalWrite(BUZ, LOW);
      delay(50);
    }
  }

  // Small delay before the next loop iteration
  delay(10);
}
