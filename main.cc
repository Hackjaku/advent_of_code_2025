#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "../models/utilities.h"

using namespace std;

int main() {

    Utilities utils;
    vector<string> lines = utils.ParseInput("../inputs/01.txt");

    int position = 50;
    int zero_counter = 0;

    for (auto& line : lines) {
        // remove first character and save it
        char direction = line[0];
        line = line.substr(1);

        int rotation = stoi(line);

        if (rotation == 0) {
            continue;
        }

        if (direction == 'R') {
            zero_counter += (position + rotation) / 100;
            position = (position + rotation) % 100;
        } else if (direction == 'L') {
            if (rotation >= position) {
                int remaining = rotation - position;
                zero_counter += 1 + (remaining - 1) / 100;
                position = (100 - (remaining % 100)) % 100;
            } else {
                position -= rotation;
                if (position == 0) {
                    zero_counter += 1;
                }
            }
        } else {
            throw runtime_error("Invalid direction character");
        }

    }

    cout << "Final Position: " << position << endl;
    cout << "Zero Crossings: " << zero_counter << endl;

    return 0;
}