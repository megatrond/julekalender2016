#include <iostream>

std::string convert(int num, int base, int offset) {
    if (num < base) {
        return std::string({static_cast<char>(num + offset)});
    } else {
        return convert(num / base, base, offset) + 
               std::string({static_cast<char>((num % base) + offset)});
    }
}

int main() {
    std::cout << convert(90101894, 26, 64) << std::endl;
    return 0;
}
