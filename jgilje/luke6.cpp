#include <cstdint>
#include <cstdlib>

#include <vector>

#include <chrono>
#include <iostream>

struct Pos {
    int x = 0;
    int y = 0;

	Pos(int x = 0, int y = 0) : x(x), y(y) {}

    int value() const { return x + y; }
    bool operator==(const Pos& rhs) const {
        return (x == rhs.x) && (y == rhs.y);
    }

    Pos    up_left() const { return Pos{x - 1, y + 2}; }
    Pos   up_right() const { return Pos{x + 1, y + 2}; }
    Pos  down_left() const { return Pos{x - 1, y - 2}; }
    Pos down_right() const { return Pos{x + 1, y - 2}; }

    Pos    left_up() const { return Pos{x - 2, y + 1}; }
    Pos   right_up() const { return Pos{x + 2, y + 1}; }
    Pos  left_down() const { return Pos{x - 2, y - 1}; }
    Pos right_down() const { return Pos{x + 2, y - 1}; }
};

Pos eval(const Pos& pos, const Pos& prev) {
    Pos ret;
    int min_diff = INT32_MAX;
    int current_value = pos.value();

    auto inner_eval = [&](const Pos& p) {
        int value = p.value();
        if (p == prev) {
            if (prev.value() == 1000) {
                std::cout << "prev was 1000\n";
                value = 0;
            } else {
                value = 1000;
            }
        }

        int diff = std::abs(value - current_value);

        if (diff < min_diff) {
            ret = p;
            min_diff = diff;
        } else if (diff == min_diff) {
            if (p.x < ret.x) {
                ret = p;
                min_diff = diff;
            } else if (p.x == ret.x) {
                if (p.y < ret.y) {
                    ret = p;
                    min_diff = diff;
                }
            }
        }
    };

    inner_eval(pos.up_left());
    inner_eval(pos.up_right());
    inner_eval(pos.down_left());
    inner_eval(pos.down_right());

    inner_eval(pos.left_up());
    inner_eval(pos.right_up());
    inner_eval(pos.left_down());
    inner_eval(pos.right_down());

    return ret;
}

int main() {
    std::cout << "(1'000'000'000'000'000 - 1) * (2 + 1) = " << (1'000'000'000'000'000 - 1) * (2 + 1) << std::endl;
    std::cout << "Now, lets start bruteforcing!" << std::endl;

    std::chrono::time_point<std::chrono::system_clock> measure_time;

    Pos pos{0, 0};
    Pos prev = pos;
    measure_time = std::chrono::system_clock::now();
    for (uint64_t i = 0; i < 1'000'000'000'000'000; i++) {
        if ((i % 1'000'000'000) == 0 && i > 0) {
            std::chrono::duration<double> elapsed_seconds = std::chrono::system_clock::now() - measure_time;
            std::cout << i << ", " << elapsed_seconds.count() << std::endl;
            measure_time = std::chrono::system_clock::now();
        }
        Pos next = eval(pos, prev);
        prev = pos;
        pos = next;
    }

    std::cout << prev.x << ":" << prev.y << std::endl;
}
