/*
Page 301
Algorithm 5.5 Finding a minimum-cost binary search tree

Algorithm OBST(p, q, n)
//Given n distinct identifires a1 < a2 < .... < an and probabilities
//p[i], 1 <= i <= n and q[i], 0 <= i <= n, this algorithm computes the cost
//c[i,j] of optimal binary search trees tij for identifiers
//ai+1 .......aj. It also computes r[i,j], the root of tij.
//w[i,j] is the weight of tij;
{
    for(i = 0 to n -1 do)
    {
        //initialize
        w[i][i] = q[i];
        r[i][i] = 0;
        c[i][i] = 0.0;
    //Optimal trees with one node
    w[i][i+1] = q[i] + q[i+1]+ p[i+1];
    r[i][i+1] = i + 1;

    c[i][i+1] = q[i] + q[i + 1] + p[i+1];
    }
    w[n][n] = q[n];
    r[n][n] = 0;
    c[n][n] = 0.0;
    for(m = 2 to n do) // Find optimal trees with m nodes
    {
        for(i = 0; i < n - m; i++)
        {
            j = i + m;
            w[i][j] = w[i][j-1] + p[j] + q[j];
            //Solve 5.12 using Knuth's result
            k = Find(c,r,i,j);
            //A value of l in the range r[i][j-1] <= l < r [i+1][j], that minimizes c[i][l-1]+c[l+j];
            c[i][j] = w[i][j] + c[i][k-1] + c[k][j];
            c[i][j] = w[i][j] + c[i][k-1]+c[k][j];
            r[i][j] = k;
        }
    }
    write (c[0][n], w[0][n], r[0][n]);
}

Algorithm Find(c,r,i,j)
{
    min = INF;
    for(int m = r[i][j-1] to r[i+1][j] do)
    {
        if(c[i][m-1] + c[m][j] < min)
        {
            min = c[i][m-1] + c[m][j];
            l = m;
        }
    }
    return l;
}

*/
// A naive recursive implementation of
// optimal binary search tree problem
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