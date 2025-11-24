#include <Servo.h>

// Pin definitions
#define TRIG_PIN 8
#define ECHO_PIN 5
#define SERVO_PIN 12

// Distance threshold in centimeters
#define DETECTION_DISTANCE 5

// Servo positions
#define GATE_CLOSED 0
#define GATE_OPEN 90

Servo gateServo;

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  
  // Initialize ultrasonic sensor pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
  // Attach servo to pin
  gateServo.attach(SERVO_PIN);
  
  // Start with gate closed
  gateServo.write(GATE_CLOSED);
  
  Serial.println("Smart Parking System Initialized");
  Serial.println("Gate Closed - Waiting for car...");
}

void loop() {
  // Get distance from ultrasonic sensor
  long distance = getDistance();
  
  // Print distance for debugging
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Check if car is detected
  if (distance > 0 && distance <= DETECTION_DISTANCE) {
    // Car detected - open gate
    Serial.println("Car Detected! Opening gate...");
    gateServo.write(GATE_OPEN);
    delay(3000); // Keep gate open for 3 seconds to allow car to pass
    
    // Close gate after car passes
    Serial.println("Closing gate...");
    gateServo.write(GATE_CLOSED);
    delay(1000); // Wait before next detection
  } else {
    // No car detected - keep gate closed
    gateServo.write(GATE_CLOSED);
  }
  
  delay(100); // Small delay between readings
}

// Function to measure distance using ultrasonic sensor
long getDistance() {
  // Clear the trigger pin
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  
  // Send 10 microsecond pulse to trigger
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  // Read the echo pin and calculate distance
  long duration = pulseIn(ECHO_PIN, HIGH);
  
  // Calculate distance in centimeters
  // Speed of sound is 343 m/s or 0.0343 cm/microsecond
  // Distance = (time * speed) / 2 (divide by 2 for round trip)
  long distance = duration * 0.0343 / 2;
  
  return distance;
}
