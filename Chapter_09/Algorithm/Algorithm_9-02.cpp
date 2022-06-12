/*
Page 441
Algorithm 9.2 Horner's rule

Algorithm Horner(A, n, v)
{
    s = an;
    for(i = n -1 to 0 step -1 do)
    {
        s = s * v + a[i];
    }
}
*/
#include <iostream>
using namespace std;

// returns value of poly[0]x(n-1) + poly[1]x(n-2) + .. + poly[n-1]
int horner(int poly[], int n, int x)
{
    int result = poly[0]; // Initialize result

    // Evaluate value of polynomial using Horner's method
    for (int i = 1; i < n; i++)
        result = result * x + poly[i];

    return result;
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
Value of polynomial is 5
*/