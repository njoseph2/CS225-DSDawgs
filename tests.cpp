#ifndef CATCH_CONFIG_MAIN
#define CATCH_CONFIG_MAIN
#endif
#include "catch.hpp"

#include <vector>
#include "CSV.h"
#include "pagerank.h"

/////////////////////////////////////////////////////////////////////////////////////////////
//                                Test Cases //
/////////////////////////////////////////////////////////////////////////////////////////////

TEST_CASE("good tokenization", "[CSV]") {
  // SECTION("Can use sections") {}
  std::vector<std::vector<std::string>> result = readCSV("testing.csv");
  REQUIRE(result[0][0] == "A");
  REQUIRE(result[0][1] == "B");
  REQUIRE(result[1][0] == "A");
  REQUIRE(result[1][1] == "C");
  REQUIRE(result[2][0] == "C");
  REQUIRE(result[2][1] == "B");
  REQUIRE(result[3][0] == "C");
  REQUIRE(result[3][1] == "D");
  REQUIRE(result[4][0] == "D");
  REQUIRE(result[4][1] == "E");
}

TEST_CASE("first iteration", "[pagerank]") {
  // SECTION("Can use sections") {}
  std::vector<std::vector<std::string>> file = readCSV("testing.csv");
  PageRank run;
  run.integrate(file);
  run.algorithm();
  std::map<std::string, double> check = run.getOriginal();
  REQUIRE(check["A"] == (.2/3) + (.2/2));
  REQUIRE(check["B"] == (.2/3) + (.2/2));
  REQUIRE(check["C"] == (.2/2) + (.2/2) + (.2/2));
  REQUIRE(check["D"] == (.2/3) + (.2/1));
  REQUIRE(check["E"] == (.2/2));
}