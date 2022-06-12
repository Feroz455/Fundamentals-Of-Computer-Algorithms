/*
Page 440

Algorithm 9.1 Straigtforward evaluation
Algorithm straightEval(A, n, v)
{
    r = 1;
    s = a0;
    for(int i = 1; to n do)
    {
        r = r * v;
        s = s + a[i] * r;
    }
    return s;
}
*/
#include <iostream>
using namespace std;

// returns value of poly[0]x(n-1) + poly[1]x(n-2) + .. + poly[n-1]
int horner(int poly[], int n, int x)
{
    int s = poly[0]; // Initialize s
    int r = 1;
    // Evaluate value of polynomial using Horner's method
    for (int i = 1; i < n; i++)
    {
        r = r * x;
        s = s + poly[i] * r;
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
/*
Value of polynomial is -25
*/