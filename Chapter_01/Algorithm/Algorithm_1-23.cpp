/*
Page 59
4.
a) Introduce statements to inctement count at all appropriate points in algorithm 1.23
b) Simplify the resulting algorithm by eleminating statements. The simplified algorithm should
compute the same value for count as compute bu the algorithm of part (a);
c) what is the exact value of count when the algorithm terminates, you may assume that the initail value
of count is 0;
d) Obtain the step cunt for algorithm 1.23 using the frequency method, Clearly show the step count table;
Algorithm D(x,n)
{
    i := 1;
    repeat
    {
        x[i] := x[i] + 2;
        i := i + 2;
    }until (i > n);
    i := 1;
    while(i<= floor(n/2))do
    {
        x[i] := x[i] + x[i+1];
        i := i+1;
    }
}
*/
#include <iostream>
#include <ctime>
#include <cmath>
#include<iomanip>
using namespace std;
void D(int x[], int n)
{
    int i = 1;
    do
    {
        x[i] = x[i] + 2;
        i = i + 2;
    } while (i > n);
    i = 1;
    while (i <= floor(n / 2))
    {
        x[i] = x[i] + x[i + 1];
        i++;
    }
}

int main()
{
    srand(time(0));
    int n = 20;
    int x[n];
    for (int i = 1; i < n; i++)
    {
        x[i] = rand() % 20;
        cout << setw(5) << x[i] << " ";
    }
    D(x, n);
    cout << "\n";
    for (int i = 1; i < n; i++)
    {
        cout << setw(5) << x[i] << " ";
    }
}
/*
    9     5     1    19     0    12    11     8    16    13     9    19     5     9    15     1    19     2     0 
   16     6    20    19    12    23    19    24    29    22     9    19     5     9    15     1    19     2     0
*/