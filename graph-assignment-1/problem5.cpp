#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
char grid[1000][1000];
bool vis[1000][1000];
vector<int> component_sizes;
vector<pair<int, int> > mv;
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

int dfs(int si, int sj)
{

    vis[si][sj] = true;
    int count = 1;
    for (int i = 0; i < 4; i++)
    {
        // int ci, cj;
        int ci = si + mv[i].first;
        int cj = sj + mv[i].second;

        if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.')
        {
            int subCount = dfs(ci, cj);
            count = count + subCount;
        }
    }
    return count;
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

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == false && grid[i][j] == '.')
            {
                int num = dfs(i, j);
                component_sizes.push_back(num);
            }
        }
    }

    sort(component_sizes.begin(), component_sizes.end());
    // for (int i = 0; i < component_sizes.size(); i++)
    // {
    //     cout << component_sizes[i] << " ";
    // }
    if (component_sizes.empty())
    {
        cout << 0 << endl;
        return 0;
    }

    for (int num : component_sizes)
    {
        cout << num << " ";
    }

    return 0;
}