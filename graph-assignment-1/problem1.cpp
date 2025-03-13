#include <iostream>
#include <vector>
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
    }

    int q; // numbers of quires
    cin >> q;
    while (q--)
    {
        int A, B;
        cin >> A >> B;
        bool found = false;


        if (A == B)
        {
            cout << "YES" << endl;
            continue;
        }
        for (int x : adj_list[A])
        {
            if (x == B)
            {
                found = true;
                break;
            }
        }




        if (found)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}