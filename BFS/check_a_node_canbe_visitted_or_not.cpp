//EKta node theke r ekta  node a jay kina seta check kortace
#include <iostream>
#include <queue>
using namespace std;
vector<int> adj_list[1005];
bool vis[1005];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    while (!q.empty())
    {
        // ber kore ana
        int parent = q.front();
        q.pop();
        // oi node niye kaj

        // children push kora
        for (int child : adj_list[parent])
        {
            if (vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
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
    memset(adj_list, 0, sizeof(adj_list));
    int src, dst;
    cin >> src >> dst;
    bfs(src);
    if (vis[dst])
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
