#include <iostream>
#include <fstream>

using namespace std;

void dfs(int **matrix, bool *visited, int n, int v, bool &first)
{
    visited[v] = true;
    if (!first)
    {
        cout << " ";
    }
    cout << v + 1;
    first = false;
    for (int i = 0; i < n; i++)
    {
        if (matrix[v][i] == 1 && !visited[i])
        {
            dfs(matrix, visited, n, i, first);
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

    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    cout << "Порядок обхода вершин: ";
    bool first = true;
    dfs(matrix, visited, n, 0, first);
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] visited;

    file.close();
    return 0;
}