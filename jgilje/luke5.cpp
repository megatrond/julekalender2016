#include <iostream>
#include <fstream>

#include <regex>

#include <vector>

static std::vector<int> values;

static void read(std::string file) {
    std::ifstream f(file);

    std::string a;
    while (std::getline(f, a)) {
        std::regex word_regex("[IVX0]+");
        auto regex_begin = std::sregex_iterator(a.begin(), a.end(), word_regex);
        auto regex_end = std::sregex_iterator();

        for (std::sregex_iterator i = regex_begin; i != regex_end; ++i) {
            std::smatch match = *i;
            auto str = match.str();
            int value = 0;
            char prev = 0;

            auto str_it = str.cbegin();
            while (str_it != str.cend()) {
                switch (*str_it) {
                case 'I':
                    value += 1;
                    break;
                case 'V':
                    if (prev == 'I') {
                        value += 3;
                    } else {
                        value += 5;
                    }
                    break;
                case 'X':
                    if (prev == 'I') {
                        value += 8;
                    } else {
                        value += 10;
                    }
                    break;
                case '0':
                    break;
                default:
                    std::cout << "Unknown char: " << *str_it << std::endl;
                    break;
                }

                prev = *str_it;
                ++str_it;
            }

            values.emplace_back(value);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        std::cout << "Missing input file" << std::endl;
        return 1;
    }

    read(argv[1]);

    for (std::size_t i = 0, j = values.size() - 1; i < (values.size() / 2); i++, j--) {
        std::cout << static_cast<char>(96 + values[i] + values[j]);
    }
    std::cout << std::endl;

    return 0;
}
