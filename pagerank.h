#pragma once

#include "BFS.h"
#include <iostream>

class PageRank {
    public:
        void integrate(std::vector<std::vector<std::string>> csv);
        void algorithm();
        double expressRanks();
    private:
        std::map<std::string, std::vector<string>> edges;
        std::map<std::string, double> original;
        std::map<std::string, double> modified;
};