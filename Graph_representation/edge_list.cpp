#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main()
{
    int n, e; // node and edge
    cin >> n >> e;
    vector<pair<int, int> > edge_list;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        edge_list.push_back(make_pair(a, b));
    }
    cout << "Output" << endl;
    for (pair<int, int> p : edge_list)
    {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}