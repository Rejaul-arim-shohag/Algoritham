#include <iostream>
#include <vector>
#include <limits>
#include <queue>

using namespace std;

vector<pair<int, int> > adj_list[105];
vector<int> dis(105, INT_MAX);

void dijkstra(int src)
{
    queue<pair<int, int> > q;
    q.push(make_pair(src, 0)); // surute manually source er distance 0 tai, (src and 0)
    // vis[src]=true; no nee to maintain visited array
    dis[src] = 0; // manually src er distance ta 0;

    while (!q.empty())
    {
        // ber kore
        pair<int, int> par = q.front();
        q.pop();
        int parent_node = par.first;
        int parent_distance = par.second;

        // dfs a oi node niye kaj,but dijkstra te print kora kaj na,
        // oi node er distance calculate kora amdr kaj,jeta amra allready korteci so eta aladavbe kora lagbena

        // childer gulo k push
        for (pair<int, int> child : adj_list[parent_node])
        {

            int child_node = child.first;
            int child_distance = child.second;

            // main changes is hear, bfs a check kora hto kno child visited ace kina,
            // but dijkstra te check korbo path relaxation kora jay kina
            // jodi kora jay tahole seta k queue the push korbo and tar distance ke update korbo

            if (parent_distance + child_distance < dis[child_node])
            {
                dis[child_node] = parent_distance + child_distance;
                q.push(make_pair(child_node, dis[child_node]));
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
        int a, b, c;
        cin >> a >> b >> c;
        adj_list[a].push_back(make_pair(b, c));
        adj_list[b].push_back(make_pair(a, c));
    }

    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }

    dijkstra(0);


    //source theke sob gulo node jaoer distance ekhon print hobe,
    cout << "OUTPUT" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << dis[i] << endl;
    }

    // ekhane jodi bola hoy source theke 3 number index a jaoer sortest distance kto
    // tahole just dis[3] print kore dilye hobe
    //abr jodi bole 3 theke 1 er jaoer sortest ditance kto tahole 3 k source shorbo
    return 0;
}