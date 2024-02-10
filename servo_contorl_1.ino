/*This program is copied from online https://www.youtube.com/watch?v=3vpP_I0l5zk

First return the shaft to 0 position, then increase to 180 degrees by 0.5s/degree. */

#include <Servo.h>
Servo m1;
int pos;

void setup() {
  Serial.begin(9600);
  
  m1.attach(9); // Connect the control pin to pin 9
}

void loop() {
  delay(500);
  m1.write(0); //Return to 0 position
  delay(1000);
  
  for (pos=0; pos<=180; pos+=1){ //loop this when 0 <= angle <= 180
    m1.write(pos);
    delay(15);
  }
}
