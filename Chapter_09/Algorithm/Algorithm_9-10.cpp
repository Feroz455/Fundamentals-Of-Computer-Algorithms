/*
page 460
Algorithm 9.10 Algorithm to compute the gcd of two numbers

Algorithm GCD(a,b)
//assumed a > b >= 0
{
    if (b != 0)
    {
        return GCD(b, a%b);
    }
    else
    return a;

}
*/
#include <iostream>
using namespace std;
int GCD(int a, int b)
// assumed a > b >= 0
{
    if (b != 0)
    {
        return GCD(b, a % b);
    }
    else
        return a;
}
int main()
{
    cout << GCD(22,8);
    return 0;
}
/*
2
*/