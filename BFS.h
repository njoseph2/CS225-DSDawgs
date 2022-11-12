#include <vector>
#include <map>
#include <string>

#include "graph.h"
class BFS {
    public:
        BFS();
        Graph readFile(std::string file);
    private:
        std::map<std::string, int> distance;
};