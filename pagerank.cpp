#include "pagerank.h"

void PageRank::integrate(std::vector<std::vector<std::string>> csv) {
    for (std::vector<std::string> edge : csv) {
        edges[edge[0]].push_back(edge[1]);
        edges[edge[1]].push_back(edge[0]);
    }
    for (auto const& x : edges) {
        original[x.first] = 1.0 / edges.size();
        modified[x.first] = 1.0 / edges.size();
        surferCount[x.first] = 0.0;
        indexs.push_back(x.first);
    }
}

void PageRank::algorithm(int iter) {
    //The more iterations, the more accurate the rank
    int iterations = iter;
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
    unsigned seed = time(0);
    srand(seed);
    int random = rand() % surferCount.size();
    //std::cout << random << std::endl;
    int teleport = 0;
    int iterations = 50;
    std::string store;
    for (int i = 0; i < iterations; i++) {
        store = indexs[random];
        while (teleport <= (int)(d * 100)) {
            surferCount[store] += 1;
            count++;
            int next = rand() % edges[store].size();
            store = edges[store].at(next);
            //std::cout << store << std::endl;
            teleport = (rand() % 100) + 1;
            //std::cout << teleport << std::endl;
        }
        random = rand() % surferCount.size();
        teleport = 0;
    }
    for (auto node : surferCount) {
        double rank = (node.second * 1.0) / (count * 1.0);
        surferCount[node.first] = rank;
    }
}

double PageRank::expressRanks(int alg) {
    double highest = 0;
    std::string highestId;
    if (alg == 1) {
        for (auto node : modified) {
            //std::cout << node.first << " - " << node.second << std::endl;
            if (node.second > highest) {
                highest = node.second;
                highestId = node.first;
            }
        }
        std::cout << "Method 1: Most Important ChannelID - " << highestId << " | Rank - " << highest << std::endl;
        return highest;
    } else {
        double highest = 0;
        for (auto node : surferCount) {
            //std::cout << node.first << " - " << rank << std::endl;
            if (node.second > highest) {
                highest = node.second;
                highestId = node.first;
            }
        }
        std::cout << "Method 2: Most Important ChannelID - " << highestId << " | Rank - " << highest << std::endl;
        return highest;
    }
    
}

std::map<std::string, double> PageRank::getOriginal() {
    return original;
}

std::map<std::string, double> PageRank::getSurferCount() {
    return surferCount;
}

std::map<std::string, std::vector<std::string>> PageRank::getEdges() {
    return edges;
}