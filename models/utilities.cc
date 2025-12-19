#include "utilities.h"

std::vector<std::string> Utilities::ParseInput(std::string path) {
    std::vector<std::string> lines;
    std::string line;
    std::fstream data(path, std::ios::in);

    while (std::getline(data, line)) {
        lines.push_back(line);
    }

    return lines;
}