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

    bool *visited = new bool[n];
    int *queue = new int[n];

    while (true)
    {
        cout << "В графе " << n << " вершин. Введите номер вершины, с которой начнётся обход: ";
        int start;
        cin >> start;

        if (cin.fail())
            break;

        if (start < 1 || start > n)
        {
            cout << "Недопустимый номер вершины. Попробуйте снова." << endl;
            continue;
        }

        for (int i = 0; i < n; i++)
        {
            visited[i] = false;
        }

        int head = 0;
        int tail = 0;
        int s = start - 1;

        queue[tail] = s;
        tail++;
        visited[s] = true;

        cout << "Порядок обхода вершин: ";
        bool first = true;

        while (head < tail)
        {
            int v = queue[head];
            head++;

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
                    visited[i] = true;
                    queue[tail] = i;
                    tail++;
                }
            }
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] visited;
    delete[] queue;

    return 0;
}