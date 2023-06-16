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

    map<CoolingType, double> coolingTypeUpperLimit;

    coolingTypeUpperLimit.insert({ PASSIVE_COOLING, 35 });
    coolingTypeUpperLimit.insert({ HI_ACTIVE_COOLING, 45 });
    oolingTypeUpperLimit.insert({ MED_ACTIVE_COOLING, 40 }); 
     
    if(coolingTypeUpperLimit.find(coolingType) != coolingTypeUpperLimit.end()){
      upperLimit = coolingTypeUpperLimit[coolingType];
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
