#include <iostream>

int main() {
    std::string sequence = "1111321112321111";

    auto transform = [](const std::string& input) {
        std::string output;

        auto it = input.cbegin();
        char c = (*it++);
        int c_count = 1;
        while (it != input.end()) {
            if (*it != c) {
                output += static_cast<char>(c_count + 0x30);
                output += c;

                c = *it;
                c_count = 1;
            } else {
                c_count++;
            }

            ++it;
        }
        output += static_cast<char>(c_count + 0x30);
        output += c;

        return output;
    };

    std::string result = sequence;
    for (int i = 0; i < 50; i++) {
        result = transform(result);
    }
    std::cout << result.length() << std::endl;

    return 0;
}
