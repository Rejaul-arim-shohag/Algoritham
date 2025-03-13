#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    vector<pair<int, int>> adj_list[n];

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj_list[a].push_back(make_pair(b, c));
        adj_list[b].push_back(make_pair(a, c)); // for undirect graph
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (pair<int, int> p : adj_list[i])
        {
            cout << p.first << " " << p.second << " ";
        }
        cout << endl;
    }
    return 0;
}