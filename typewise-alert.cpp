#include "typewise-alert.h"
#include <stdio.h>

const double lowerLimit = 0 ;

BreachType inferBreach(double value, double upperLimit) {
  BreachType breachType = NORMAL;
  if(value < lowerLimit) {
    breachType = TOO_LOW;
  }
  if(value > upperLimit) {
    breachType = TOO_HIGH;
  }
  return breachType;
}

BreachType classifyTemperatureBreach(
    CoolingType coolingType, double temperatureInC) {   
   return inferBreach(temperatureInC, getUpperLimit);
}

double getUpperLimit(CoolingType coolingType){
  int upperLimit = 0;
  if(coolingType == PASSIVE_COOLING)
  {
    upperLimit = 35;    
  }else if(coolingType == HI_ACTIVE_COOLING)
  {
    upperLimit = 45;
  }else if(coolingType == MED_ACTIVE_COOLING){
    upperLimit = 40;
  }
  return upperLimit;
}

void checkAndAlert(
    AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {

  BreachType breachType = classifyTemperatureBreach(
    batteryChar.coolingType, temperatureInC
  );

  if(TO_CONTROLLER == alertTarget) {
          sendToController(breachType);
      } else 
      {
        sendToEmail(breachType);
      }
  }

void sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}

void sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
  printf("To: %s\n", recepient);
  if(TOO_LOW == breachType) {      
      printf("Hi, the temperature is too low\n");
  }else if(TOO_HIGH == breachType )
  {    
      printf("Hi, the temperature is too high\n");
  }
}
