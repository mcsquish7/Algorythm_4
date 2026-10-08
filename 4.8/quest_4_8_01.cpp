#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream file("input.txt");
    int n;
    file >> n;

    int **matrix = new int *[n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            file >> matrix[i][j];
        }
    }
    file.close();

    cout << "Текстовый вид орграфа:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ": ";
        bool found = false;
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 1)
            {
                if (found)
                {
                    cout << " ";
                }
                cout << j + 1;
                found = true;
            }
        }
        if (!found)
        {
            cout << "нет";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}