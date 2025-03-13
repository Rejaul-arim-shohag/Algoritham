#include <iostream>
using namespace std;
#include <cstring>
int dp[100005];
bool canReach(long long int start, int target)
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

    dp[start] = canReach(start + 3, target) || canReach(start * 2, target);
    return dp[start];
}

int main()
{
    int test_case;
    cin>>test_case;

    while(test_case--){
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
    }
    return 0;
}