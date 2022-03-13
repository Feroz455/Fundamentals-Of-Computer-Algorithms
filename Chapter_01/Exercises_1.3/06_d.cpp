/*
page 60
Algorthm 1.25 Matrix multiplication

Algorithm Mult(a,b,c,n)
{
    for i:=1 to n do
        for j := 1 to n do
            {
                c[i][j] = 0;
                for k:=1 to n do
                    c[i][j] = c[i][j] + (a[i][k] * b[k][j]);
            }
}


Do exercise 4 for transpose (Algorithm 1.25);
a) Introduce statements to inctement count at all appropriate points in algorithm 1.25
b) Simplify the resulting algorithm by eleminating statements. The simplified algorithm should
compute the same value for count as compute bu the algorithm of part (a);
c) what is the exact value of count when the algorithm terminates, you may assume that the initail value
of count is 0;
d) Obtain the step cunt for algorithm 1.23 using the frequency method, Clearly show the step count table;
Algorithm Transpose(a,n)
*/
#include <iostream>
#include <ctime>
#include<cmath>
using namespace std;
int const n = 4;
int Mult(int a[][n], int b[][n], int c[][n])
{
    int count = 0;
    for(int i = 1; i < n; i++)
    count += pow(n,i);

    return count;
}
int main()
{
    srand(time(0));
    int x[n][n], y[n][n], z[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            x[i][j] = rand() % 10;
            y[i][j] = rand() % 10;
        }
    }

    cout << "Number of operation -> " << Mult(x, y, z) << " \n";
    return 0;
}
/*
Number of operation -> 84 
*/
