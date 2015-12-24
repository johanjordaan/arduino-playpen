#include "Temperature.h"

Temperature t(A0);

void setup(){
  Serial.begin(9600);
  for(int pinNumber = 2; pinNumber<5; pinNumber++){
    pinMode(pinNumber,OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop(){
   int temperature = t.Read();

  // if the current temperature is lower than the baseline
  // turn off all LEDs
  if(temperature < t.GetBaseLineTemp()){
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  } // if the temperature rises 2-4 degrees, turn an LED on
  else if(temperature >= t.GetBaseLineTemp()+2 && temperature < t.GetBaseLineTemp()+4){
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  } // if the temperature rises 4-6 degrees, turn a second LED on
  else if(temperature >= t.GetBaseLineTemp()+4 && temperature < t.GetBaseLineTemp()+6){
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
  } // if the temperature rises more than 6 degrees, turn all LEDs on
  else if(temperature >= t.GetBaseLineTemp()+6){
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
  }
  delay(1);
}
