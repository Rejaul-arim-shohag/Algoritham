#include <iostream>
using namespace std;
bool canReach(int n, int target)
{
    if (n == target)
    {
        return true;
    }

    if (n > target)
    {
        return false;
    }
    // bool left = canReach(n + 5, target);
    // bool right = canReach(n * 4, target);
    // return left || right;

    return canReach(n + 5, target) || canReach(n * 4, target);
}

int main()
{
    int target;
    cin >> target;
    if (canReach(1, target))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}