#include <iostream>
#include <vector>
#include <queue>
#include <cstring> // For memset

using namespace std;

bool vis[105];
vector<int> adj_list[105];
int parent[105]; // Track parent for cycle detection
bool cycle;

void dfs(int src)
{
    vis[src] = true;
    for (int child : adj_list[src])
    {
        // if (vis[child] && parent[src] != child)
        // {
        //     cycle = true;
        // }
        if (vis[child] && parent[src] != child && parent[child] != src) // ✅ Fixed cycle detection
        {
            cycle = true;
        }
        if (!vis[child])
        {
            parent[child] = src;
            dfs(child);

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
            dfs(i);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " Parent " << parent[i] << endl;
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
