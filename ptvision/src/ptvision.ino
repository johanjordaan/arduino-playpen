#include <Servo.h>

Servo servo;
void setup(){
   Serial.begin(9600);
   servo.attach(9);
   servo.write(0);
}

int sensorValue = 0;
int angle = 0;
int delta = 1;
void loop(){
   sensorValue = analogRead(A1);
   Serial.println(sensorValue);
   Serial.println(angle);

   if(angle+delta>=180-1 || angle+delta<=0)
      delta *= -1;
   angle += delta;

   servo.write(angle);
   delay(10);
}
