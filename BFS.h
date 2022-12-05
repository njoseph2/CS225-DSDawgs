#pragma once

#include <vector>
#include <map>
#include <queue>
#include <string>

#include "graph.h"
using namespace std;
class BFS
{
    public:
        BFS(Graph* g, Vertex s);
        void PrintTraversal();
        Vertex NextVertex();

    private:
        Graph* g_;
        queue<Vertex> q;
        Vertex start;
        unordered_map<Vertex, bool> visited;
        bool step, printed;
};