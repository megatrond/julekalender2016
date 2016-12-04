#include <iostream>

#include <vector>
#include <algorithm>

bool is_special(uint64_t i) {
    if (std::to_string(i).find('7') != std::string::npos) {
        return true;
    } else if ((i % 7) == 0) {
        return  true;
    }

    return false;
}

int main() {
    std::vector<uint64_t> numbers;

    for (uint64_t i = 1, j = 0; i <= 1337; i++) {
        if (is_special(i)) {
            numbers.emplace_back(numbers[j++]);
        } else {
            numbers.emplace_back(i);
        }
    }

    std::cout << numbers.back() << std::endl;
    return 0;
}
