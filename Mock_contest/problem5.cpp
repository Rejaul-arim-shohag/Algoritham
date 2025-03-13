#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int test_case;
    cin >> test_case;
    while (test_case--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int Mina = 0, Moni = 0;
        sort(v.begin(), v.end(), greater<int>());

        for (int i = 0; i < n; ++i)
        {

            if (Mina <= Moni)
            {
                Mina += v[i];
            }
            else
            {
                Moni += v[i];
            }
        }

        cout << abs(Mina - Moni) << endl;
    }
    return 0;
}
