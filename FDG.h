#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>

#include "cs225/PNG.h" 
#include "lodepng/lodepng.h" 

using namespace cs225; 

struct Node
{
    std::string name; // node name
    double rank; // node rank
    double x; // x coordinate
    double y; // y coordinate
    std::vector<int> neighbors; // indices of neighboring nodes
};

class FDG {
    public:
        double attractiveForce(const Node& a, const Node& b);
        double repulsiveForce(const Node& a, const Node& b);
        void updatePositions();
        cs225::PNG visualize();

        std::vector<Node> nodes;
    private:
        const double kRepulsion = 4.472135955; // repulsion constant
        const double kAttraction = 4.472135955; // attraction constant
        const double kMaxDistance = 10.0; // max distance constant
        const double kMinDistance = 0.0; // min distance constant
};