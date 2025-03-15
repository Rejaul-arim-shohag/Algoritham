#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        string S, T;
        cin >> S >> T;

        int n = S.length(), m = T.length();
        vector<long long> dp(m + 1, 0);
        dp[0] = 1;
        for (char c : S)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (c == T[j])
                {
                    dp[j + 1] += dp[j];
                }
            }
        }

        cout << dp[m] << endl;
    }

    return 0;
}
