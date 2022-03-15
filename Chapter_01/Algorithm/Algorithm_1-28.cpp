/*
Page 72

Prime0(n, a)
// Returns true if n is a prime and false otherwise.
// a is the probability parameter.
{
    q:= n - 1;
    for i :=1 to large do // Specify large.
    m := 9; y := 1; a := Random() mod q + 1;
    // Choose a random number in the range [1, n – 1].
    z := a;
    // Compute a^n-1 mod n.
    while (m > 0) do
    {
        while (m mod 2 = 0) do
    {
    z := z^2 mod n;
    m:= [m/2);
    m:= m - 1;
    y := (y * z) mod n;
    if (y != 1) then return false;
    // If a^n-1 mod n is not 1, n is not a prime.
    return true;
}

*/
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
// Returs true if n is a prime and false otherwise
// a is the probability Parameter
bool Prime0(int n, int a)
{
    srand(time(0));
    int q = n - 1, m, y, z, A;
    for (int i = 1; i < a; i++)
    {
        m = q;
        y = 1;
        A = rand() % (q + 1);
        // choose a random number in the range [1,n-1];
        z = A;
        // Compute a^n-1 mode n
        while (m > 0)
        {
            while (m % 2 == 0)
            {
                z = (z * z) % n;
                m = floor(m / 2);
            }
            m = m - 1;
            y = (y * z) % n;
        }
        if (y != 1)
            return false;
        // If a^n-1 mod n is not 1, n is not a prime
    }
    return true;
}
int main()
{
    int k = 3;
    Prime0(11, k) ? cout << " true\n" : cout << " false\n";
    Prime0(15, k) ? cout << " true\n" : cout << " false\n";
}
/*
true
false
*/
