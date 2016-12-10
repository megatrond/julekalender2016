#include <iostream>

#include <vector>
#include <string>

struct Player {
    std::string name;
    int kill_count = 0;
    int killed_in_room = -1;
    bool alive = true;
};

int main() {
    std::vector<Player> players = {
        {"Thief", 1}, {"Wizard", 10}, {"Warrior", 1}, {"Priest", 0}
    };
    int priest_ressurected_in_room = -1;

    int goblins = 1;
    int total_goblin_count = 0;
    for (int i = 1; i <= 100; ) {
        // rule 1 - 3
        for (const auto& player : players) {
            if (player.alive) {
                goblins -= player.kill_count;
            }
        }

        // rule 4
        if (players[3].alive) {
            if (priest_ressurected_in_room != i) {
                auto resurrect = [&](auto& player) {
                    player.alive = true;
                    player.killed_in_room = -1;
                    priest_ressurected_in_room = i;
                };

                if (players[2].killed_in_room == i) {
                    resurrect(players[2]);
                } else if (players[1].killed_in_room == i) {
                    resurrect(players[1]);
                }
            }
        }

        // rule 5
        int alive_count = 0;
        for (auto& player : players) {
            if (player.alive) {
                alive_count++;
            }
        }
        if (alive_count == 1) {
            total_goblin_count += goblins;

            goblins = ++i;
            continue;
        }

        // rule 6
        if (goblins >= (alive_count * 10)) {
            auto kill_player = [&](auto& player) {
                player.alive = false;
                player.killed_in_room = i;
            };

            if (players[2].alive) {
                kill_player(players[2]);
            } else if (players[1].alive) {
                kill_player(players[1]);
            } else if (players[3].alive) {
                kill_player(players[3]);
            }
        }

        // rule 7
        if (goblins <= 0) {
            goblins = ++i;
        }
    }
    std::cout << "Total survivors: " << total_goblin_count + 17 + 1 << "\n";

    return 0;
}
