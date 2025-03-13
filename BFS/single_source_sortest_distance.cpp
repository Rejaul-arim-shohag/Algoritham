// single source sortest distance ekhane single source kothati mention kora thake,
// karon eta graph, and grpah a multiple source thakte pare, tree te jemon ektai root thake,

// bfs chlaye tar sathe jodi level ta track rakhi taholey source theke protiti node a jaoer shortest distance ber kora jay
// children er level hobe parent er theke 1 beshi
// EKta node theke r ekta  node a jay kina seta check kortace
#include <iostream>
#include <queue>
using namespace std;
vector<int> adj_list[1005];
bool vis[1005];
int level[1005];
int parent[1005];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;
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
                level[child] = level[parent] + 1;
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
    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    int src, dst;
    cin >> src >> dst;
    bfs(src);
    cout << level[dst];
    // for (int i = 0; i < n; i++)
    // {
    //     cout << i << " -> " << level[i] << endl;
    // }

    return 0;
}
