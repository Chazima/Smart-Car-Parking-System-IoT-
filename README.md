# Smart Car Parking System

An IoT-based automated car parking gate system that automatically opens and closes using ultrasonic sensor detection.

##  Description
This project creates an automated parking gate system that:
- **Automatically detects** vehicles using an ultrasonic sensor
- **Opens the gate** when a car approaches (within 30cm)
- **Closes the gate** after the vehicle passes through
- **Efficient operation** with state management to prevent unnecessary servo movement

##  Components Required

 Arduino Uno  -1 as a Microcontroller Board 
 Ultrasonic Sensor -1 for Distance Measurement 
 Servo Motor -1 for Gate Mechanism 
 Jumper Wires 
 Breadboard -1
 USB Cable -1
 Power Supply -1

##  Circuit Connection

### Wiring:
ULTRASONIC SENSOR → ARDUINO UNO
---------------------------------
VCC              → 5V
TRIG             → Digital Pin 8
ECHO             → Digital Pin 5
GND              → GND

SERVO MOTOR → ARDUINO UNO
---------------------------
Signal      → Digital Pin 12
VCC         → 5V
GND         → GND
