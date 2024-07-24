// C++ code

int bt1 = 4;
int bt2 = 2;
int btState1 = 0;
int btState2 = 0;

int enA = 11;
int int1 = 10;
int int2 = 9;
int o1State = 0;
int o2State = 0;
  
int spd = 255;

void setup()
{
  Serial.begin(9600);
  pinMode(bt1, INPUT);
  pinMode(bt2, INPUT);
  pinMode(enA, OUTPUT);
  pinMode(int1, OUTPUT);
  pinMode(int2, OUTPUT);
}

void loop()
{
  analogWrite(enA, spd);
  btState1 = digitalRead(bt1);
  btState2 = digitalRead(bt2);
  o1State = digitalRead(int1);
  o2State = digitalRead(int2);
  
  if ((btState1 == HIGH) && (btState2 == LOW)){
    analogWrite(int1, spd);
    digitalWrite(int2, LOW);
    Serial.print(1);
    Serial.print(o1State);
    Serial.println(o2State);
  }
  else if ((btState1 == LOW) && (btState2 == HIGH)){
    digitalWrite(int1,LOW);
    analogWrite(int2,spd);
    Serial.print(-1);
    Serial.print(o1State);
    Serial.println(o2State);
  }
  else{
    digitalWrite(int1, LOW);
    digitalWrite(int2, LOW);
    Serial.print(0);
    Serial.print(o1State);
    Serial.println(o2State);
  }
}