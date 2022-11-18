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

TEST_CASE("Test1", "[board_init]") {
  // SECTION("Can use sections") {}
  std::string t = "test";
  REQUIRE(t == "test");
}
