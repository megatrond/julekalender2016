#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>

#include <limits>

static std::vector<std::vector<int>> triangle;

static void read(std::string file) {
    std::ifstream f(file);

    std::string line;
    while (std::getline(f, line)) {
        std::stringstream ss(line);

        triangle.emplace_back();
        int value;
        while (ss >> value) {
            triangle.back().emplace_back(value);
        }
    }
}

static int replacementA() {
    std::vector<std::vector<int>> t = triangle;

    for (std::size_t row = t.size() - 2; row < std::numeric_limits<std::size_t>::max(); row--) {
        std::size_t row_columns = row + 1;
        for (std::size_t column = 0; column < row_columns; column++) {
            t[row][column] += std::max(t[row + 1][column], t[row + 1][column + 1]);
        }
    }

    return t[0][0];
}

static int replacementB() {
    std::vector<std::vector<int>> t = triangle;

    std::size_t steps = triangle.size();
    for (std::size_t column = 1; column < steps; column++) {
        for (std::size_t row = (steps - 1); row >= column; row--) {
            t[row][column] += std::max(t[row][column - 1], t[row - 1][column - 1]);
        }
    }

    return t.back().back();
}

static int replacementC() {
    std::vector<std::vector<int>> t = triangle;

    std::size_t steps = triangle.size();
    for (std::size_t step = 1; step < steps; step++) {
        for (std::size_t row = step, column = 0; row < steps; row++, column++) {
            t[row][column] += std::max(t[row - 1][column], t[row][column + 1]);
        }
    }

    return t.back().front();
}

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        std::cout << "Missing input file" << std::endl;
        return 1;
    }

    read(argv[1]);

    std::cout << "A" << replacementA() << std::endl;
    std::cout << "B" << replacementB() << std::endl;
    std::cout << "C" << replacementC() << std::endl;
}
