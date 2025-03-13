#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
bool rearrange(string s1, string s2)
{
    if (s1.length() != s2.length())
        return false;

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    cout << "S1: " << s1 << endl;
    cout << "S2: " << s2 << endl;

    return s1 == s2;
}

int main()
{
    int test_case;
    cin >> test_case;
    while (test_case--)
    {
        string st1, st2;
        cin >> st1 >> st2;
        if (rearrange(st1, st2))
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
