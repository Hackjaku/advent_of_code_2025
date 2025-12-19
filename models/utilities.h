#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <boost/integer/common_factor.hpp>

class Utilities {
public:
    static std::vector<std::string> ParseInput(std::string);
};

#endif // UTILITIES_H