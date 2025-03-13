#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    set<char> res;
    for(char ch:s){
        res.insert(ch);
    }
    for (char ch : res)
    {
        std::cout << ch;
    }
    return 0;
}