#include <iostream>
#include <fstream>

#include <string>
#include <unordered_map>

#include <algorithm>

static std::unordered_map<std::string, int> bank;

static void read(std::string file) {
    std::ifstream f(file);

    std::string from, to, str_amount;
    while (std::getline(f, from, ',') && std::getline(f, to, ',') && std::getline(f, str_amount)) {
        int amount = std::stoi(str_amount);
        bank[from] -= amount;
        bank[to] += amount;
    }
}

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        std::cout << "Missing input file" << std::endl;
        return 1;
    }
    read(argv[1]);

    int count = 0;
    for (const auto& it : bank) {
        if (it.second > 10) count++;
    }
    std::cout << count << std::endl;

    return 0;
}
