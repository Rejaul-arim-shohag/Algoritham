// https: // codeforces.com/problemset/problem/20/C
#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <algorithm>

using namespace std;
#define ll long long int

vector<pair<ll, ll>> adj_list[100005];
ll dis[100005];
ll parent[100005];
// vector<ll> dis(105, INT_MAX);

void dijkstra(ll src)
{
    // priority_queue<pair<ll, ll> > pq;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    pq.push(make_pair(0, src));

    dis[src] = 0;

    while (!pq.empty())
    {

        pair<ll, ll> par = pq.top();
        pq.pop();
        ll parent_node = par.second;
        ll parent_distance = par.first;

        for (pair<ll, ll> child : adj_list[parent_node])
        {

            ll child_node = child.first;
            ll child_distance = child.second;

            if (parent_distance + child_distance < dis[child_node])
            {
                dis[child_node] = parent_distance + child_distance;
                pq.push(make_pair(dis[child_node], child_node));
                parent[child_node] = parent_node;
            }
        }
    }
}

int main()
{
    ll n, e;
    cin >> n >> e;
    while (e--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj_list[a].push_back(make_pair(b, c));
        adj_list[b].push_back(make_pair(a, c));
    }

    for (ll i = 1; i <= n; i++)
    {
        dis[i] = LLONG_MAX;
        parent[i] = -1;
    }

    dijkstra(1);
    if (dis[n] == LLONG_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        ll node = n;
        vector<ll> path;
        while (node != -1)
        {
            path.push_back(node);
            node = parent[node];
        }
        reverse(path.begin(), path.end());
        for (auto x : path)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}