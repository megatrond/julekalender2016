#include <iostream>

#include <cstdint>
#include <cmath>

int main() {
    uint64_t sum = 0;
    uint64_t prev_fib = 1;
    for (uint64_t current_fib = 2; current_fib < 4'000'000'000;) {
        if ((current_fib % 2) == 0) {
            sum += current_fib;
        }

        uint64_t next = current_fib + prev_fib;
        prev_fib = current_fib;
        current_fib = next;
    }
    std::cout << sum << std::endl;

    return 0;
}
