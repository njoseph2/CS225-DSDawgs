#include "CSV.h"

std::vector<std::vector<std::string>> readCSV(const std::string & file) {
    std::ifstream channels;
    channels.open(file);
    std::vector<std::vector<std::string>> result;

    if (channels.fail()) {
        std::cout << "bad file" << std::endl;
        return result;
    }

    //goes until end of file
    bool first = true;
    std::string id;
    while (std::getline(channels, id, '\n')) {
        if (!first) {
            std::vector<std::string> vec;
            std::string token;
            std::string delimiter = ",";
            size_t pos = 0;
            while ((pos = id.find(delimiter)) != std::string::npos) {
                token = id.substr(0 ,pos);
                vec.push_back(token);
                id.erase(0,pos + delimiter.length());
            }
            vec.push_back(id);
            result.push_back(vec);
        } else {
            first = false;
        }
    }

    for (auto a : result) {
        for (auto b : a) {
            std::cout << b << std::endl;
        }
        std::cout << "NEXT" << std::endl;
    }
    std::cout << "END" << std::endl;
    return result;
}

Graph* toGraph(std::vector<std::vector<std::string>> csv) {
        Graph* g_ = new Graph(false);
        unordered_map<Vertex, bool> added;
        for (auto& row : csv) {
            if (added[row[0]] == false) {
                g_->insertVertex(row[0]);
                added[row[0]] = true;
            }
            if (added[row[1]] == false) {
                    g_->insertVertex(row[1]);
                    added[row[1]] = true;
            } 
            g_->insertEdge(row[0], row[1]);
        }
        return g_;
}