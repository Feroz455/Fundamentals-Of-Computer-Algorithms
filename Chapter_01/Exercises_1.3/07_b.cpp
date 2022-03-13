
/*
page 60
Algorthm 1.26 Matrix multiplication

Algorithm Mult(a,b,c,m,n,p)
{
    for i:=1 to m do
        for j := 1 to p do
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
#include <cmath>
#include <iomanip>
using namespace std;
int Mult(int **a, int **b, int **c, int m, int n, int p)
{
    int ci = 0, cj = 0, ck = 0;
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        count++;
        for (int j = 0; j < p; j++)
        {
            count++;
            for (int k = 0; k < n; k++)
            {
                count++;
            }
        }
    }
    // cout << ci << " " << cj << " " << ck << "\n";
    return count;
}

int main()
{
    srand(time(0));
    int n, m, p;
    n = m = p = 4;
    int **a, **b, **c;

    a = new int *[n];
    b = new int *[m];
    c = new int *[n];

    for (int i = 0; i < n; i++)
    {
        a[i] = new int[m];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            a[i][j] = rand() % 20;
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";

    for (int i = 0; i < m; i++)
    {
        b[i] = new int[p];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            b[i][j] = rand() % 20;
            cout << b[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < n; i++)
    {
        c[i] = new int[p];
    }

    cout << "Number of operation -> " << Mult(a, b, c, m, n, p) << " \n";

    return 0;
}
/*
10 12 11 11
3 16 0 9
19 4 16 18
14 4 2 8


17 6 9 4
4 17 7 19
6 11 9 0
4 5 17 7
Number of operation -> 84
*/
/*
It is generally more profitable to parallelize the outermost loop in a nest of loops, 
since the overheads incurred are small. However, it is not always safe to parallelize 
the outermost loops due to dependences that might be carried by such loops
*/