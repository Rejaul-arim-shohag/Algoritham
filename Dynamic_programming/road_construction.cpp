#include <iostream>
using namespace std;
int par[100005];
int group_size[100005];
int component_size, largest_component;

// ja input asbe se gulor leader find kore sajiye rakhbo
int find(int node)
{
    if (par[node] == -1)
    {
        return node;
    }
    int leader = find(par[node]);
    par[node] = leader;
    return leader;
}

void dsu_union_by_size(int node1, int node2)
{
    int leader1 = find(node1);
    int leader2 = find(node2);
    if (leader1 == leader2){
        return;
    }
        if (group_size[leader1] >= group_size[leader2])
        {
            par[leader2] = leader1;
            group_size[leader1] += group_size[leader2];
            largest_component = max(largest_component, group_size[leader1]);
        }
        else
        {
            par[leader1] = leader2;
            group_size[leader2] += group_size[leader1];
            largest_component = max(largest_component, group_size[leader2]);
        }
    // protibar unior korer por component ek kore kombe, dorlam 5 ta city ace,
    // jekno duita city ke ek sathe connect kore ekta group kore dilam, tarpr componet hlo
    // oi duita mila ekta r 3 ta, total 4 ta
    component_size--;
}

// void dsu_union_by_size(int node1, int node2)
// {
//     int leader1 = find(node1);
//     int leader2 = find(node2);
//     if (group_size[leader1] >= group_size[leader2])
//     {
//         par[leader2] = leader1;
//         group_size[leader1] += group_size[leader2];
//     }
//     else
//     {
//         par[leader1] = leader2;
//         group_size[leader2] += group_size[leader1];
//     }
// }

int main()
{

    int n, e;
    cin >> n >> e;
    component_size = n;    // surute jto gula city toto gula component, karo sathe sathe karo connection nai
    largest_component = 1; // karo sathe karo connection nai, tai each component is a self component
    // memset(par, -1, sizeof(par));
    // memset(group_size, 1, sizeof(group_size));
    for (int i = 1; i <= n; i++)
    {
        par[i] = -1;
        group_size[i] = 1;
    }
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        dsu_union_by_size(a, b);
        cout << component_size << " " << largest_component << endl;
    }

    return 0;
}