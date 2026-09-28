#include <iostream>

bool equals(const char* a, const char* b) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) return false;
        ++i;
    }
    return a[i] == '\0' && b[i] == '\0';
}
// Вывод исходного массива
void print_array(const int* arr, int size) {
    std::cout << "Исходный массив:";
    for (int i = 0; i < size; ++i) {
        std::cout << ' ' << arr[i];
    }
    std::cout << std::endl;
}

void print_element(const int* arr, int size, int index) {
    if (index == 0) {
        std::cout << "0 root " << arr[0] << std::endl;
        return;
    }
    int parent = (index - 1) / 2;

    int level = 0;
    int idx = index;
    while (idx > 0) {
        idx = (idx - 1) / 2;
        ++level;
    }

    if (index % 2 == 1) {
        std::cout << level << " left(" << arr[parent] << ") " << arr[index] << std::endl;
    }
    else {
        std::cout << level << " right(" << arr[parent] << ") " << arr[index] << std::endl;
    }
}

void print_pyramid(const int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        print_element(arr, size, i);
    }
}

void travel(const int* arr, int size) {
    int current = 0;
    char command[20];
    while (true) {
        std::cout << "Вы находитесь здесь: ";
        print_element(arr, size, current);
        std::cout << "Введите команду: ";
        std::cin >> command;
        if (equals(command, "exit")) {
            break;
        }
        else if (equals(command, "up")) {
            if (current == 0) {
                std::cout << "Ошибка! Отсутствует родитель" << std::endl;
            }
            else {
                current = (current - 1) / 2;
                std::cout << "Ок" << std::endl;
            }
        }
        else if (equals(command, "left")) {
            int left = 2 * current + 1;
            if (left < size) {
                current = left;
                std::cout << "Ок" << std::endl;
            }
            else {
                std::cout << "Ошибка! Отсутствует левый потомок" << std::endl;
            }
        }
        else if (equals(command, "right")) {
            int right = 2 * current + 2;
            if (right < size) {
                current = right;
                std::cout << "Ок" << std::endl;
            }
            else {
                std::cout << "Ошибка! Отсутствует правый потомок" << std::endl;
            }
        }
        else {
            std::cout << "Ошибка! Неизвестная команда" << std::endl;
        }
    }
}
int main() {
    setlocale(LC_ALL, "Russian");
    // int arr[] = {94, 67, 18, 44, 55, 12, 6, 42};
    // int arr[] = {16, 11, 9, 10, 5, 6, 8, 1, 2, 4};
    int arr[] = { 1, 3, 6, 5, 9, 8 };
    int size = sizeof(arr) / sizeof(arr[0]);
    print_array(arr, size);
    std::cout << "Пирамида:" << std::endl;
    print_pyramid(arr, size);
    travel(arr, size);
    return 0;
}
