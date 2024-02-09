/*This program first return the shaft to 0 position, then increase to 180 degrees by 0.5s/degree. */

#include <Servo.h>
Servo m1;
int pos;
int choice;
int button =3;

void setup() {
  Serial.begin(9600);
  
  m1.attach(9); // Connect the control pin to pin 9
  pinMode(3, INPUT)
}

def menu(){
  while (1){
    println("1. Step by step");
    println("2. Auto_up")
    println("3. Auto_down")
    print("Please choose 1, 2, or 3: ");
    choice = Serial.read();

    if (choice = "1"){
      step();
      return 1;
    }
    else if (choice = "2"){
      auto_up();
      return 1;
    }
    else if (choice = "3"){
      auto_down();
      return 1;
    }
    else(){
      return 1;
    }  
  }
}

void step(){
  continue;
}

void auto_up(){
  continue;
}

void auto_down(){
  continue;
}

void loop() {
  delay(500);
  m1.write(0); //Return to 0 position
  delay(1000);

  menu();
  if (Serial.availabe()){
    int lagging = Serial.read(); //can only read the very first byte
  }

  for (pos=0; pos<=180; pos+=1){ //loop this when 0 <= angle <= 180
    m1.write(pos);
    delay (lagging);
  }
}
