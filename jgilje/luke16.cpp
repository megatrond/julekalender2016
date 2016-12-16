#include <iostream>
#include <cmath>

#include <vector>
#include <numeric>

int main() {
    for (int i = 1; i < 500000; i++) {
        std::vector<int> numbers;
        int j = i;

        while (j >= 10) {
            numbers.emplace_back(j % 10);
            j = j / 10;
        }
        numbers.emplace_back(j % 10);

        int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
        if (sum == 43) {
            auto sqrt = static_cast<int>(std::sqrt(i));
            if ((sqrt * sqrt) == i) {
                std::cout << i << std::endl;
                break;
            }

            auto cbrt = static_cast<int>(std::cbrt(i));
            if ((cbrt * cbrt * cbrt) == i) {
                std::cout << i << std::endl;
                break;
            }
        }
    }

    return 0;
}
