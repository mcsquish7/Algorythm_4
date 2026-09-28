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

bool remove_dynamic_array_head(int*& arr, int& logical_size, int& actual_size)
{
	if (logical_size == 0)
	{
		cout << "Невозможно удалить первый элемент, так как массив пустой. До свидания!" << endl;
		return false;
	}
	int new_logical_size = logical_size - 1;
	int threshold = actual_size / 3;
	if (new_logical_size > threshold)
	{
		for (int i = 0; i < new_logical_size; ++i)
			arr[i] = arr[i + 1];
		--logical_size;
	}
	else
	{
		int new_actual_size = actual_size / 3;
		if (new_actual_size < 1) new_actual_size = 1;
		int* new_arr = new int[new_actual_size];

		for (int i = 0; i < new_logical_size; ++i)
			new_arr[i] = arr[i + 1];
		delete[] arr;
		arr = new_arr;
		actual_size = new_actual_size;
		logical_size = new_logical_size;
	}
    return true;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    int actual_size, logical_size;
    cout << "Введите фактичеcкий размер массива: ";
    cin >> actual_size;
    cout << "Введите логический размер массива: ";
    cin >> logical_size;
    if (logical_size > actual_size)
    {
        cout << "Ошибка! Логический размер массива не может превышать фактический!"
            << endl;
        return 1;
    }
    int* arr = new int[actual_size];
    for (int i = 0; i < logical_size; ++i)
    {
        cout << "Введите arr[" << i << "]: ";
        cin >> arr[i];
    }
    cout << "Динамический массив: ";
    print_dynamic_array(arr, logical_size, actual_size);
    while (logical_size >= 0)
    {
        string answer;
        cout << "Удалить первый элемент? ";
        cin >> answer;
        if (answer == "y")
        {
            if (remove_dynamic_array_head(arr, logical_size, actual_size))
            {
                cout << "Динамический массив: ";
                print_dynamic_array(arr, logical_size, actual_size);
            }
            else break;

        }
        else if (answer == "n")
            break;
    }
    if (logical_size != 0)
    {
        cout << "Спасибо! Ваш динамический массив: ";
        print_dynamic_array(arr, logical_size, actual_size);
    }
    delete[] arr;
    return 0;
}
