/*
page 12
1. Horner's rule is a means for evaluating a polynomial at a point x0 using
minimum number of multiplicaion. If the polynomial is
A(x) = an x^n + an-1 x^n-1 + an-2 x^n-3 + an-4 x^n-4 + ....... + a1x + a0;
Horner's rule is
A(x0) = (....(anx0+an-1)x0 +  . . . . + a1)x0 + a0

*/
#include <iostream>
#include<cmath>
using namespace std;
int Horner_Rule(int poly[], int N, int x)
{
    int result = poly[0];
    for (int i=1; i<N; i++)
        result = result*x + poly[i];
    return result;
}
int main()
{
    int N , x, sum = 0;
    cin >> N;
    int A[N];
    for (int i = 0; i < N ; i++)
    {
        cin >> A[i];
    }
    cout << "Enter Value of x\n";
    cin >> x;
    cout << "\nSUM = " << Horner_Rule(A, N, x);
    return 0; 
}
/*
output
***run 1***
4 
-1
2
-6
2
Enter Value of x
3

SUM = 5

*****run 2***
4
1 3 0 2
Enter Value of x
2

SUM = 23
5
3 2 8 9 1
Enter Value of x
2

SUM = 115
*/
