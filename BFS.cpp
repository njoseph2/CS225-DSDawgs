#include "BFS.h"
#include <iostream>
#include <fstream>
#include <unordered_map>

 BFS::BFS(Graph* g, Vertex s): g_(g), q(), start(s), step(false), printed(false) {
    
 }

void BFS::PrintTraversal() {
    if (step) {
        std::cout << "Currently in step by step traversal" << std::endl;
    }
    printed = true;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        Vertex curr = q.front();
        q.pop();
        vector<Vertex> neighbors = g_-> getAdjacent(curr);
        for (Vertex& v: neighbors) {
            if (!visited[v]) { 
                q.push(v);
                visited[v] = true;
            }
        }
        std::cout << curr << std::endl;
    }
}

Vertex BFS::NextVertex() {
    if (printed) {
        std::cout << "Printed Traversal" << std::endl;
        return "";
    }
    if (q.empty() && step) {
        std::cout << "Finished" << std::endl;
        return "";
    }
    if (q.empty()) {
        q.push(start);
        visited[start] = true;
    }
    step = true;
    Vertex curr = q.front();
    q.pop();
    vector<Vertex> neighbors = g_->getAdjacent(curr);
    for (Vertex& v: neighbors) {
        if (!visited[v]) { 
            q.push(v);
            visited[v] = true;
        }
    }
    return curr;
      
}