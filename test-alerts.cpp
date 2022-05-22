#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits") {
  REQUIRE(inferBreach(-1, 0, 30) == TOO_LOW);
  REQUIRE(inferBreach(-1 , 0, 45) == TOO_LOW);
  REQUIRE(inferBreach(-1 , 0, 40) == TOO_LOW);
  REQUIRE(inferBreach( 0 , 0, 30) == NORMAL);  
  REQUIRE(inferBreach( 31, 0, 30) == TOO_HIGH);
  REQUIRE(inferBreach( 46, 0, 45) == TOO_HIGH);
  REQUIRE(inferBreach( 41, 0, 40) == TOO_HIGH);
  REQUIRE(inferBreach( 29, 0, 30) == NORMAL);  
}

TEST_CASE("Classify the temperature breach based on cooling type")
{
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING,-1) == TOO_LOW);
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING,0) == NORMAL);
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING,31) == TOO_HIGH);
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING,-1) == TOO_LOW);
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING,0) == NORMAL);
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING,45) == TOO_HIGH);
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING,-1) == TOO_LOW);
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING,0) == NORMAL);
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING,41) == TOO_HIGH);
}

TEST_CASE("Alerter")
{
  CoolingType ct;
  ct.coolingType=PASSIVE_COOLING;
  REQUIRE(checkAndAlert(TO_EMAIL,50,"abc@xyz.com") == true);
}
