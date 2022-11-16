#pragma once

#include <vector>
#include "BFS.h"

class PageRank {
    public:
        void integrate();
        void algorithm();
    private:
        std::vector<std::pair<Vertex, double>> original;
        std::vector<std::pair<Vertex, double>> modified;
};