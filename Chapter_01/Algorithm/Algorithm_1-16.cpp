/*
page 47
Algorithm 1.16 Computation of x^n
Algorithm Exponentiate(x,n); // Return x^n for an integer n >= 0
{
    m := n; power := 1; z = x;
    while(m > 0) do
    {
        while((m mod 2)  = 0) do
        {
            m := floor(m/2); z := z^2
        }
         m := m -1;power := power * power * z;
    }
    return power;
}
*/
#include <iostream>
#include <cmath>
#include<ctime>
using namespace std;
// Return x^n for an integer n >= 0
long Exponnentiate(int x, int n)
{
    long int m = n, power = 1, z = x;
    while (m > 0)
    {
        while ((m % 2) == 0)
        {
            m = floor(m / 2);
            z = pow(z, 2);
        }
        m = m - 1;
        power = power * z;
    }
    return power;
}
int main()
{
    srand(time(0));
    long x, n;
    for (int i = 0; i < 10; i++)
    {
        x = rand()%10;
        n = rand()%10;
        cout << x << "^" << n  << " = " << Exponnentiate(x, n) << "\n";
    }

    getchar();
    return 0;
}
/*
output
6^9 = 10077696
5^8 = 390625  
0^2 = 0       
2^7 = 128     
9^0 = 1       
9^5 = 59049   
5^2 = 25      
9^2 = 81      
3^8 = 6561
4^6 = 4096
*/