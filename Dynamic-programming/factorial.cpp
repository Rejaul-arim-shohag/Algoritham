#include <iostream>
using namespace std;
int fact(int n)
{
    if (n == 1)
    {
        return 1;
    }
    // jokhn 5 diye call hobe tokhn aey fact(5-1)=4 diye call hobe
    // zehtun n er man 5, so
    // int mul = fact(n - 1); // aey line ta 4 projnto factorial ber kore niye asbe
    // return n * mul;


    //shorcut
    return n * fact(n - 1);
}

int main()
{
    cout << fact(0) << endl;
    return 0;
}