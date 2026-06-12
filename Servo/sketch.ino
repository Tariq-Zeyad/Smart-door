#include <Servo.h>

const int SENSOR_PIN = 5; // e.g., Motion or IR sensor
const int SERVO_PIN  = 3; // Servo motor acting as the door mechanism
Servo smartDoor;

void setup() {
  smartDoor.attach(SERVO_PIN);
  pinMode(SENSOR_PIN, INPUT_PULLUP); 
  smartDoor.write(0); // Door is closed by default
}

void loop() {
  // If sensor detects someone
  bool personDetected = (digitalRead(SENSOR_PIN) == LOW);
  
  if (personDetected) {
    smartDoor.write(90); // Open the door
  } else {
    smartDoor.write(0);  // Close the door
  }
  
  delay(15); // Gives the servo time to move smoothly
}