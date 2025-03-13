#include <iostream>
using namespace std;
int dp[10005];
bool canReach(int start, int target)
{
    if (start == target)
    {
        return true;
    }

    if (start > target)
    {
        return false;
    }

    if (dp[start] != -1)
    {
        return dp[start];
    }

    dp[start] = canReach(start + 5, target) || canReach(start * 4, target);
    return dp[start];
}

int main()
{
    int target;
    cin >> target;

    memset(dp, -1, sizeof(dp));
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