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
        original[x.first] = 1.0 / edges.size();
        modified[x.first] = 1.0 / edges.size();
        surferCount[x.first] = 0;
        indexs.push_back(x.first);

        // std::cout << x.first << " (";
        // for (std::string relation : x.second) {
        //     std::cout << relation;
        // }
        // std::cout << ") - " << modified[x.first] << std::endl;
    }
}

void PageRank::algorithm() {
    //The more iterations, the more accurate the rank
    int iterations = 3;
    for (int i = 0; i < iterations; i++) {
        //go through every vertex
        for (auto node : edges) {
            double rank = 0;
            //look at vertex's connections (other nodes)
            for (std::string connections : node.second) {
                //add rank of connections divided by the size of their connections
                rank  += original[connections] / edges[connections].size(); 
            }
            modified[node.first] = rank;
        }
        original = modified;
    }
}

//Implementation of the pagerank surfer model
void PageRank::floatSurfer(double d) {
    int s = surferCount.size();
    int random = rand() % s;
    int teleport = 0;
    int iterations = 20;
    std::string store;
    for (int i = 0; i < iterations; i++) {
        store = indexs[random];
        while (teleport < (int)(d * 100)) {
            surferCount[store] += 1;
            int next = rand() % edges[indexs[random]].size();
            int count = 0;
            store = edges[indexs[random]].at(next);
            teleport = (rand() % 100) + 1;
        }
        random = rand() % s;
    }
}

double PageRank::expressRanks() {
    double highest = 0;
    std::string highestId;
    for (auto node : modified) {
        std::cout << node.first << " - " << node.second << std::endl;
        if (node.second > highest) {
            highest = node.second;
            highestId = node.first;
        }
    }
    //std::cout << highestId << std::endl;
    return highest;
}

std::map<std::string, double> PageRank::getOriginal() {
    return original;
}