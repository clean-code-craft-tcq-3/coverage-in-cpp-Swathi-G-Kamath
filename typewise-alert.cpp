#include "typewise-alert.h"
#include <stdio.h>

BreachType inferBreach(double value, double lowerLimit, double upperLimit) 
{
  Breachtype breachType=NORMAL;
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

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) 
{
    BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);
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

void sendToEmail(BreachType breachType, const char *recepient) 
{
  std::cout<<"To: "<<recepient<<breachTypeMessage[breachtype];
}

}
