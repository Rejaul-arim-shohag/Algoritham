
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        string s;
        cin >> s;
        string decoded;
        stringstream ss(s);
        char letter;
        int count;
        while (ss >> letter >> count)
        {
            if (count > 0)
            {
                decoded.append(count, letter);
            }
        }
        cout << decoded << endl;
    }
    return 0;
}