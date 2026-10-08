#include <iostream>
#include <fstream>

using namespace std;

void dfs(int **matrix, bool *visited, int n, int v, int *result, int &index)
{
    visited[v] = true;
    for (int i = 0; i < n; i++)
    {
        if (matrix[v][i] == 1 && !visited[i])
        {
            dfs(matrix, visited, n, i, result, index);
        }
    }
    result[index] = v + 1;
    index++;
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

    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    int *result = new int[n];
    int index = 0;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(matrix, visited, n, i, result, index);
        }
    }

    cout << "Топологический порядок вершин: ";
    for (int i = n - 1; i >= 0; i--)
    {
        cout << result[i];
        if (i > 0)
        {
            cout << " ";
        }
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] visited;
    delete[] result;

    return 0;
}