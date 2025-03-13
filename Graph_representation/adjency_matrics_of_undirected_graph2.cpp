#include <iostream>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    int adjacency_matrix[n][n];
    // memset(adjacency_matrix, 0, sizeof(adjacency_matrix));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                adjacency_matrix[i][j] = 1;
            }
            else
            {
                adjacency_matrix[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adjacency_matrix[a][b] = 1;
        adjacency_matrix[b][a] = 1; // for undirected graph connection
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << adjacency_matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}