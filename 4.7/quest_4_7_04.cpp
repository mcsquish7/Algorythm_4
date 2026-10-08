#include <iostream>
#include <fstream>

using namespace std;

void dfs(int **matrix, int *component, int n, int v, int comp)
{
    component[v] = comp;
    for (int i = 0; i < n; i++)
    {
        if (matrix[v][i] == 1 && component[i] == 0)
        {
            dfs(matrix, component, n, i, comp);
        }
    }
}

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

    int *component = new int[n];
    for (int i = 0; i < n; i++)
    {
        component[i] = 0;
    }

    int compCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (component[i] == 0)
        {
            compCount++;
            dfs(matrix, component, n, i, compCount);
        }
    }

    cout << "Принадлежность вершин компонентам связности:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << " - " << component[i] << endl;
    }
    cout << "Количество компонентов связности в графе: " << compCount << endl;

    for (int i = 0; i < n; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] component;

    return 0;
}