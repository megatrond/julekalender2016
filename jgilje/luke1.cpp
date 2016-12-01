#include <iostream>

#include <cstdint>
#include <cmath>

int main() {
    for (uint64_t tester = 16; tester < UINT64_MAX; tester += 10) {
        uint64_t log = static_cast<uint64_t>(std::log10(tester));
        uint64_t shifted = (tester / 10) + (static_cast<uint64_t>(std::pow(10.0, log)) * 6);

        if ((tester * 4) == shifted) {
            std::cout << tester << std::endl;
            break;
        }
    }

    return 0;
}
