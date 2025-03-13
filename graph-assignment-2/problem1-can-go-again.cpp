#include <iostream>
#include <climits>
#include <vector>
using namespace std;

long long int dis[1005];
int n, e;
bool flag = false;

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
            if (dis[a] != LLONG_MAX && dis[a] + c < dis[b])
            {
                dis[b] = dis[a] + c;
            }
        }
    }

    for (auto ed : edge_list)
    {
        int a = ed.a; // from node
        int b = ed.b; // to node
        int c = ed.c; // distance of from node to node
        if (dis[a] != LLONG_MAX && dis[a] + c < dis[b])
        {
            flag = true;
            break;
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
        edge_list.push_back(Edge(a, b, c));
    }

    for (int i = 1; i <= n; i++)
    {
        dis[i] = LLONG_MAX;
    }

    int src;
    cin >> src;
    dis[src] = 0;

    // cout << "OUTPUT" << endl;
    bellman_ford();

    int test_case;
    cin >> test_case;

    if (flag)
    {
        cout << "Negative Cycle Detected" << endl;
    }
    else
    {

        while (test_case--)
        {
            int dst;
            cin >> dst;
            if (dis[dst] == LLONG_MAX)
            {
                cout << "Not Possible" << endl;
            } else{
                cout << dis[dst] << endl;
            }

        }
    }

    return 0;
}