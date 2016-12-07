#include <iostream>
#include <fstream>

#include <string>
#include <unordered_map>
#include <unordered_set>

#include <algorithm>

struct Position {
    int x = 0;
    int y = 0;
};
static Position position;

static void read(std::string file) {
    std::ifstream f(file);

    std::string walk, str_amount, meters, direction;
    while (f >> walk >> str_amount >> meters >> direction) {
        if (walk != "walk") {
            throw std::runtime_error("Unknown command");
        }
        if (meters != "meters") {
            throw std::runtime_error("Unknown quantity");
        }

        auto amount = std::stoi(str_amount);
        if (direction == "north") {
            position.x += amount;
        } else if (direction == "south") {
            position.x -= amount;
        } else if (direction == "west") {
            position.y += amount;
        } else if (direction == "east") {
            position.y -= amount;
        } else {
            throw std::runtime_error("Unknown direction");
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        std::cout << "Missing input file" << std::endl;
        return 1;
    }

    read(argv[1]);
    std::cout << position.x << "," << position.y << std::endl;

    return 0;
}
