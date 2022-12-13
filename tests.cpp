#ifndef CATCH_CONFIG_MAIN
#define CATCH_CONFIG_MAIN
#endif
#include "catch.hpp"
#include "BFS.h"
#include <vector>
#include "CSV.h"
#include "pagerank.h"

/////////////////////////////////////////////////////////////////////////////////////////////
//                                Test Cases //
/////////////////////////////////////////////////////////////////////////////////////////////

TEST_CASE("good tokenization", "[CSV]") {
  // ECTION("Can use sections") {}
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

TEST_CASE("to Graph", "[CSV]") {
  // ECTION("Can use sections") {}
  std::vector<std::vector<std::string>> result = readCSV("testing.csv");
  Graph* graph = toGraph(result);
  REQUIRE(graph->vertexExists("A"));
  REQUIRE(graph->vertexExists("B"));
  REQUIRE(graph->vertexExists("C"));
  REQUIRE(graph->vertexExists("D"));
  REQUIRE(graph->vertexExists("E"));
  REQUIRE(!graph->vertexExists("F"));
  REQUIRE(!graph->vertexExists("G"));
  REQUIRE(graph->edgeExists("E", "D"));
  REQUIRE(graph->edgeExists("D", "E"));
  REQUIRE(!graph->edgeExists("C", "E"));
  REQUIRE(!graph->edgeExists("E", "C"));
  REQUIRE(graph->edgeExists("A", "B"));
  REQUIRE(graph->edgeExists("B", "A"));
  delete graph;
}

TEST_CASE("BFS", "[BFS]") {
  // ECTION("Can use sections") {}
  std::vector<std::vector<std::string>> result = readCSV("testing.csv");
  Graph* graph = toGraph(result);
  BFS b(graph, "A");
  //std::cout << "works";
  REQUIRE(b.NextVertex() == "A");
  REQUIRE(b.NextVertex() == "C");
  REQUIRE(b.NextVertex() == "B");
  REQUIRE(b.NextVertex() == "D");
  //cout << b.NextVertex() << endl;
  REQUIRE(b.NextVertex() == "E");
  REQUIRE(b.NextVertex() == "");
  //REQUIRE(graph->vertexExists("A"));
  
  delete graph;
}


TEST_CASE("first iteration", "[pagerank]") {
  // SECTION("Can use sections") {}
  std::vector<std::vector<std::string>> file = readCSV("testing.csv");
  PageRank run;
  run.integrate(file);
  run.algorithm(1);
  std::map<std::string, double> check = run.getOriginal();
  REQUIRE(check["A"] == (.2/3) + (.2/2));
  REQUIRE(check["B"] == (.2/3) + (.2/2));
  REQUIRE(check["C"] == (.2/2) + (.2/2) + (.2/2));
  REQUIRE(check["D"] == (.2/3) + (.2/1));
  REQUIRE(check["E"] == (.2/2));
}

TEST_CASE("ranks add up", "[pagerank]") {
  // SECTION("Can use sections") {}
  std::vector<std::vector<std::string>> file = readCSV("testing.csv");
  PageRank run;
  run.integrate(file);
  run.algorithm(1);
  std::map<std::string, double> check = run.getOriginal();
  double ranks = (check["A"] + check["B"] + check["C"] + check["D"] + check["E"]);
  bool pass = false;
  if (ranks >= 0.995 && ranks <= 1.005) {
    pass = true;
  }
  REQUIRE(pass);
}

TEST_CASE("ranks add up | multiple iterations", "[pagerank]") {
  // SECTION("Can use sections") {}
  std::vector<std::vector<std::string>> file = readCSV("testing.csv");
  PageRank run;
  run.integrate(file);
  run.algorithm(20);
  std::map<std::string, double> check = run.getOriginal();
  double ranks = (check["A"] + check["B"] + check["C"] + check["D"] + check["E"]);
  bool pass = false;
  if (ranks >= 0.995 && ranks <= 1.005) {
    pass = true;
  }
  REQUIRE(pass);
}

TEST_CASE("ranks add up | floatSurfer", "[pagerank]") {
  // SECTION("Can use sections") {}
  std::vector<std::vector<std::string>> file = readCSV("testing.csv");
  PageRank run;
  run.integrate(file);
  run.floatSurfer(0.85);
  std::map<std::string, double> check = run.getSurferCount();
  double ranks = (check["A"] + check["B"] + check["C"] + check["D"] + check["E"]);
  bool pass = false;
  if (ranks >= 0.995 && ranks <= 1.005) {
    pass = true;
  }
  REQUIRE(pass);
}