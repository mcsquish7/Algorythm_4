#include <iostream>
#include <string>

int find_substring_light_rabin_karp(std::string source, std::string substring)
{
    int n = source.length();
    int m = substring.length();
    if (m > n)
        return -1;
    int sub_hash = 0;
    for (int i = 0; i < m; i++)
    {
        sub_hash += (int)substring[i];
    }
    int win_hash = 0;
    for (int i = 0; i < m; i++)
    {
        win_hash += (int)source[i];
    }
    for (int i = 0; i <= n - m; i++)
    {
        if (win_hash == sub_hash)
        {
            bool match = true;
            for (int j = 0; j < m; j++)
            {
                if (source[i + j] != substring[j])
                {
                    match = false;
                    break;
                }
            }
            if (match)
                return i;
        }
        if (i < n - m)
        {
            win_hash = win_hash - (int)source[i] + (int)source[i + m];
        }
    }
    return -1;
}

int main()
{
    std::string source;
    std::cout << "Введите строку, в которой будет осуществляться поиск: ";
    std::getline(std::cin, source);
    std::string substring;
    do
    {
        std::cout << "Введите подстроку, которую нужно найти: ";
        std::getline(std::cin, substring);
        int index = find_substring_light_rabin_karp(source, substring);
        if (index != -1)
        {
            std::cout << "Подстрока " << substring << " найдена по индексу " << index << std::endl;
        }
        else
        {
            std::cout << "Подстрока " << substring << " не найдена" << std::endl;
        }
    } while (substring != "exit");
    return 0;
}