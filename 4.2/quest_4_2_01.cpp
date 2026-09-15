// время O(2^n), память O(n) - длина самой длинной ветки n в стеке.
#include <iostream>

using namespace std;

int fibo(int n)
{
	if (n <= 2)
	{
		return 1;
	}
	return fibo(n - 1) + fibo(n - 2);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Введите номер числа Фибоначчи: ";
	int n = 1;
	cin >> n;
	cout << "Число Фибоначчи " << n << " равно " << fibo(n);

	return 0;
}