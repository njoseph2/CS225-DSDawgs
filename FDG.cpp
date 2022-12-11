#include "FDG.h"

// Computes the attractive force between two nodes
double FDG::attractiveForce(const Node& a, const Node& b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    double d = dx * dx + dy * dy;
    return kAttraction * d;
}

// Computes the repulsive force between two nodes
double FDG::repulsiveForce(const Node& a, const Node& b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    double d = dx * dx + dy * dy;
    return kRepulsion / d;
}

// Updates the positions of all nodes based on their forces
void FDG::updatePositions()
{
    for (int i = 0; i < nodes.size(); i++)
    {
        Node& a = nodes[i];
        double fx = 0;
        double fy = 0;

        // compute the repulsive forces from all other nodes
        for (int j = 0; j < nodes.size(); j++)
        {
            if (i == j) continue; // skip the current node

            Node& b = nodes[j];

            // only consider nodes with a lower rank
            if (b.rank >= a.rank) continue;

            double f = repulsiveForce(a, b);
            fx += f * (a.x - b.x);
            fy += f * (a.y - b.y);
        }

        // compute the attractive forces from all neighboring nodes
        for (int j : a.neighbors)
        {
            Node& b = nodes[j];
            double f = attractiveForce(a, b);
            fx -= f * (a.x - b.x);
            fy -= f * (a.y - b.y);
        }

        // update the node's position based on the forces
        a.x += fx;
        a.y += fy;
        // create boundary for the canvas
        if (a.x > kMaxDistance) { a.x = kMaxDistance; }
        if (a.x < kMinDistance) { a.x = kMinDistance; }
        if (a.y > kMaxDistance) { a.y = kMaxDistance; }
        if (a.y < kMinDistance) { a.y = kMinDistance; }
    }
}