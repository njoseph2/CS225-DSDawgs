#include "CSV.h"
#include "pagerank.h"

int main() {
    std::vector<std::vector<std::string>> file;
    file = readCSV("testing.csv");
    //std::cout << file.size() << std::endl;

    PageRank run;
    run.integrate(file);
    run.algorithm();
    std::cout << run.expressRanks() << std::endl;
    return 0;
};