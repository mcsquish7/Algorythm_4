#include <iostream>

void print_pyramid(const int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        if (i == 0) {
            std::cout << "0 root " << arr[i] << std::endl;
        }
        else {
            int parent = (i - 1) / 2;
            int level = 0;
            int idx = i;
            while (idx > 0) {
                idx = (idx - 1) / 2;
                ++level;
            }

            if (i % 2 == 1) {
                std::cout << level << " left(" << arr[parent] << ") " << arr[i] << std::endl;
            }
            else {
                std::cout << level << " right(" << arr[parent] << ") " << arr[i] << std::endl;
            }
        }
    }
}
void print_array(const int* arr, int size) {
    std::cout << "Исходный массив:";
    for (int i = 0; i < size; ++i) {
        std::cout << ' ' << arr[i];
    }
    std::cout << std::endl;
}
int main() {
    setlocale(LC_ALL, "Russian");
    int a1[] = { 1, 3, 6, 5, 9, 8 };
    int a2[] = { 94, 67, 18, 44, 55, 12, 6, 42 };
    int a3[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
    int* tests[] = { a1, a2, a3 };
    int sizes[] = { 6, 8, 10 };
    for (int t = 0; t < 3; ++t) {
        print_array(tests[t], sizes[t]);
        std::cout << "Пирамида:" << std::endl;
        print_pyramid(tests[t], sizes[t]);
        std::cout << std::endl;
    }
    return 0;
}
