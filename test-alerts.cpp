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
