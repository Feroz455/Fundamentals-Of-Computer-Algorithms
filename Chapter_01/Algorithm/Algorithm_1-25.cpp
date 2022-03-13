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
#include <iomanip>
using namespace std;
int const n = 4;
void Mult(int a[][n], int b[][n], int c[][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                c[i][j] = c[i][j] + (a[i][k] * b[k][j]);
            }
        }
    }
    // cout << ci << " " << cj << " " << ck << "\n";
}
void Print(int x[][n])
{
    cout << "\n**********\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << setw(3) << x[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n**********\n";
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
    Print(x);
    Print(y);
    Mult(x, y, z);
    Print(z);
    return 0;
}
/*
output
**********
  4   8   1   3
  1   3   5   2
  4   3   2   2
  0   7   8   2

**********

**********
  5   2   5   9
  8   4   5   0 
  7   1   7   7
  6   8   7   0

**********

**********
109  65  88  43
 76  35  69  44
 70  38  63  50
124  52 105  56 

**********
*/
