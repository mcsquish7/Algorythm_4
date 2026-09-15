// время O(n), память O(n)
#include <iostream>

using namespace std;

long long fibo(int n, long long* memo)
{
	if (n <= 1)
	{
		return n;
	}
	if (memo[n] != -1) return memo[n];

	memo[n] = fibo(n - 1, memo) + fibo(n - 2, memo);
	return memo[n];
}

int main()
{
	setlocale(LC_ALL, "Russian");
	const int Nmax = 50;
	long long memo[Nmax+1];
	for (int i = 0; i <= Nmax; i++)
	{
		memo[i] = -1;
	}
	cout << "Введите номер числа Фибоначчи: ";
	int n = 1;
	cin >> n;
	if (n > Nmax)
	{
		cout << "Число слишком большое";
		return 1;
	}
	cout << "Число Фибоначчи " << n << " равно " << fibo(n, memo);

	return 0;
}