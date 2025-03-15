#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    int test_case;
    cin >> test_case;

    while (test_case--)
    {
        int n;
        cin >> n;

        vector<int> a(n - 2);
        long long sum;

        long long b = 0;

        for (int i = 0; i < n - 2; ++i)
        {
            cin >> a[i];
            b += a[i];
        }

        cin >> sum;

        long long sum_deleted = sum - b;

        cout << sum_deleted + 1 << endl;
    }

    return 0;
}
