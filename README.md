# RoboNav-Autonomous-Robot
Arduino-based autonomous obstacle detection and avoidance robot. 

RoboNav — Autonomous Obstacle Detection & Avoidance Robot

A Robotics & AI Student Project

Project Overview

RoboNav is a Level-1 autonomous mobile robot designed to detect obstacles, scan its surroundings, and select a clearer direction using an Arduino-based control system.

Features

- Real-time obstacle detection
- Left and right scanning using a servo motor
- Automatic direction selection
- Autonomous movement and turning

Hardware Components

Component| Purpose
Arduino UNO| Main controller
HC-SR04| Distance measurement
SG90 Servo| Sensor scanning
L298N| Motor control
DC Gear Motors| Robot movement
Battery Pack| Power supply
Chassis| Robot structure

Working Principle

1. The ultrasonic sensor measures the front distance.
2. If the path is clear, the robot moves forward.
3. If an obstacle is detected, the robot stops.
4. The servo scans the left and right directions.
5. Arduino compares the measured distances.
6. The robot turns toward the direction with more available space.

Pin Configuration

Component| Arduino Pin
HC-SR04 TRIG| D9
HC-SR04 ECHO| D10
Servo Signal| D6
L298N ENA| D5
L298N IN1| D7
L298N IN2| D8
L298N IN3| D12
L298N IN4| D13
L298N ENB| D11

Software & Technologies

- Arduino IDE
- Embedded C++ / Arduino programming
- Ultrasonic sensing
- Servo and DC motor control

Challenges & Learning

During development, I faced challenges with:

- Incorrect motor rotation direction
- Reversed left and right turns
- Servo movement and connections
- Hardware wiring and debugging

Solving these problems helped me understand sensor integration, motor control, and systematic troubleshooting.

Project Images


<img width="1600" height="1200" alt="WhatsApp Image 2026-11-01 at 11 33 05 AM" src="https://github.com/user-attachments/assets/274f3ffe-ec08-4a96-9286-ab7a50418531" />

<img width="1600" height="1200" alt="WhatsApp Image 2026-09-13 at 1 28 00 PM" src="https://github.com/user-attachments/assets/91ef2774-46d2-4b9a-8494-d1a3b54b93de" />
<img width="1200" height="1600" alt="WhatsApp Image 2026-11-01 at 11 33 05 AM (2)" src="https://github.com/user-attachments/assets/403a5df3-bac6-4258-bdbd-4df50700377d" />




Future Improvements

- Smoother turning and movement
- Improved obstacle navigation
- More advanced path-planning algorithms

Developer

Abhishek Sharma
B.Tech — Robotics and Artificial Intelligence

---

Build • Test • Debug • Improve 🤖
