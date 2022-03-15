/*
Page 76
10. Consider the naive Monte Carlo agorithm for primality testing presented in Algorithm 1.31. Here
Power(x,y) computes x^y. What should be the value of t for the algorithm's output to be correct with higher
Probability?
Algorithm Prime1(n)
{
    //Specify t
    for i:=1 to t do
    {
        m:=Power(n,0.5);
        j:=Random() mod % m+2;
        if((n mod j) == 0) then return
        false
        //If j divides n, n is not prime
    }

    return true;
}
*/
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
bool Prime1(int n)
{
    srand(time(0));
    int t = 10, m, j;
    for (int i = 1; i < t; i++)
    {
        m = pow(n, 0.5);
        j = rand() % (m + 2);
        if ((n % j) == 0)
            return false;
    }
    return true;
}
int main()
{
    for (int i = 2; i < 20; i++)
    {
        if (Prime1(i))
            cout << i << " ";
    }
    return 0;
}