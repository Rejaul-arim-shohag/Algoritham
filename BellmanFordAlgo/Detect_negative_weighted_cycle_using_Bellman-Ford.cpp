#include <iostream>
#include <climits>
#include <vector>
using namespace std;
int dis[1005];
int n, e;

class Edge
{
public:
    int a, b, c;
    Edge(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

vector<Edge> edge_list;

void bellman_ford()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (auto ed : edge_list)
        {
            int a = ed.a; // from node
            int b = ed.b; // to node
            int c = ed.c; // distance of from node to node
            if (dis[a] != INT_MAX && dis[a] + c < dis[b])
            {
                dis[b] = dis[a] + c;
            }
        }
    }

    bool flag = false;
    for (auto ed : edge_list)
    {
        int a = ed.a; // from node
        int b = ed.b; // to node
        int c = ed.c; // distance of from node to node
        if (dis[a] != INT_MAX && dis[a] + c < dis[b])
        {
            flag = true;
            break;
        }
    }

    // print
    if (flag)
    {
        cout << "Negative weighted cycle detected" << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << " " << dis[i] << endl;
        }
    }
}

int main()
{

    cin >> n >> e;

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c)); // for directed graph
        // edge_list.push_back(Edge(a, b, c)); // if graph is undirected
    }



    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }
    dis[0] = 0;

    cout << "OUTPUT" << endl;
    bellman_ford();

    return 0;
}