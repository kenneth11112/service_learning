/*
Connection to the BTS7960 board:
BTS7960 Pin 1 (RPWM) to Arduino pin 5(PWM)
BTS7960 Pin 2 (LPWM) to Arduino pin 6(PWM)
BTS7960 Pin 3 (R_EN), 4 (L_EN), 7 (VCC) to Arduino 5V pin
BTS7960 Pin 8 (GND) to Arduino GND
BTS7960 Pin 5 (R_IS) and 6 (L_IS) not connected
*/

#include <Servo.h>

Servo m1;  // create servo object to control a servo
// twelve servo objects can be created on most boards

//Define pins
const int sw1 = 2;  // switch for forward movement
const int sw2 = 3;  // switch for backward movement
const int bt = 4;   // connect button to pin 3
volatile byte state = LOW;

//Define variables
int sw1State = 0;
int sw2State = 0;
int btState = 0;
int pos;        // variable to store the servo position
int time = 15;  // time between each step

void setup() {
  Serial.begin(9600);

  m1.attach(9);  // attaches the servo on pin 9 to the servo object

  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
  pinMode(bt, INPUT);
  pinMode(bt, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(bt), stop, CHANGE);
}

void loop() {
  while (state == LOW) {
    if (sw1 == HIGH) {
      for (pos = 0; pos <= 180; pos += 1) {  // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        m1.write(pos);  // tell servo to go to position in variable 'pos'
        Serial.println(pos);
        delay(time);  // default as waiting 15ms for the servo to reach the position
      }
    }

    if (sw2 == HIGH) {
      for (pos = 180; pos >= 0; pos -= 1) {  // goes from 180 degrees to 0 degrees
        m1.write(pos);                  // tell servo to go to position in variable 'pos'
        delay(15);                           // waits 15ms for the servo to reach the position
      }
    }
  }
}

void stop() {
  state = !state;
}
