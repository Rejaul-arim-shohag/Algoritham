#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    int can_reach = 1;
    if (T < 3 || T == 5)
    {
        can_reach = -1;
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