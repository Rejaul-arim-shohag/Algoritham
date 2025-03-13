#include <iostream>
using namespace std;
long long int dp[1005]; // dp means dynamic programming
long long int fibonacci(long long int n)
{
    if (n < 2)
    {
        return n;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return dp[n];
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cout << fibonacci(5) << endl;
    return 0;
}