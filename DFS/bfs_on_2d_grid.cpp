#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
char grid[105][105];
bool vis[105][105];
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

void bfs(int si, int sj)
{

    queue<pair<int, int> > q;
    q.push(make_pair(si, sj));
    vis[si][sj] = true;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;

        cout << par_i << " " << par_j << endl;
        for (int i = 0; i < 4; i++)
        {
            int ci = par_i + mv[i].first;
            int cj = par_j + mv[i].second;
            if (valid(ci, cj) && !vis[ci][cj])
            {
                q.push(make_pair(ci, cj));
                vis[ci][cj] = true;
            }
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
    int si, sj;
    cin >> si >> sj;
    memset(vis, false, sizeof(vis));
    bfs(si, sj);
    return 0;
}