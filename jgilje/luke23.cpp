#include <iostream>
#include <vector>

#include "boost/multiprecision/cpp_int.hpp"

boost::multiprecision::cpp_int iterate(uint32_t steps, uint32_t options) {
    std::vector<boost::multiprecision::cpp_int> res(steps);
    res[0] = 1;
    res[1] = 2;
    res[2] = 4;

    for (uint32_t i = 3; i <= steps; i++) {
        res.emplace_back(0);
        for (uint32_t j = 1; j <= options; j++) {
            res[i] = res[i] + res[i - j];
        }
    }

    return res[steps - 1];
}

int main() {
    std::cout << iterate(250, 3) << std::endl ;
    return 0;
}
