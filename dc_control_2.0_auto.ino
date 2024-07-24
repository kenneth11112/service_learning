//Input pins
const int startswitch = 6; //start or end
const int intbt = 2; //Interrupt
//const int intbt2 = 3; //Interrupt 2
//const int PWMcon = A5;

//Output pins to L298 motor driver
const int enA = 5;
const int out1 = 4;
const int out2 = 3;

//Indicator output pins
const int idc1 = 13;
const int idc2 = 12;

//States: 0=LOW, 1=HIGH
int startstate; 
int btState1 = 0; //Interrupt 1 state
//int btState2 = 0; //Interrupt 2 state
int o1State = 1;  //Output to L298 INT1
int o2State = 0;  //Output to L298 INT2

void setup() {
  //Control input pins
  pinMode(startswitch, INPUT_PULLUP);
  pinMode(intbt, INPUT_PULLUP);
  //pinMode(intbt2, INPUT_PULLUP);
  //pinMode(PWMcon, INPUT);

  //Motor driver output
  pinMode(enA, OUTPUT);
  pinMode(out1, OUTPUT);
  pinMode(out2, OUTPUT);

  //Indicator LED output
  pinMode(idc1, OUTPUT);
  pinMode(idc2, OUTPUT);


  //Set interrupt
  attachInterrupt(digitalPinToInterrupt(intbt), trigger, FALLING);
  //attachInterrupt(digitalPinToInterrupt(intbt2), trigger, RISING);
}

void loop() {
  /*
  //PWM value
  spd = analogRead(con);  //Read the value from the speed potentiometer input
  analogWrite(enA, spd);
  float spd_display = map(spd, 0, 255, 0, 10);   //Convert 0-255 scale to 0-10 scale
  spd_display = round(spd_display * 10) / 10.0;  //Round off to 1 d.p.
  */

  //Read switch state
  startstate = digitalRead(startswitch);

  //Direction control
  analogWrite(enA, 255);
  if (startstate == HIGH) {
    //Motor diver control
    digitalWrite(out1, o1State);
    digitalWrite(out2, o2State);

    //LED indicator
    digitalWrite(idc1, o1State);
    digitalWrite(idc2, o2State);
  }
  else {
    //Motor driver control
    digitalWrite(out1, LOW);
    digitalWrite(out2, LOW);

    //LED indicator
    digitalWrite(idc1, LOW);
    digitalWrite(idc2, LOW);
  }
}

//When the interrupt button is pressed, change the direction, ie the states of the two outputs                  
void trigger() {
  o1State = !o1State;
  o2State = !o2State;
}