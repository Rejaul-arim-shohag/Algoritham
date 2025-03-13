#include <iostream>
#include <queue>
using namespace std;
vector<int> adj_list[1000];
bool vis[1000];
void dfs(int src)
{
    // cout << src << " ";
    vis[src] = true;
    for (int child : adj_list[src])
    {
        if (vis[child] == false)
        {
            dfs(child);
        }
    }
}

int main()
{
    int n, e;
    int number_of_components = 0;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
            number_of_components++;
            // cout<< endl;
        }
    }

    cout << "number_of_components " << number_of_components << endl;

    return 0;
}