#include <Servo.h>
Servo monServo;
Char cmd;
int in1=5;
int in2=4;
int in3=3;
int in4=2;

void setup() {
   monServo.attach(A0);
   pinMode(in1, OUTPUT);
   pinMode(in2, OUTPUT);
   pinMode(in3, OUTPUT);
   pinMode(in4, OUTPUT);
   Serial.begin(9600);
}

void loop() {
  if(Serial.available()){
    cmd = Serial.read();
  }
  //avancer 
  if(cmd=='F'){
    digitalWrite(in1, HIGH);
    digitalWrite(in4, HIGH);
  }
// en arrière 
  else if(cmd=='B'){
      digitalWrite(in2, HIGH);
      digitalWrite(in3, HIGH);
  }
  //gauche
  else if(cmd=='L'){
      digitalWrite(in4, HIGH);
      digitalWrite(in2, HIGH);
  }
  //droite 
  else if(cmd == 'R'){
      digitalWrite(in1, HIGH);
      digitalWrite(in3, HIGH);
  }

  //le moteur de dechargement tournera d'un angle de 170 puis retrouve sa position initiale 0
   else if(cmd == 'W'){
      monServo.Write(170);
      delay(1500);
      monServo.write(0);
  }
  else{
      digitalWrite(in1, HIGH);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, HIGH);
  }

}
