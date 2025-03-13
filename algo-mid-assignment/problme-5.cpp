#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
char grid[1000][1000];
bool vis[1000][1000];
int level[1000][1000];
pair<int, int> parent[1000][1000];

vector<pair<int, int> > d;
int n, m;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void bfs(int si, int sj)
{
    queue<pair<int, int> > q;
    q.push(make_pair(si, sj));
    vis[si][sj] = true;
    level[si][sj] = 0;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;

        for (int i = 0; i < 4; i++) // c hange direction if necessary
        {
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;
            // change valid check
            if (valid(ci, cj) && !vis[ci][cj] && (grid[ci][cj] == '.' || grid[ci][cj] == 'R' || grid[ci][cj] == 'D'))
            {
                q.push(make_pair(ci, cj));
                vis[ci][cj] = true;
                level[ci][cj] = level[par_i][par_j] + 1;
                // parent[ci][cj] = {par_i, par_j};
                parent[ci][cj] = make_pair(par_i, par_j);
            }
        }
    }
}

int main()
{
    d.push_back(make_pair(0, 1));
    d.push_back(make_pair(0, -1));
    d.push_back(make_pair(-1, 0));
    d.push_back(make_pair(1, 0));
    cin >> n >> m;

    int si, sj, di, dj;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'R')
            {
                si = i;
                sj = j;
            }
            if (grid[i][j] == 'D')
            {
                di = i;
                dj = j;
            }
        }
    }

    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent));
    bfs(si, sj);

    int x = di, y = dj;


    while (x != -1 && y != -1)
    {
        if (grid[x][y] == 'R')
            break;

        if (grid[x][y] != 'D')
             grid[x][y] = 'X';

        pair<int, int> par = parent[x][y];


        if (par.first == -1 || par.second == -1)
            break;

        x = par.first;
        y = par.second;
    }



    // cout << endl << "OUTPUT" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}