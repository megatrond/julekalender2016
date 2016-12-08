#include <iostream>
#include <fstream>

#include <string>
#include <vector>
#include <unordered_map>

static std::unordered_map<int, int> ladders = {
    {3, 17}, {8, 10}, {15,44}, {22,5}, {39,56}, {49,75}, {62,45}, {64,19}, {65,73}, {80,12}, {87,79}
};

struct Player {
    int position = 1;
};
static std::vector<Player> players(1337);

static void read(std::string file) {
    std::ifstream f(file);


    std::size_t i = 0;
    std::size_t ladder_use = 0;
    std::string str_roll;
    while (f >> str_roll) {
        int roll = std::stoi(str_roll);
        int new_position = players[i].position + roll;
        if (new_position < 90) {
            if (ladders.count(new_position) > 0) {
                players[i].position = ladders[new_position];
                ladder_use++;
            } else {
                players[i].position = new_position;
            }
        } else if (new_position == 90) {
            break;
        }

        i = (i + 1) % players.size();
    }

    std::cout << ladder_use * (i + 1) << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        std::cout << "Missing input file" << std::endl;
        return 1;
    }
    read(argv[1]);

    return 0;
}
