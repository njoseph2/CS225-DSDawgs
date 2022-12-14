#pragma once

#include "BFS.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

class PageRank {
    public:
        void integrate(std::vector<std::vector<std::string>> csv);
        void algorithm(int iter);
        double expressRanks(int alg);
        std::map<std::string, double> getOriginal();
        std::map<std::string, double> getSurferCount();
        std::map<std::string, std::vector<std::string>> getEdges();
        void floatSurfer(double d);
    private:
        std::map<std::string, std::vector<string>> edges;
        std::map<std::string, double> surferCount;
        std::map<std::string, double> original;
        std::map<std::string, double> modified;
        std::vector<std::string> indexs;
        int count = 0;
};