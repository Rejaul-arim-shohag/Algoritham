#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
bool vis[8][8];
int level[8][8];
vector<pair<int, int> > d;
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
    level[si][sj] = 0;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;
        for (int i = 0; i < 8; i++)
        {
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;
            if (valid(ci, cj) && !vis[ci][cj])
            {
                q.push(make_pair(ci, cj));
                vis[ci][cj] = true;
                level[ci][cj] = level[par_i][par_j] + 1;
            }
        }
    }
}

int main()
{
    d.push_back(make_pair(2, -1));
    d.push_back(make_pair(1, -2));
    d.push_back(make_pair(-1, -2));
    d.push_back(make_pair(-2, -1));

    d.push_back(make_pair(-2, 1));
    d.push_back(make_pair(2, 1));
    d.push_back(make_pair(1, 2));
    d.push_back(make_pair(-1, -2));

    int T;
    cin >> T;
    while (T--)
    {
        // n = 8, m = 8;
        // string source, destination;
        // cin >> source >> destination;
        // int si = source[1] - '1';
        // int sj = source[0] - 'a';

        // int di = destination[1] - '1';
        // int dj = destination[0] - 'a';

        // cout << si << " " << sj << endl;
        // cout << dj << " " << dj << endl;

        cin >> n >> m;

        int si, sj, di, dj;
        cin >> si >> sj;
        cin >> di >> dj;

        memset(vis, false, sizeof(vis));
        memset(level, -1, sizeof(level));

        bfs(si, sj);
        cout << level[di][dj] << endl;
    }

    return 0;
}