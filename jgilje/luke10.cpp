#include <iostream>

#include <vector>
#include <string>

struct Player {
    Player(int kill_count) : kill_count(kill_count) {}

    int kill_count = 0;
    int killed_in_room = -1;
    bool alive = true;
};

#define THIEF 0
#define WIZARD 1
#define WARRIOR 2
#define PRIEST 3

int main() {
    std::vector<Player> players = {
        {1}, {10}, {1}, {0}
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
        if (players[PRIEST].alive) {
            if (priest_ressurected_in_room != i) {
                auto resurrect = [&](auto& player) {
                    player.alive = true;
                    player.killed_in_room = -1;
                    priest_ressurected_in_room = i;
                };

                if (players[WARRIOR].killed_in_room == i) {
                    resurrect(players[WARRIOR]);
                } else if (players[WIZARD].killed_in_room == i) {
                    resurrect(players[WIZARD]);
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

            if (players[WARRIOR].alive) {
                kill_player(players[WARRIOR]);
            } else if (players[WIZARD].alive) {
                kill_player(players[WIZARD]);
            } else if (players[PRIEST].alive) {
                kill_player(players[PRIEST]);
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
