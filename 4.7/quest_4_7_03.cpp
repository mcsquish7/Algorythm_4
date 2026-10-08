#include <iostream>
#include <fstream>

using namespace std;

bool dfs(int **matrix, bool *visited, int n, int v, int parent)
{
    visited[v] = true;
    for (int i = 0; i < n; i++)
    {
        if (matrix[v][i] == 1)
        {
            if (!visited[i])
            {
                if (dfs(matrix, visited, n, i, v))
                {
                    return true;
                }
            }
            else if (i != parent)
            {
                return true;
            }
        }
    }
    return false;
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

    bool hasCycle = false;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (dfs(matrix, visited, n, i, -1))
            {
                hasCycle = true;
                break;
            }
        }
    }

    if (hasCycle)
    {
        cout << "В графе есть цикл!" << endl;
    }
    else
    {
        cout << "В графе нет циклов" << endl;
    }

    for (int i = 0; i < n; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] visited;

    return 0;
}