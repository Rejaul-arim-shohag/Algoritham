#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<long long> a(N + 5, 0);
    vector<long long> dp(N + 5, 0);
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
        dp[i] = dp[i - 1] + a[i];
    }

    while (Q--)
    {
        int l, r;
        cin >> l >> r;
        cout << dp[r] - dp[l - 1] << endl;
    }
    return 0;
}