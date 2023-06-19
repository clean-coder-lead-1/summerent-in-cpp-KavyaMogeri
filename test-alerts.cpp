#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach for Low temperature") {
  REQUIRE(inferBreach(-12, 30) == TOO_LOW);
}

TEST_CASE("infers the breach for high temperature") {
  REQUIRE(inferBreach(33, 30) == TOO_HIGH);
}

TEST_CASE("infers the breach normal temperature") {
  REQUIRE(inferBreach(30, 30) == NORMAL);
}

TEST_CASE("classify breach Temperature for passive coolong ") {
  BatteryCharacter batteryCharacter;
  batteryCharacter.brand = "testing";
  batteryCharacter.coolingType = PASSIVE_COOLING;
  REQUIRE(checkAndAlert(TO_CONTROLLER, batteryCharacter, 42) == true);
}

TEST_CASE("classify breach Temperature for active coolong") {
  BatteryCharacter batteryCharacter;
  batteryCharacter.brand = "testing";
  batteryCharacter.coolingType = HI_ACTIVE_COOLING;
  REQUIRE(classifyTemperatureBreach(TO_CONTROLLER,batteryCharacter, 12) == true);
}

TEST_CASE("classify breach Temperature for med active coolong") {
  BatteryCharacter batteryCharacter;
  batteryCharacter.brand = "testing";
  batteryCharacter.coolingType = MED_ACTIVE_COOLING;
  REQUIRE(classifyTemperatureBreach(TO_EMAIL , batteryCharacter, 35) == true);
}