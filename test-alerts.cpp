#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"
#include <cstring>

using namespace std;

TEST_CASE("infers the breach for Low temperature") {
  REQUIRE(inferBreach(-12, 30) == TOO_LOW);
}

TEST_CASE("infers the breach for high temperature") {
  REQUIRE(inferBreach(33, 30) == TOO_HIGH);
}

TEST_CASE("infers the breach normal temperature") {
  REQUIRE(inferBreach(30, 30) == NORMAL);
}

TEST_CASE("checkAndAlert for passive coolong ") {
  BatteryCharacter batteryCharacter;
  string testbrand = "testing";
  strcpy(batteryCharacter.brand, testbrand.c_str());
  batteryCharacter.coolingType = PASSIVE_COOLING;
  REQUIRE(checkAndAlert(TO_CONTROLLER, batteryCharacter, 42) == true);
}

TEST_CASE("checkAndAlert for active coolong") {
  BatteryCharacter batteryCharacter;
  string testbrand = "testing";
  strcpy(batteryCharacter.brand, testbrand.c_str());
  batteryCharacter.coolingType = HI_ACTIVE_COOLING;
  REQUIRE(checkAndAlert(TO_CONTROLLER,batteryCharacter, 12) == true);
}

TEST_CASE("classify breach Temperature forcheckAndAlert med active coolong") {
  BatteryCharacter batteryCharacter;
  string testbrand = "testing";
  strcpy(batteryCharacter.brand, testbrand.c_str());
  batteryCharacter.coolingType = MED_ACTIVE_COOLING;
  REQUIRE(checkAndAlert(TO_EMAIL , batteryCharacter, 35) == true);
}

  TEST_CASE("No Alert for med active coolong") {
  BatteryCharacter batteryCharacter;
  string testbrand = "testing";
  strcpy(batteryCharacter.brand, testbrand.c_str());
  batteryCharacter.coolingType = MED_ACTIVE_COOLING;
  REQUIRE(checkAndAlert(TO_INVALID , batteryCharacter, 35) == false);
}