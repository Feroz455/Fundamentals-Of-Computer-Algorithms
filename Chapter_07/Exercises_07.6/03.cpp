/*
Page 393
3) Give a backtraking algorithm for the knapsack problem using the dynamic state space
tree discussed in this section.
*/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// A utility function that returns maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }

// Prints the items which are put in a knapsack of capacity W
void printknapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n + 1][W + 1];

    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] +
                                  K[i - 1][w - wt[i - 1]],
                              K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    // stores the result of Knapsack
    int res = K[n][W];
    cout << res << endl;

    w = W;
    for (i = n; i > 0 && res > 0; i--)
    {

        // either the result comes from the top
        // (K[i-1][w]) or from (val[i-1] + K[i-1]
        // [w-wt[i-1]]) as in Knapsack table. If
        // it comes from the latter one/ it means
        // the item is included.
        if (res == K[i - 1][w])
            continue;
        else
        {

            // This item is included.
            cout << " " << wt[i - 1];

            // Since this weight is included its
            // value is deducted
            res = res - val[i - 1];
            w = w - wt[i - 1];
        }
    }
}

// Driver code
int main()
{
    int val[] = {11, 21, 31, 33, 43, 53, 55, 65};
    int wt[] = {1, 11, 21, 23, 33, 43, 45, 55};
    int W = 110;
    int n = sizeof(val) / sizeof(val[0]);

    printknapSack(W, wt, val, n);

    return 0;
}
/*
159
43 33 21 11 1
*/