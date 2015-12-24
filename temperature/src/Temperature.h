#ifndef __TEMPERATUTE_H__
#define __TEMPERATURE_H__

#include "Arduino.h"

class Temperature
{
   public:
      Temperature(int pin);
      float Read();

      int GetBaseLineTemp();

   private:
      int _baseLineTemp = 20;
      int _pin;

      void log(int sensorVal,float voltage, float temperature);
};

#endif // __TEMPERATURE_H__
