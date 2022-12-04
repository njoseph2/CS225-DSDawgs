#include "BFS.h"
#include <iostream>
#include <fstream>
#include <unordered_map>

Graph toGraph(std::vector<std::vector<std::string>> csv) {
        Graph g_(false);
        unordered_map<Vertex, bool> added;
        for (auto& row : csv) {
            if (added[row[0]] == false) {
                g_.insertVertex(row[0]);
                added[row[0]] = true;
            }
            if (added[row[1]] == false) {
                    g_.insertVertex(row[1]);
                    added[row[1]] = true;
            } 
            g_.insertEdge(row[0], row[1]);
        }
        return g_;
}