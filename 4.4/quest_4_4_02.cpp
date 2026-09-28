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
	cout << endl;
}

void append_to_dynamic_array(int*& arr, int& logical_size, int& actual_size, int value)
{
	if (logical_size == actual_size)
	{
		actual_size += logical_size;
		int* new_arr = new int[actual_size];
		for (int i = 0; i < logical_size; i++)
		{
			new_arr[i] = arr[i];
		}
		delete[] arr;
		arr = new_arr;
	}
	arr[logical_size] = value;

	logical_size++;
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
	int value = 1;
	while(true)
	{
		cout << "Введите элемент для добавления: ";
		cin >> value;
		if (value == 0)
		{
			cout << "Спасибо! Ваш массив: ";
			print_dynamic_array(arr, logical_size, actual_size);
			break;
		}
		append_to_dynamic_array(arr, logical_size, actual_size, value);
		print_dynamic_array(arr, logical_size, actual_size);
	}
	
	delete[] arr;

	return 0;
}