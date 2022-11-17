#include "pagerank.h"

void PageRank::integrate(std::vector<std::vector<std::string>> csv) {
    for (std::vector<std::string> edge : csv) {
        edges[edge[0]].push_back(edge[1]);
        edges[edge[1]].push_back(edge[0]);
        // std::string node1 = edge[0];
        // std::string node2 = edge[1];
        // if (edges.find(node1) != edges.end()) {
        //     edges[node1].push_back(node2);
        // } else 
        
        // if (edges.find(node2) != edges.end()) {
        //     edges[node2].push_back(node1);
        // }
    }
    for (auto const& x : edges) {
        original[x.first] = 1 / edges.size();
        modified[x.first] = 1 / edges.size();
    }
}

void PageRank::algorithm() {

}