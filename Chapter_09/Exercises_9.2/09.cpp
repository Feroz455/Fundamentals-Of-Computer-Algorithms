#include <iostream>
#include <cmath>
using namespace std;
int e[] = {2, 4, 6, 8};
int poly[] = {2, -6, 2, -1};
int PMult(int r, int s, int t)
{
    t = r * s;
}
// returns value of poly[0]x(n-1) + poly[1]x(n-2) + .. + poly[n-1]
int horner(int n, int x)
{
    int s = poly[0]; // Initialize s
    int r = 1, t = 1;
    // Evaluate value of polynomial using Horner's method
    for (int i = 1; i < n; i++)
    {
        r = pow(x, (e[i] - e[i - 1]));
        t = t * r;
        s = s + poly[i] * t;
    }

    return s;
}

// Driver program to test above function.
int main()
{
    // Let us evaluate value of 2x3 - 6x2 + 2x - 1 for x = 3

    int x = 3;
    int n = sizeof(poly) / sizeof(poly[0]);
    cout << "Value of polynomial is " << horner(n, x);
    return 0;
}