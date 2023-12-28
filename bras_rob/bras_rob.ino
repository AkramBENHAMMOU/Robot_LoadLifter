#include <servo.h>

#define trigPin 13
#define echoPin 8

Servo servo_base;
Servo servo_bras_sup;
Servo servo_bras_inf;
Servo servo_pince;
int sound = 250;

void setup(){
  Serial.begin (9600);
  pinMode(trigPin , OUTPUT);
  pinMode(echoPin, INPUT);

  Servo_base.attach(9);
  servo_bras_sup.attach(10);
  servo_bras_inf.attach(12);
  servo_pince.attach(11);
}
void loop(){
  long durarion , distance ,nbr=0;
  digitalWrite(trigPin , LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2)/29.1;
  if(distance < 15 && dinstance>0){
    Serial.print(distance);
  Serial.println("cm");
  for(nbr=0;nbr<2;nbr++){
    delay(600);
  Serial.println("the distance is less than 30 ");

  if(nbr==0)
    servo_base.write(90);
  if(nbr==1)
    servo_base.write(140);
    delay(1000);
    servo_pince.write(180);
    delay(1000);
    servo_bras_sup.write(40);
    delay(1000);
    servo_bras_inf.write(0);
    delay(2000);
    
    servo_pince.write(0);
    delay(1000);
    servo_bras_sup.write(140);
    delay(2000);
    servo_base.write(0);
    delay(2000);
    servo_bras_sup.write(60);
    delay(1000);
     servo_pince.write(180);
    delay(1000);
    servo_bras_sup.write(140);
    delay(1000);
    delay(1500);
    servo_pince.write(0);
    delay(1000);
    delay(1500);
    }  
  }  
 else{
    servo_base.write(120);
    delay(1500);
  }
  delay(2000);
}