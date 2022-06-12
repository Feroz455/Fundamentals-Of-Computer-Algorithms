/*
Page 9.7 
Algorithm Iterpolate(X, Y, n, G)
//Assume n >= 2. X[1:n] and Y[1:n] are the 
//n pairs of points. The unique interpolating 
//Polunomial of degree < n is returned in G
{
    //D is a polynomial
    G = Y[1]; // G begains as a constant
    D = x - X[1]; // D is a linear polynomial
    for(j = 2; to n do )
    {
        denom = Horner(D, j -1, X[j]); // Evaluate D at X[J];
        num = Horner(G, j - 2, X[j]); // Evalute G at X[j] 
        G = G + (D * Y[j] - num)/denom;
        D = D * (x - X[j]);
    }

} 
*/

#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    int n, i, j;
    float x[10], f[10], a, sum = 0, mult;
    cout << "No of sample points ? ";
    cin >> n;
    cout << "\nAll x with corresponding f(x) ";
    for (i = 0; i < n; i++)
        cin >> x[i] >> f[i];
    cout << "\nEnter x for calculation ";
    cin >> a;

    for (j = 0; j < n - 1; j++)
    {
        for (i = n - 1; i > j; i--)
            f[i] = (f[i] - f[i - 1]) / (x[i] - x[i - j - 1]);
    }
    for (i = n - 1; i >= 0; i--)
    {
        mult = 1;
        for (j = 0; j < i; j++)
            mult *= (a - x[j]);

        mult *= f[j];
        sum += mult;
    }
    cout << "The result is: " << sum;
    return 0;
}
