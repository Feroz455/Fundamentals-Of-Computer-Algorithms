/*
page 300
a) Show that the computing time of function OBST(Algorithm 5.5) is O(n^2)

b) Write an algorithm to construct the optimal binary search tree given the
roots r(i,j), 0 <= i <= j <= n. Show that this can be done in time O(n);
*/
#include <bits/stdc++.h>
using namespace std;
int n = 4;
#define INF 9999
int Find(int c[][4], int r[][4], int i, int j)
{
    int min = INF, l = 0;
    for (int m = r[i][j - 1]; m <= r[i + 1][j]; m++)
    {
        if (c[i][m - 1] + c[m][j] < min)
        {
            min = c[i][m - 1] + c[m][j];
            l = m;
        }
    }
    return l;
}
void OBST(int p[], int q[])
{
    int w[4][4] = {0};
    int r[4][4] = {0}, c[4][4] = {0};
    for (int i = 0; i < n; i++)
    {
        // initialize
        w[i][i] = q[i];
        r[i][i] = 0;
        c[i][i] = 0.0;
        // Optimal trees with one node
        w[i][i + 1] = q[i] + q[i + 1] + p[i + 1];
        r[i][i + 1] = i + 1;

        c[i][i + 1] = q[i] + q[i + 1] + p[i + 1];
    }
    w[n][n] = q[n];
    r[n][n] = 0;
    c[n][n] = 0.0;
    for (int m = 2; m <= n; m++) // Find optimal trees with m nodes
    {
        for (int i = 0; i <= n - m; i++)
        {
            int j = i + m;
            w[i][j] = w[i][j - 1] + p[j] + q[j];
            // Solve 5.12 using Knuth's result
            int k = Find(c, r, i, j);
            // A value of l in the range r[i][j-1] <= l < r [i+1][j], that minimizes c[i][l-1]+c[l+j];
            c[i][j] = w[i][j] + c[i][k - 1] + c[k][j];
            c[i][j] = w[i][j] + c[i][k - 1] + c[k][j];
            r[i][j] = k;
        }
    }

    cout << "Cost -> " << c[0][n] << " weight -> " << w[0][n] << " root ->  " << r[0][n] << "\n";
}
int main()
{
    int p[5] = {0, 3, 3, 1, 1};
    int q[] = {2, 3, 1, 1, 1};
    OBST(p, q);

    return 0;
}
/*
Cost -> 32 weight -> 16 root ->  2
*/