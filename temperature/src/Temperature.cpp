#include "Temperature.h"

Temperature::Temperature(int pin)
{
   _pin = pin;
}

float Temperature::Read()
{
   int sensorVal = analogRead(_pin);
   float voltage = (sensorVal/1024.0) * 5.0;
   // convert the voltage to temperature in degrees C
   // the sensor changes 10 mV per degree
   // the datasheet says there's a 500 mV offset
   // ((volatge - 500mV) times 100)
   float temperature = (voltage - .5) * 100;

   log(sensorVal,voltage,temperature);
}

int Temperature::GetBaseLineTemp()
{
   return _baseLineTemp;
}

void Temperature::log(int sensorVal,float voltage, float temperature)
{
   Serial.print("SensorVal : [");
   Serial.print(sensorVal);
   Serial.print("], Voltage : [");
   Serial.print(voltage);
   Serial.print("], Temp(C) : [");
   Serial.print(temperature);
   Serial.println("]");
}
