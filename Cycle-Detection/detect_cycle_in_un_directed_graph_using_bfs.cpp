// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;
// bool vis[105];
// vector<int> adj_list[105];

// int parent[105]; // track parent for cycle ditection
// bool cycle;
// void bfs(int src)
// {
//     queue<int> q;
//     q.push(src);
//     vis[src] = true;
//     while (!q.empty())
//     {
//         int par = q.front();
//         q.pop();
//         // cout << par << endl;
//         for (int child : adj_list[par])
//         {
//             if (vis[child] && parent[par] != child)
//             {
//                 cycle = true;
//             }
//             if (!vis[child])
//             {
//                 q.push(child);
//                 vis[child] = true;
//             }
//         }
//     }
// }
// int main()
// {
//     int n, e;
//     cin >> n >> e;

//     while (e--)
//     {
//         int a, b;
//         cin >> a >> b;
//         adj_list[a].push_back(b);
//         adj_list[b].push_back(a);
//     }
//     memset(vis, false, sizeof(vis));
//     memset(parent, -1, sizeof(parent));
//     cycle = false;
//     for (int i = 0; i < n; i++)
//     {
//         if (!vis[i])
//         {
//             bfs(i);
//         }
//     }
//     if (cycle)
//     {
//         cout << "Cycle detected" << endl;
//     } else{
//         cout << "No cycle" << endl;
//     }
//     return 0;
// }

#include <iostream>
#include <vector>
#include <queue>
#include <cstring> // For memset

using namespace std;

bool vis[105];
vector<int> adj_list[105];
int parent[105]; // Track parent for cycle detection
bool cycle = false;

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;


    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (int child : adj_list[par])
        {
            if (vis[child] && parent[par] != child)
            {
                cycle = true;
            }
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                parent[child] = par; // ✅ Fix: Assign parent before pushing into queue
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(vis, 0, sizeof(vis));        // ✅ Correct way to reset bool array
    memset(parent, -1, sizeof(parent)); // ✅ Initialize parent array

    cycle = false;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            bfs(i);
        }
    }

    if (cycle)
    {
        cout << "Cycle detected" << endl;
    }
    else
    {
        cout << "No cycle" << endl;
    }

    return 0;
}
