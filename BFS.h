#pragma once

#include <vector>
#include <map>
#include <queue>
#include <string>

#include "graph.h"
class BFS {
    public:
        BFS(std::vector<Vertex> v, Vertex src);
    private:
        int num;
        std::map<Vertex, std::vector<Vertex>> adjacent;
        std::map<Vertex, bool> visited;
        std::queue<Vertex> q;

};