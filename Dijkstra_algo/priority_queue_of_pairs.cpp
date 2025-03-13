#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(10, 1));
    pq.push(make_pair(5, 2));

    cout << pq.top().first << " " << pq.top().second;
    return 0;
}