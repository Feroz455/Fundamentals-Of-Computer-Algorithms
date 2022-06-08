/*
Page 389
Algorithm 7.11 A bounding function


Algorithmm Bound(cp, cw, k)
//cp is the current profit total cw is the current
//weight total; k is the index of the last removed
//item and m is the knapsack size.
{
    b = cp;
    c = cw;
    for(int i = k+1; i <= n; i++)
    {
        c = c+ w[i];
        if(c < m)
        b = b + p[i];
        else
        return b + (1 - (c - m)/ w[i]) * p[i];
    }
}
*/
#include <iostream>
using namespace std;
#define n 8
int w[n + 1], p[n + 1], m, x[n + 1], y[n + 1], fp, fw;
void BKnap(int k, int cp, int cw);
int Bound(int cp, int cw, int k)

// cp is the current profit total cw is the current
// weight total; k is the index of the last removed
// item and m is the knapsack size.
{
    int b = cp;
    int c = cw;
    for (int i = k + 1; i <= n; i++)
    {
        c = c + w[i];
        if (c < m)
            b = b + p[i];
        else
            return b + (1 - (c - m) / w[i]) * p[i];
    }
    return 0;
}

void BKnap(int k, int cp, int cw)
// m is the size of the knapsack; n is the number of weight
// and profits. w[] and p[] are the weights and profits
// p[i]/w[i] >= p[i+1]/w[i+1]. fw is the final weight of
// knapsack; fp is the final maximum profit. x[k] = 0 if w[k]
// is not in the knapsack; else x[k] = 1;
{

    // Generate left child

    if (cw + w[k] <= m)
    {
        y[k] = 1;
        if (k < n)
        {
            BKnap(k + 1, cp + p[k], cw + w[k]);
        }
        if ((cp + p[k] > fp) && (k == n))
        {
            fp = cp + p[k];
            fw = cw + w[k];
            for (int j = 1; j <= k; j++)
            {
                x[j] = y[j];
            }
            for (int i = 1; i <= n; i++)
            {
                cout << x[i] << " ";
            }
            cout << "\n";
            cout << " fp " << fp << "\n";
            cout << " fw " << fw << "\n";
        }
    }
    // Generate right child

    if (Bound(cp, cw, k) >= fp)
    {
        y[k] = 0;
        if (k < n)
        {
            BKnap(k + 1, cp, cw);
            if ((cp > fp) && (k == n))
            {
                fp = cp;
                fw = cw;
                for (int j = 1; j <= k; j++)
                {
                    x[j] = y[j];
                }
                for (int i = 1; i <= n; i++)
                {
                    cout << x[i] << " ";
                }
                cout << "\n";
                cout << " fp " << fp << "\n";
                cout << " fw " << fw << "\n";
            }
        }
    }
}

int main()
{
    cout << "Enter weight\n";
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }
    cout << "Enter Profit\n";
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    cout << "Enter Knapsack capacity\n";
    cin >> m;

    BKnap(1, 0, 0);

    return 0;
}
/*
Enter weight
1 11 21 23 33 43 45 55
Enter Profit
11 21 31 33 43 53 55 65
Enter Knapsack capacity
110
1 1 1 0 0 0 0 1 
 fp 128
 fw 88
1 1 0 0 0 1 0 1
 fp 150
 fw 110
*/