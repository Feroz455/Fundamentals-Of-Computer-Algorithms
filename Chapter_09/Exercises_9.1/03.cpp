/*
Page 439

3) Show the tuples that would result by representing the polynomials
5x^2 + 3x + 10 and 7x+4 values x = 0, 1, 2, 3, 4, 5, 6 .
What set of tuples is sufficient to represent the product of these two polynomials?
*/

#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    for (int i = 0; i <= 6; i++)
    {
        cout << 5 * (pow(i, 2)) + 3 * i + 10 << "\n";
        cout << 7 * i + 4 << "\n";
    }
    return 0;
}
/*
10
4
18
11
36
18
64
25
102
32
150
39
208
46
*/