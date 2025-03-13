#include <iostream>
#include <vector>
#include <queue>
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

void bfs(int si, int sj, int di, int dj)
{

    queue<pair<int, int>> q;
    q.push(make_pair(si, sj));
    vis[si][sj] = true;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;

        if (par_i == di && par_j == dj)
        {
            cout << "YES" << endl;
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int ci = par_i + mv[i].first;
            int cj = par_j + mv[i].second;
            if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] != '#')
            {
                q.push(make_pair(ci, cj));
                vis[ci][cj] = true;
            }
        }
    }
    cout << "NO" << endl;
}

int main()
{
    // mv.push_back(make_pair(-1, 0));
    // mv.push_back(make_pair(1, 0));
    // mv.push_back(make_pair(0, -1));
    // mv.push_back(make_pair(0, 1));
    mv = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int si = -1, sj = -1, di = -1, dj = -1;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                si = i;
                sj = j;
            }
            if (grid[i][j] == 'B')
            {
                di = i;
                dj = j;
            }
        }
    }

    memset(vis, false, sizeof(vis));
    if (si == -1 || sj == -1 || di == -1 || dj == -1)
    {
        cout << "NO" << endl;
    }
    else
    {
        bfs(si, sj, di, dj);
    }
    // bfs(si, sj, di, dj);
    return 0;
}