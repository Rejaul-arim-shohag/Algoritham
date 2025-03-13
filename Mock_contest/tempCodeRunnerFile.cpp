#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    int can_reach = -1;
    for (int i = 0; i <= T; i += 3)
    {
        if ((T - i) % 4 == 0)
        {
            can_reach = 1;
        }
    }
    if (can_reach == 1)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}