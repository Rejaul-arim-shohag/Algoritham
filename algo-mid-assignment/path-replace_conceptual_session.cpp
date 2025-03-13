#include <iostream>
#include <vector>
#include <queue>
using namespace std;
char grid[105][105];
bool vis[105][105];
int level[105][105];
pair<int, int> parent[105][105];

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
void bfs(int si, int sj){
    queue<pair<int , int> > q;
    q.push(make_pair(si, sj));
    vis[si][sj] = true;
    level[si][sj] = 0;
    while(!q.empty()){
        pair<int, int> par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;
        for(int i=0; i<4; i++){
            int ci = par_i+mv[i].first;
            int cj = par_j+mv[i].second;
            if (valid(ci, cj) && !vis[ci][cj] && (grid[ci][cj] == '.' || grid[ci][cj] == 'A'||grid[ci][cj]=='B'))
            {
                q.push(make_pair(ci, cj));
                vis[ci][cj] = true;
                level[ci][cj] = level[par_i][par_j]+1;//add more
                parent[ci][cj] = make_pair(par_i, par_j);
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

    cin >> n >> m;
    int si, sj, di, dj;
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
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent));
    bfs(si, sj);

    cout << parent[4][4].first << " " << parent[4][4].second << endl;
    int x = di, y = dj;

    while (1)
    {
        pair<int, int> par = parent[x][y];
        x = par.first;
        y = par.second;
        if (grid[x][y] == 'A')
        {
            break;
        }
        grid[x][y] = 'o';
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}