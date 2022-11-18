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
    std::string id;
    while (std::getline(channels, id, '\n')) {
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