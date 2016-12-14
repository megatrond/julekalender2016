#include <iostream>

#include <cmath>
#include <set>

#include <limits>

static uint64_t factorial(uint64_t n) {
    return (n <= 1) ? 1 : factorial(n - 1) * n;
}

static uint64_t sum_factorial(const std::set<uint64_t>& set) {
    uint64_t sum = 0;
    for (auto i : set) {
        sum += factorial(i);
    }
    return sum;
}

static void print_candidate(const std::set<uint64_t>& set) {
    for (auto z : set) {
        std::cout << z;
    }
    std::cout << std::endl;
}

int main() {
    const double energy = 2.25e32;
    std::set<uint64_t> best_set;
    uint64_t min_factorial_sum = std::numeric_limits<uint64_t>::max();

    for (uint64_t i = 16; i > 0; i--) {
        std::set<uint64_t> set = {i};

        double now = std::pow(i, i);
        for (uint64_t j = i-1; j > 0; j--) {
            if (set.count(j) == 0) {
                double next = now * std::pow(j, j);
                if (next > energy) {
                    auto copy = set;
                    copy.insert(j);

                    auto sum = sum_factorial(copy);
                    if (sum < min_factorial_sum) {
                        best_set = copy;
                        min_factorial_sum = sum;
                    }

                    continue;
                } else {
                    now = next;
                    set.insert(j);
                }
            }
        }
    }

    // because for some reason, knowit wanted there
    // to be an even amount
    if ((best_set.size() % 2) == 1) {
        best_set.insert(1);
    }

    print_candidate(best_set);
    return 0;
}
