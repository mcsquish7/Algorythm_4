#include <iostream>
#include <string>

int real_string_hash(std::string s, int p, int n)
{
    unsigned long long sum = 0;
    unsigned long long p_pow = 1;
    for (int i = 0; i < s.length(); i++)
    {
        sum = (sum + (unsigned long long)s[i] * p_pow) % n;
        p_pow = (p_pow * p) % n;
    }
    return (int)sum;
}

int main()
{
    int p, n;
    std::cout << "Введите p: ";
    std::cin >> p;
    std::cout << "Введите n: ";
    std::cin >> n;
    std::cin.ignore();
    std::string s;
    do
    {
        std::cout << "Введите строку: ";
        std::getline(std::cin, s);
        std::cout << "Хэш строки " << s << " = " << real_string_hash(s, p, n) << std::endl;
    } while (s != "exit");
    return 0;
}