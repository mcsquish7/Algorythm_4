#include <iostream>
#include <string>

int simple_string_hash(std::string s) {
    int sum = 0;
    for (int i = 0; i < s.length(); i++) {
        sum += (int)s[i];
    }
    return sum;
}

int main() {
    std::string s;
    do {
        std::cout << "Введите строку: ";
        std::getline(std::cin, s);
        std::cout << "Наивный хэш строки " << s << " = " << simple_string_hash(s) << std::endl;
    } while (s != "exit");
    return 0;
}