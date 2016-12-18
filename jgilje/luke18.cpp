#include <iostream>

#include <chrono>

int main() {
    // max illum: 20:08:08
    // min illum:  1:11:11

    using namespace std::chrono_literals;
    auto min_time =  1h + 11min + 11s;
    auto max_time = 20h +  8min +  8s;

    auto diff = max_time - min_time;
    std::cout << std::chrono::duration_cast<std::chrono::hours>(diff).count() << ":"
              << std::chrono::duration_cast<std::chrono::minutes>(diff % std::chrono::hours(1)).count() << ":"
              << std::chrono::duration_cast<std::chrono::seconds>(diff % std::chrono::minutes(1)).count()
              << std::endl;
    return 0;
}
