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
    while (channels.peek() != EOF) {
        std::string id;
        std::vector<std::string> vec;
        while (std::getline(channels, id, ',')) {
            vec.push_back(id);
        }
        result.push_back(vec);
    }
    return result;
}