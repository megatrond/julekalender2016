#include <iostream>

#include <bitset>

int main() {
    uint64_t max = 0;
    uint64_t lhs_max = 0;
    uint64_t rhs_max = 0;

    uint32_t values[] = {9,8,7,6,5,4,3,2,1,0};
    for (uint32_t i = 0; i < (1 << 5); i++) {
        auto l_bitset = std::bitset<5>(i);

        uint64_t lhs = values[l_bitset[4] ? 0 : 1] * 10000 + values[l_bitset[3] ? 2 : 3] * 1000
                     + values[l_bitset[2] ? 4 : 5] *   100 + values[l_bitset[1] ? 6 : 7] *   10
                     + values[l_bitset[0] ? 8 : 9];

        uint64_t rhs = values[l_bitset[4] ? 1 : 0] * 10000 + values[l_bitset[3] ? 3 : 2] * 1000
                     + values[l_bitset[2] ? 5 : 4] *   100 + values[l_bitset[1] ? 7 : 6] *   10
                     + values[l_bitset[0] ? 9 : 8];

        if (max < (lhs * rhs)) {
            max = lhs * rhs;
            lhs_max = lhs;
            rhs_max = rhs;
        }
    }

    std::cout << lhs_max << " * " << rhs_max << " = " << max << std::endl;
}
