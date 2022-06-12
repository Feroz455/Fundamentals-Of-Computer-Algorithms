/*
Page 442
Algorithm 9.5 Horner's rule for a sparse represetation

Algorithm SHorner(A, m, v)
{
    s = e[0] = 0;
    for(i = m, to 1 step -1 do)
    {
        s = (s+A[i]) * pow(v,e[i]- e[i-1]);
    }
}
*/
#include <iostream>
#include <cmath>
using namespace std;
int e[] = {2, 4, 6, 8};
// returns value of poly[0]x(n-1) + poly[1]x(n-2) + .. + poly[n-1]
int horner(int poly[], int n, int x)
{
    int s = e[0] = 0; // Initialize s
    int r = 1, t = 1;
    // Evaluate value of polynomial using Horner's method
    for (int i = 1; i < n; i++)
    {
        s = (s + poly[i]) * pow(x, e[i] - e[i - 1]);
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