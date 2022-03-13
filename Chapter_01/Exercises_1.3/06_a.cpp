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
using namespace std;
int const n = 4;
int Mult(int a[][n], int b[][n], int c[][n])
{
    int count = 0;
    int ci = 0, cj = 0, ck = 0;
    for (int i = 0; i < n; i++)
    {
        count++;
        ci++;
        for (int j = 0; j < n; j++)
        {
            count++;
            cj++;
            c[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                count++;
                ck++;
                c[i][j] = c[i][j] + (a[i][k] * b[k][j]);
            }
        }
    }
    //cout << ci << " " << cj << " " << ck << "\n";
    return count;
}
void Print(int x[][n])
{
    cout << "\n**********\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << x[i][j] << " ";
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
    cout << "Number of operation -> " << Mult(x, y, z) << " \n";
    Print(z);
    return 0;
}
/*
**********
2 9 4 3   
6 6 3 6   
4 7 9 2   
5 9 9 1   

**********

**********
9 9 8 8   
2 2 5 4   
5 4 2 2   
8 1 9 2   

**********
Number of operation -> 4 16 64
84

**********
80 55 96 66
129 84 138 90
111 88 103 82
116 100 112 96 

**********
*/
