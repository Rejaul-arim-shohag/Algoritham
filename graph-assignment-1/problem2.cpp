#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, e; // numbers of node and edge
    cin >> n >> e;
    vector<int> adj_list[n];
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        // input niye kothao rakhar jonno addjacency list use korbo
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int q; // numbers of quires
    cin >> q;

    while (q--)
    {
        vector<int> connected_items;
        int X;
        cin >> X;
        for (int x : adj_list[X])
        {
            connected_items.push_back(x);
        }
        if (connected_items.empty())
        {
            cout << -1 << endl;
        }
        else
        {
            sort(connected_items.begin(), connected_items.end(), greater<int>());
            for (size_t i = 0; i < connected_items.size(); i++)
            {
                cout << connected_items[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}