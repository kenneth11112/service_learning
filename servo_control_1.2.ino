#include <Servo.h>

Servo m1;  // create servo object to control a servo
// twelve servo objects can be created on most boards

//Define pins
const int sw1 = 2;  // switch for forward movement
const int sw2 = 3;  // switch for backward movement
const int bt = 4;   // connect button to pin 3
volatile byte state = LOW;

//Define variables
volatile byte sw1State = LOW;
volatile byte sw2State = LOW;
volatile byte btState = LOW;
int pos;        // variable to store the servo position
int time = 60;  // time between each step

void setup() {
  Serial.begin(9600);

  m1.attach(9);  // attaches the servo on pin 9 to the servo object

  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
  pinMode(bt, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(bt), stop, CHANGE);
}

void loop() {
  while (state == LOW) {
    if (sw1State == HIGH) {
      for (pos >= 0; pos <= 90; pos += 1) {  	// goes from 0 degrees to 90 degrees
        // in steps of 1 degree
        m1.write(pos);  											// tell servo to go to position in variable 'pos'
        Serial.println(pos);
        delay(time);  												// default as waiting 15ms for the servo to reach the position
      }
    }

    if (sw2State == HIGH) {
      for (pos <= 90; pos >= 0; pos -= 1) {  	// goes from 90 degrees to 0 degrees
        m1.write(pos);                  			// tell servo to go to position in variable 'pos'
				Serial.println(pos);
        delay(15);                           	// waits 15ms for the servo to reach the position
      }
		}
		if (btState == HIGH){
			stop();
    }
  }
}

void stop() {
  state = !state;
}
