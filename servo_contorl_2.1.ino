#include <Servo.h>

// Define constants for the motor driver pins
const int MOTOR_PWM = 11;
const int MOTOR_IN1 = 12;
const int MOTOR_IN2 = 13;

// Define constants for the potentiometer and button pins
const int POTENTIOMETER_PIN = A0;
const int SWITCH1_PIN = 2;
const int SWITCH2_PIN = 3;
const int BUTTON_PIN = 4;

// Create a Servo object for the motor
Servo motor;

void setup() {
  // Initialize the motor driver pins
  pinMode(MOTOR_PWM, OUTPUT);
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);

  // Initialize the potentiometer and button pins
  pinMode(POTENTIOMETER_PIN, INPUT);
  pinMode(SWITCH1_PIN, INPUT);
  pinMode(SWITCH2_PIN, INPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // Attach the motor to the motor driver pins
  motor.attach(MOTOR_PWM, MOTOR_IN1, MOTOR_IN2);
}

void loop() {
  // Read the potentiometer value
  int potValue = analogRead(POTENTIOMETER_PIN);

  // Map the potentiometer value to a motor speed value
  int motorSpeed = map(potValue, 0, 1023, 0, 255);

  // Set the motor speed
  motor.write(motorSpeed);

  // Check if the button is pressed
  if (digitalRead(BUTTON_PIN) == LOW) {
    // Stop the motor
    motor.write(0);
  }

  // Delay for 10 milliseconds
  delay(10);
}