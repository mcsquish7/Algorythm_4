#include <iostream>

using namespace std;

void print_dynamic_array(int* arr, int logical_size, int actual_size)
{
	for (int i = 0; i < actual_size; i++)
	{
		if (i < logical_size)
		{
			cout << arr[i] << " ";
		}
		else
		{
			cout << "_ ";
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Введите фактический размер массива: ";
	int actual_size = 0;
	cin >> actual_size;
	cout << "Введите логический размер размер массива: ";
	int logical_size = 0;
	cin >> logical_size;
	if (logical_size > actual_size)
	{
		cerr << "Ошибка! Логический размер массива не может превышать фактический!";
		return 1;
	}

	int* arr = new int[actual_size];

	for (int i = 0; i < logical_size; i++)
	{
		cout << "Введите arr[" << i << "]: ";
		cin >> arr[i];
	}

	cout << "Динамический массив: ";
	print_dynamic_array(arr, logical_size, actual_size);

	delete[] arr;

	return 0;
}