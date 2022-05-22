#include "typewise-alert.h"
#include <stdio.h>
#include <iostream>

int coolingLowerLimits[]={0,0,0};
int coolingUpperLimits[]={30,45,40};
const char *breachTypeMessage[]={"Temperature is Normal","Temperature is too low","Temperature is too high"};

BreachType inferBreach(double value, double lowerLimit, double upperLimit) 
{
  BreachType breachType=NORMAL;
  if(value < lowerLimit) 
  {
    breachType=TOO_LOW;
  }
  if(value > upperLimit) 
  {
    breachType=TOO_HIGH;
  }
  return breachType;
}

int getLowerLimitFromcoolingType(CoolingType coolingType)
{
  return(coolingLowerLimits[coolingType]);
}

int getupperLimitFromcoolingType(CoolingType coolingType)
{
  return(coolingUpperLimits[coolingType]);
}

BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC) 
{
  int lowerLimit=getLowerLimitFromcoolingType(coolingType);
  int upperLimit=getupperLimitFromcoolingType(coolingType);
  return inferBreach(temperatureInC, lowerLimit, upperLimit);
}

void checkAndAlert(AlertTarget alertTarget, double temperatureInC,const char *recepient) 
{
    BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);
    switch(alertTarget) {
    case TO_CONTROLLER:
      sendToController(breachType);
      break;
    case TO_EMAIL:
      sendToEmail(breachType,recepient);
      break;
  }
}

void sendToController(BreachType breachType) 
{
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}

int sendToEmail(BreachType breachType, const char *recepient) 
{
  std::cout<<"To: "<<recepient<<breachTypeMessage[breachType];
  return true;
}


