#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<pair<int, int> > d;
int n, m;

bool vis[100][100];
int level[100][100];

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
    d.push_back(make_pair(-1, 2));

    int T;
    cin >> T;
    while (T--)
    {

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

// #include <iostream>
// #include <utility>
// #include <vector>
// #include <queue>
// #include <cstring>

// using namespace std;

// vector<pair<int, int> > d;
// int n, m;

// bool vis[100][100];
// int level[100][100];

// bool valid(int i, int j)
// {
//     if (i < 0 || i >= n || j < 0 || j >= m)
//     {
//         return false;
//     }
//     else
//     {
//         return true;
//     }
// }

// int bfs(int si, int sj, int di, int dj)
// {
//     queue<pair<int, int> > q;
//     q.push(make_pair(si, sj));
//     vis[si][sj] = true;
//     level[si][sj] = 0;
//     while (!q.empty())
//     {
//         pair<int, int> par = q.front();
//         q.pop();
//         int par_i = par.first;
//         int par_j = par.second;

//         if (par_i == di && par_j == dj)
//         {
//             return level[par_i][par_j];
//         }
//         for (int i = 0; i < 8; i++)
//         {
//             int ci = par_i + d[i].first;
//             int cj = par_j + d[i].second;
//             if (valid(ci, cj) && !vis[ci][cj])
//             {
//                 q.push(make_pair(ci, cj));
//                 vis[ci][cj] = true;
//                 level[ci][cj] = level[par_i][par_j] + 1;
//             }
//         }
//     }
//     return -1;
// }

// int main()
// {
//     d.push_back(make_pair(2, -1));
//     d.push_back(make_pair(1, -2));
//     d.push_back(make_pair(-1, -2));
//     d.push_back(make_pair(-2, -1));

//     d.push_back(make_pair(-2, 1));
//     d.push_back(make_pair(2, 1));
//     d.push_back(make_pair(1, 2));
//     d.push_back(make_pair(-1, 2));

//     int T;
//     cin >> T;
//     while (T--)
//     {

//         cin >> n >> m;

//         int si, sj, di, dj;
//         cin >> si >> sj;
//         cin >> di >> dj;

//         memset(vis, false, sizeof(vis));
//         memset(level, -1, sizeof(level));

//         cout << bfs(si, sj, di, dj) << endl;

//         // bfs(si, sj, di, dj);
//         // cout << level[di][dj] << endl;
//     }

//     return 0;
// }