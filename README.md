# Smart Automated Restaurant Door Simulation 🚪🤖

A simple yet robust Arduino-based prototype designed using **Wokwi** that simulates an automatic smart door system commonly used in modern restaurants and smart buildings to welcome guests seamlessly.

## 🌐 Live Simulation
You can test, interact, and run this project live in your browser without any hardware using Wokwi:
👉 **Run Live Simulation on Wokwi  >> https://wokwi.com/projects/466627233339303937**

## 📝 Project Overview
This project uses an **Arduino UNO**, a **digital motion/proximity sensor**, and a **Servo motor** to emulate an automated door. When a person approaches, the sensor triggers the servo to rotate 90° (opening the door). Once the person passes, the servo returns to 0° (closing the door).

## 🚀 Features & Optimizations
* **Noise Reduction:** Utilizes Arduino's internal `INPUT_PULLUP` resistors to eliminate floating electrical noise and ensure reliable sensor readings without needing external hardware resistors.
* **Smooth Mechanical Movement:** Implements a tiny calculated delay (`delay(15)`) to match the mechanical speed of the servo, preventing jittering, stuttering, and overheating.
* **Clean Code Architecture:** Written using optimized embedded C++ best practices (e.g., using `const` for pin definitions to save RAM).

## 🛠️ Hardware Requirements (Simulated or Physical)
* Arduino Board (e.g., Arduino Uno, Nano)
* Servo Motor (e.g., SG90 or MG995)
* Digital Sensor (PIR Motion Sensor or IR Proximity Sensor)
* Jumper Wires & Breadboard

## 🔌 Pin Configuration
| Component | Arduino Pin |
| --------- | ----------- |
| Servo Signal Pin | D3 |
| Sensor Output Pin | D5 |

## 📂 File Structure
* `SmartDoor.ino` - The primary C++ Arduino source code.
* `diagram.json` - Wokwi simulation diagram file mapping the electronics design.
* `requirements.txt` - Documenting the exact simulation/library dependencies.
* `LICENSE` - Open-source MIT License details.

## 💻 Source Code
```cpp
#include <Servo.h>

const int SENSOR_PIN = 5; 
const int SERVO_PIN  = 3; 
Servo smartDoor;

void setup() {
  smartDoor.attach(SERVO_PIN);
  pinMode(SENSOR_PIN, INPUT_PULLUP); 
  smartDoor.write(0); // Door closed by default
}

void loop() {
  bool personDetected = (digitalRead(SENSOR_PIN) == LOW);
  
  if (personDetected) {
    smartDoor.write(90); // Open door
  } else {
    smartDoor.write(0);  // Close door
  }
  
  delay(15); // Smooth movement delay
}
