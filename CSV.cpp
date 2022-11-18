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
        while (std::getline(channels, id, '\n')) {
            std::cout << id << std::endl;
            std::string token;
            std::string delimiter = ",";
            size_t pos = 0;
            while ((pos = id.find(delimiter)) != std::string::npos) {
                token = id.substr(0,pos);
                std::cout << token << std::endl;
                vec.push_back(token);
                id.erase(0,pos+delimiter.length());
            }
            result.push_back(vec);
            std::cout << "NEXT" << std::endl;
        }
        result.push_back(vec);
    }
    return result;
}