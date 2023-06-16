#include "typewise-alert.h"
#include <stdio.h>

const double lowerLimit = 0;
 
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
  int upperLimit = 0;
  switch(coolingType) {
    case PASSIVE_COOLING:
      upperLimit = 35;
      break;
    case HI_ACTIVE_COOLING:
      upperLimit = 45;
      break;
    case MED_ACTIVE_COOLING:
      upperLimit = 40;
      break;
  }
  return inferBreach(temperatureInC, upperLimit);
}

void checkAndAlert(
    AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {

  BreachType breachType = classifyTemperatureBreach(
    batteryChar.coolingType, temperatureInC
  );

  switch(alertTarget) {
    case TO_CONTROLLER:
      sendToController(breachType);
      break;
    case TO_EMAIL:
      sendToEmail(breachType);
      break;
  }
}

void sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}

void sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
  switch(breachType) {
    case TOO_LOW:
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is too low\n");
      break;
    case TOO_HIGH:
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is too high\n");
      break;
    case NORMAL:
      break;
  }
}
