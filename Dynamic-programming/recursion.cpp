#include <iostream>
using namespace std;
// using this function we can print 1 to 5 or, 5 to 1;
void printN(int n)
{

    if (n > 5)
    {
        return;
    }
    printN(n + 1);
    cout << n << " ";
}

// some of 1 to 5
int rec_sum(int n)
{
    if (n > 5)
    {
        return 0;
    }

    int sum = rec_sum(n + 1);
    return sum + n;
}

int main()
{
    // printN(1);
    cout << rec_sum(1) << endl;
    return 0;
}