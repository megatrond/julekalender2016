#include <iostream>

#include <vector>
#include <algorithm>

std::vector<uint64_t*> process(std::vector<uint64_t*>& in) {
    std::vector<uint64_t*> out;

    for (auto i : in) {
        auto s = std::to_string(*i);
        auto it = std::find(s.cbegin(), s.cend(), '7');
        if (it != s.cend()) {
            out.emplace_back(i);
            *i = out.size();
        } else if ((*i % 7) == 0) {
            out.emplace_back(i);
            *i = out.size();
        }
    }

    return out;
}

int main(int argc, char* argv[]) {
    std::vector<uint64_t> numbers(1400);
    std::vector<uint64_t*> working_vector(numbers.size());

    for (uint64_t i = 0; i < numbers.size(); i++) {
        numbers[i] = i + 1;
        working_vector[i] = &numbers[i];
    }

    while (working_vector.size() > 0) {
        working_vector = process(working_vector);
    }

    std::cout << numbers[1336] << std::endl;
    return 0;
}
