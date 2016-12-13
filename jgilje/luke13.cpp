#include <iostream>
#include <fstream>
#include <sstream>

#include <string>
#include <unordered_map>

#include <memory>
#include <cstring>

#define COLUMNS 10000
#define ROWS 10000
#define SIZE COLUMNS * ROWS

static std::unordered_map<std::string, int> bank;

struct coord {
    int x = 0;
    int y = 0;
};

coord parse_coord(std::string str) {
    std::stringstream ss(str);
    std::string x, y;
    std::getline(ss, x, ',');
    ss >> y;

    return coord{std::stoi(x), std::stoi(y)};
}

static void turn_on_off(bool* vec, bool val, const coord& from, const coord& to) {
    for (int i = from.y; i <= to.y; i++) {
        for (int j = from.x; j <= to.x; j++) {
            vec[i * COLUMNS + j] = val;
        }
    }
}

static void toggle(bool* vec, const coord& from, const coord& to) {
    for (int i = from.y; i <= to.y; i++) {
        for (int j = from.x; j <= to.x; j++) {
            auto coord = i * COLUMNS + j;
            vec[coord] = !vec[coord];
        }
    }
}

static void read(std::string file) {
    std::unique_ptr<bool[]> lights(new bool[SIZE]);
    std::memset(lights.get(), 0, SIZE);
    std::ifstream f(file);

    std::string command, on_off, from, through, to;
    while (f >> command) {
        if (command == "turn") {
            f >> on_off >> from >> through >> to;
            turn_on_off(lights.get(), on_off == "on", parse_coord(from), parse_coord(to));
        } else if (command == "toggle") {
            f >> from >> through >> to;
            toggle(lights.get(), parse_coord(from), parse_coord(to));
        } else {
            throw std::runtime_error("Unknown command");
        }
    }

    int count = 0;
    for (std::size_t i = 0; i < SIZE; i++) {
        if (lights[i]) {
            count++;
        }
    }

    std::cout << count << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        std::cout << "Missing input file" << std::endl;
        return 1;
    }
    read(argv[1]);

    return 0;
}
