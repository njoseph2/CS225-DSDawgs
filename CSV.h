#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include "graph.h"

std::vector<std::vector<std::string>> readCSV(const std::string & file);

Graph* toGraph(std::vector<std::vector<std::string>> csv);