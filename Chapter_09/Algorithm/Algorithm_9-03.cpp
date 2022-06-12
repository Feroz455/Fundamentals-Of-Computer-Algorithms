/*
Page 441
Algorithm 9.3 Sparse evaluation

Algorithm SStraightEval(A,m,v)
//Sparse stright forward evaluation
// m is number of nonzero terms
{
    s = 0;
    for(i = 1 to m do)
    {
        s = s + a[i] * power(v,e[i]);
    }
return s;

}
*/
#include <iostream>
#include <cmath>
using namespace std;
int e[] = {2, -6, 2, -1};
// returns value of poly[0]x(n-1) + poly[1]x(n-2) + .. + poly[n-1]
int horner(int poly[], int n, int x)
{
    int s = poly[0]; // Initialize s
    int r = 1;
    // Evaluate value of polynomial using Horner's method
    for (int i = 1; i < n; i++)
    {
        s = s + poly[i] * pow(r, e[i]);
    }

    return s;
}

// Driver program to test above function.
int main()
{
    // Let us evaluate value of 2x3 - 6x2 + 2x - 1 for x = 3
    int poly[] = {2, -6, 2, -1};

    int x = 3;
    int n = sizeof(poly) / sizeof(poly[0]);
    cout << "Value of polynomial is " << horner(poly, n, x);
    return 0;
}