#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
char grid[35][35];
bool vis[35][35];
int level[35][35];
vector<pair<int, int> > mv;
int n;
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= n)
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
        for (int i = 0; i < 4; i++)
        {
            int ci = par_i + mv[i].first;
            int cj = par_j + mv[i].second;
            if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] != 'T')
            {
                q.push(make_pair(ci, cj));
                vis[ci][cj] = true;
                level[ci][cj] = level[par_i][par_j] + 1;
            }
        }
    }
}
// For each input set output single integer i.e.minimum number of moves from S to E.

int main()
{
    mv.push_back(make_pair(-1, 0));
    mv.push_back(make_pair(1, 0));
    mv.push_back(make_pair(0, -1));
    mv.push_back(make_pair(0, 1));

    int si, sj, di, dj;
    while (cin >> n) // jtobar amra input nicci totobar aey loop ta chalabo, karo question bola ace Input is terminated by EOF.
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
                if (grid[i][j] == 'S')
                {
                    si = i;
                    sj = j;
                }

                if (grid[i][j] == 'E')
                {
                    di = i;
                    dj = j;
                }
            }
        }
        memset(vis, false, sizeof(vis));
        memset(level, -1, sizeof(level));
        bfs(si, sj);
        cout << level[di][dj] << endl;
    }

    return 0;
}