/*
page 62
Do the previous exercise for matrix multiplication (Algorithm 1.26)
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
*/
#include <iostream>
#include <ctime>
#include <cmath>
#include <iomanip>
using namespace std;
int Mult(int **a, int **b, int **c, int m, int n, int p)
{
    int count = 0;
    int ci = 0, cj = 0, ck = 0;

    for (int i = 0; i < m; i++)
    {
        count++;
        ci++;
        for (int j = 0; j < p; j++)
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
    // cout << ci << " " << cj << " " << ck << "\n";
    return count;
}

int main()
{
    srand(time(0));
    int n, m, p;
    int **a, **b, **c;
    clock_t h, h1, t, t1;
    double temp[10];
    for (int n = 1; n <= 100; n = n + 10)
    {
        m = p = n;
        h = clock();
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
            }
        }

        for (int i = 0; i < m; i++)
        {
            b[i] = new int[p];
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < p; j++)
            {
                b[i][j] = rand() % 20;
            }
        }

        for (int i = 0; i < n; i++)
        {
            c[i] = new int[p];
        }

        cout << "Number of operation -> " << Mult(a, b, c, m, n, p) << " \n";

        h1 = clock();
        t = h1 - h;
        cout << ((double)t) / CLOCKS_PER_SEC << "sec\n";

        temp[n/10] = ((double)t);
    }
    cout << "\n";
    for(int i = 0; i < 10; i++)
    {
        while(temp[i]--)
        {
            cout <<"*";
        }
        cout << "\n";
    }

    return 0;
}
/*
Number of operation -> 3    
0.003sec
Number of operation -> 1463 
0.001sec
Number of operation -> 9723 
0.001sec
Number of operation -> 30783
0.002sec
Number of operation -> 70643
0.002sec
Number of operation -> 135303 
0.003sec
Number of operation -> 230763
0.004sec
Number of operation -> 363023 
0.008sec
Number of operation -> 538083
0.009sec
Number of operation -> 761943 
0.011sec

***
*
*
**
**
***
****
********
*********
***********
*/