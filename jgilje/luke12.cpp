#include <iostream>
#include <fstream>

#include <regex>
#include <locale>

#include <list>

static void print_roman(int i) {
    switch (i) {
    case 0:
        std::cout << "0";
        break;
    case 1:
        std::cout << "I";
        break;
    case 2:
        std::cout << "II";
        break;
    case 3:
        std::cout << "III";
        break;
    case 4:
        std::cout << "IV";
        break;
    case 5:
        std::cout << "V";
        break;
    case 6:
        std::cout << "VI";
        break;
    case 7:
        std::cout << "VII";
        break;
    case 8:
        std::cout << "VIII";
        break;
    case 9:
        std::cout << "IX";
        break;
    case 10:
        std::cout << "X";
        break;
    case 11:
        std::cout << "XI";
        break;
    case 12:
        std::cout << "XII";
        break;
    case 13:
        std::cout << "XIII";
        break;
    }
}

static void crypt(std::string msg) {
    std::list<int> values;

    std::locale locale;
    std::regex word_regex("[\\w]");
    auto regex_begin = std::sregex_iterator(msg.begin(), msg.end(), word_regex);
    auto regex_end = std::sregex_iterator();

    auto front_it = values.begin();
    for (std::sregex_iterator i = regex_begin; i != regex_end; ++i) {
        auto letter = std::tolower(i->str()[0], locale);
        auto value = static_cast<int>(letter) - 96;
        auto half = value / 2;
        values.insert(front_it, value - half);
        values.insert(front_it, half);
        front_it--;
    }

    auto end_it = --values.cend();
    for (auto it = values.cbegin(); it != end_it; ++it) {
        print_roman(*it);
        std::cout << ", ";
    }

    print_roman(values.back());
    std::cout << std::endl;
}

int main() {
    std::string msg = "Your message was received with gratitude! We do not know about you, but Christmas is definitely our favourite holiday. The tree, the lights, all the presents to unwrap. Could there be anything more magical than that?! We wish you a happy holiday and a happy new year!";
    crypt(msg);

    return 0;
}
