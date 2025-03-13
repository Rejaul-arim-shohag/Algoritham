#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
char grid[1000][1000];
bool vis[1000][1000];
vector<pair<int, int>> mv;
int n, m;
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void dfs(int si, int sj)
{
    // cout << si << " " << sj << endl;
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        // int ci, cj;
        int ci = si + mv[i].first;
        int cj = sj + mv[i].second;

        if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.')
        {
            dfs(ci, cj);
        }
    }
}

int main()
{
    mv.push_back(make_pair(-1, 0));
    mv.push_back(make_pair(1, 0));
    mv.push_back(make_pair(0, -1));
    mv.push_back(make_pair(0, 1));
    // int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    memset(vis, false, sizeof(vis));
    int numbers_of_components = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == false && grid[i][j] == '.')
            {
                dfs(i, j);
                numbers_of_components++;
            }
        }
    }
    cout << numbers_of_components << endl;
    return 0;
}