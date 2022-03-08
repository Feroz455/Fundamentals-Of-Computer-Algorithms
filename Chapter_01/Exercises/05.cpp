/*
The factorial funtion n! has a value 1 when n <= 1 and value n*(n-1)! when
n > 1. Write both a recursive and an iterative algorithm to compute n!
*/
#include <iostream>
using namespace std;
int fact(int A)
{
    if (A <= 0)
    {
        return 1;
    }
    else
        return (A * fact(A - 1));
}
int fact_norecursive(int A)
{
    int temp = 1;
    if (A <= 0)
    {
        return 1;
    }
    else
    {
        for (int i = 1; i <= A; i++)
        {
            temp = temp * i;
        }
    }
    return temp;
}
int main()
{
    int A;
    cin >> A;
    cout << A << "! recursive = " << fact(A) << " \n";
    cout << A << "! Non recursive = " << fact_norecursive(A);
    return 0;
}
/*
output
10
10! recursive = 3628800    
10! Non recursive = 3628800
*/