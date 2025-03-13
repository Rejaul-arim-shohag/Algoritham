#include <iostream>
#include <vector>
using namespace std;
char grid[1000][1000];
bool vis[1000][1000];
vector<pair<int, int> > mv;
int n, m;
bool found;
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

void dfs(int si, int sj, int di, int dj)
{
    if (found)
    {
        return;
    }
    vis[si][sj] = true;
    if (si == di && sj == dj)
    {
        found = true;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int ci = si + mv[i].first;
        int cj = sj + mv[i].second;
        if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.')
        {
            dfs(ci, cj, di, dj);
        }
    }
}

int main()
{
    mv.push_back(make_pair(-1, 0));
    mv.push_back(make_pair(1, 0));
    mv.push_back(make_pair(0, -1));
    mv.push_back(make_pair(0, 1));

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    int si, sj, di, dj;
    cin >> si >> sj;
    cin >> di >> dj;
    dfs(si, sj, di, dj);
    if (found)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}