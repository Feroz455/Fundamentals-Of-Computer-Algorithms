/*
Do exercise 4 for transpose (Algorithm 1.24);
a) Introduce statements to inctement count at all appropriate points in algorithm 1.24
b) Simplify the resulting algorithm by eleminating statements. The simplified algorithm should
compute the same value for count as compute bu the algorithm of part (a);
c) what is the exact value of count when the algorithm terminates, you may assume that the initail value
of count is 0;
d) Obtain the step cunt for algorithm 1.23 using the frequency method, Clearly show the step count table;
Algorithm Transpose(a,n)
{
    for i:=1 to n-1 do
        for j := i+1 to n do
            {
                t := a[i,j];
                a[i,j] = a[j,i];
                a[j,i] = t;
            }
}
*/
#include <iostream>
#include <ctime>
using namespace std;
int const n = 4;
void Transpose(int a[][n])
{
    int t;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            t = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = t;
        }
    }
}
int main()
{
    srand(time(0));
    int x[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            x[i][j] = rand() % 10;
            cout << x[i][j] << " ";
        }
        cout << "\n";
    }
    Transpose(x);
    cout << "\n**********************\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << x[i][j] << " ";
        }
        cout << "\n";
    }
}
/*
6 8 5 5
2 6 4 2
2 9 7 9
3 0 3 2

**********************
6 8 5 5
2 6 4 2
2 9 7 9
3 0 3 2
*/