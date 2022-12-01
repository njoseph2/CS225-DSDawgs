#pragma once

#include "BFS.h"
#include <iostream>
#include <cstdlib>

class PageRank {
    public:
        void integrate(std::vector<std::vector<std::string>> csv);
        void algorithm();
        double expressRanks();
        std::map<std::string, double> getOriginal();
        void floatSurfer(double d);
    private:
        std::map<std::string, std::vector<string>> edges;
        std::map<std::string, double> surferCount;
        std::map<std::string, double> original;
        std::map<std::string, double> modified;
        std::vector<std::string> indexs;
};