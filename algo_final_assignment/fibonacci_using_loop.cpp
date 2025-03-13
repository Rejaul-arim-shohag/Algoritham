#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long int fibo[n + 1];
    fibo[0] = 0;
    fibo[1] = 1;
    fibo[2] = 1;
    fibo[3] = 2;
    for (int i = 4; i <= n; i++)
    {
        fibo[i] = fibo[i - 1] + fibo[i - 2] + fibo[i - 3] + fibo[i - 4];
    }
    cout << fibo[n] << endl;
    return 0;
}