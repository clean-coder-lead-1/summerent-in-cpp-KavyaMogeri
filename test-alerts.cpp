#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits") {
  REQUIRE(inferBreach(-12, 30) == TOO_LOW);
}

TEST_CASE("infers the breach according to limits") {
  REQUIRE(inferBreach(33, 30) == TOO_HIGH);
}

TEST_CASE("infers the breach according to limits") {
  REQUIRE(inferBreach(30, 30) == NORMAL);
}

TEST_CASE("infers the breach according to limits") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 42) == TOO_HIGH);
}

TEST_CASE("infers the breach according to limits") {
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 12) == NORMAL);
}

TEST_CASE("infers the breach according to limits") {
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 35) == NORMAL);
}