#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main()
{
    vector<pair<int, int> > v;

    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }

    cout << "Output" << endl;

    for (pair<int, int> ad : v)
    {
        cout << ad.first << " " << " " << ad.second << endl;
    }
    return 0;
}