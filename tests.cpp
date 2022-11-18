#ifndef CATCH_CONFIG_MAIN
#define CATCH_CONFIG_MAIN
#endif
#include "catch.hpp"

#include <vector>
#include "CSV.h"
//#include "CS225-DSDawgs/pagerank.h"

/////////////////////////////////////////////////////////////////////////////////////////////
//                                Test Cases //
/////////////////////////////////////////////////////////////////////////////////////////////

TEST_CASE("bad file", "[CSV]") {
  // SECTION("Can use sections") {}
  std::vector<std::vector<std::string>> result = readCSV("test.cvs");
  REQUIRE(result[0][0] == "A");
  REQUIRE(result[0][1] == "A");
  REQUIRE(result[1][0] == "A");
  REQUIRE(result[1][1] == "A");
  REQUIRE(result[2][0] == "A");
  REQUIRE(result[2][1] == "A");
}

TEST_CASE("Test2", "[CSV]") {
  // SECTION("Can use sections") {}
  std::string t = "test";
  REQUIRE(t == "test");
}

TEST_CASE("Test3", "[board_init]") {
  // SECTION("Can use sections") {}
  std::string t = "test";
  REQUIRE(t == "test");
}