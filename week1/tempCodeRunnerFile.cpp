#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string text;

    std::getline(std::cin, text, '\0');

    for (char& c : text) {
        c = std::toupper(c);
    }

    std::cout << text << std::endl;

    return 0;
}
