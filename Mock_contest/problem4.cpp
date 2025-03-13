#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];


    sort(a.begin(), a.end(), greater<long long>());

    long long total = 0;

    long long prev = INT_MAX;


    for (int i = 0; i < n; i++)
    {

        long long pick = min(a[i], prev - 1);
        if (pick < 0)
            pick = 0;
        total += pick;
        prev = pick;
    }

    cout << total << "\n";
    return 0;
}
