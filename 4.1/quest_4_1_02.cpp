#include <iostream>

using namespace std;

int find(int* arr, const int size, int point)
{
	int count = 0;
	int left = 0, right = size;
	
	while (left < right)
	{
		int mid = (left + right) / 2;

		if (arr[mid] <= point)
		{
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
	}

	return size - left;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	const int size = 11;
	int arr[size] = {14, 14, 16, 19, 32, 32, 32, 56, 69, 72, 72};
	cout << "Введите точку отсчёта: ";
	int point = 0;
	cin >> point;

	cout << "\nКоличество элементов в массиве больших, чем " << point << ": " << find(arr, size, point);

	return 0;
}