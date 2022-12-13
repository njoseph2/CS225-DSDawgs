#include "CSV.h"
#include "pagerank.h"
#include "FDG.h"
#include "visualize.h"

#include "cs225/PNG.h"

int main() {
    std::vector<std::vector<std::string>> file;
    // COMMENT THIS IF YOU WANT TO TO RUN THE TWITCH DATASET
    file = readCSV("testing.csv");

    // UNCOMMENT BELLOW CODE IF YOU WANT TO RUN THE TWITCH DATASET (TAKES A LONG TIME TO RUN)
    //file = readCSV("large_twitch_edges.csv");

    PageRank run;
    run.integrate(file);
    run.algorithm(20);
    run.floatSurfer(0.85);
    run.expressRanks(1);
    run.expressRanks(2);
    
    FDG forces;
    forces.nodes.resize(run.getEdges().size());
    int count = 0;
    std::map<std::string, int> indices;
    double size = run.getOriginal().size() * 1.0;
    for (auto x : run.getOriginal()) {
        indices[x.first] = count;
        forces.nodes[count].name = x.first;
        forces.nodes[count].rank = x.second;
        forces.nodes[count].x = double(std::rand()) / (double(RAND_MAX) + 1.0) * size;
        forces.nodes[count].y = double(std::rand()) / (double(RAND_MAX) + 1.0) * size;
        count++;
    }
    for (std::pair<std::string, std::vector<std::string>> const& x : run.getEdges()) {
        std::vector<int> vec;
        for (std::string edge : x.second) {
            vec.push_back(indices[edge]);
        }
        forces.nodes[indices[x.first]].neighbors = vec;
    }
    for (unsigned i = 0; i < 30; i++ ) {
        forces.updatePositions();
    }
    for (unsigned i = 0; i < forces.nodes.size(); i++) {
        std::cout << "Channel: " << forces.nodes[i].name << " | x: " << forces.nodes[i].x << "| y: " << forces.nodes[i].y << std::endl;
    }
    return 1;

};