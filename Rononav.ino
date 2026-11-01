#include <Servo.h>

// ================= SENSOR =================
#define TRIG_PIN 9
#define ECHO_PIN 10

// ================= SERVO =================
#define SERVO_PIN 6

// ================= L298N =================
#define ENA 5
#define IN1 7
#define IN2 8

#define ENB 11
#define IN3 12
#define IN4 13

Servo scanner;

// Motor speed: 0–255
int motorSpeed = 150;

// Minimum safe distance in cm
int safeDistance = 25;


// =================================================
//                ULTRASONIC FUNCTION
// =================================================

long getDistance() {

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);

  if (duration == 0) {
    return 400;
  }

  long distance = duration * 0.034 / 2;

  return distance;
}


// =================================================
//                    STOP
// =================================================

void stopRobot() {

  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}


// =================================================
//                   FORWARD
// =================================================

void forward() {

  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);

  // Adjusted because your robot was moving backward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}


// =================================================
//                    LEFT TURN
// =================================================

void leftTurn() {

  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}


// =================================================
//                   RIGHT TURN
// =================================================

void rightTurn() {

  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}


// =================================================
//                  SETUP
// =================================================

void setup() {

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  scanner.attach(SERVO_PIN);

  scanner.write(90);

  Serial.begin(9600);

  stopRobot();

  delay(1000);

  Serial.println("RoboNav Started");
}


// =================================================
//                    MAIN LOOP
// =================================================

void loop() {

  // Look straight
  scanner.write(90);
  delay(200);

  long frontDistance = getDistance();

  Serial.print("Front: ");
  Serial.print(frontDistance);
  Serial.println(" cm");


  // ---------------------------------------------
  // PATH IS CLEAR
  // ---------------------------------------------

  if (frontDistance > safeDistance) {

    forward();

    delay(50);

    return;
  }


  // ---------------------------------------------
  // OBSTACLE DETECTED
  // ---------------------------------------------

  Serial.println("Obstacle detected!");

  stopRobot();

  delay(300);


  // ---------------------------------------------
  // SCAN LEFT
  // ---------------------------------------------

  scanner.write(150);

  delay(500);

  long leftDistance = getDistance();

  Serial.print("Left: ");
  Serial.print(leftDistance);
  Serial.println(" cm");


  // ---------------------------------------------
  // SCAN RIGHT
  // ---------------------------------------------

  scanner.write(30);

  delay(500);

  long rightDistance = getDistance();

  Serial.print("Right: ");
  Serial.print(rightDistance);
  Serial.println(" cm");


  // ---------------------------------------------
  // RETURN SERVO TO CENTER
  // ---------------------------------------------

  scanner.write(90);

  delay(200);


  // ---------------------------------------------
  // CHOOSE CLEARER PATH
  // ---------------------------------------------

  if (leftDistance > rightDistance) {

    Serial.println("Turning LEFT");

    leftTurn();

    delay(600);

    stopRobot();

  }

  else {

    Serial.println("Turning RIGHT");

    rightTurn();

    delay(600);

    stopRobot();
  }


  delay(200);
}
