/*
Page 375
1. Algorithm NQueens can be made more efficient by redefining the function Place(k,i) so that it
either returns the next legitimate column on which to place the kth queen or an illegal valu.
Rewrite both functions (algorithm 7.4 nd 7.5) so they implement this alternate strategy

*/
#include <iostream>
using namespace std;
int a[5], count = 0;
// row = index and column =  value
//  ie i = raw and a[i] = column;
int place(int k)
{
    int i;
    for (i = 1; i < k; i++) // from 1st row to the current row -1
    {
        if ((a[i] == a[k]) || ((abs(a[i] - a[k]) == abs(i - k))))
            return 0;
    }
    return 1;
}
void Print_Sol(int n)
{
    int i, j;
    count++;
    cout << "\n\nSolution #: " << count << "\n";
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            // cout << a[j] << " ";
            if (a[i] == j)
            {
                cout << "Q\t";
            }
            else
                cout << "*\t";
        }
        cout << "\n";
    }
}
void NQueen(int n)
{
    int k = 1;
    a[k] = 0;
    while (k != 0)
    {
        //   cout << a[k] << " " << k  << " \n";
        do
        {
            a[k]++;
            //  cout << a[k] << " " << k << " \n";

        } while ((a[k] <= n) && !place(k)); // while column are left
        if (a[k] <= n)
        {
            if (k == n)
            {
                Print_Sol(n);
            }
            else
            {
                k++;
                a[k] = 0;
            }
        }
        else
            k--;
    }
}
int main()
{
    int i, n;
    cout << "Enter the number of Queens\n";
    cin >> n;
    NQueen(n);
    cout << "Total solution " << count << '\n';
    return 0;
}
/*
Enter the number of Queens
4


Solution #: 1
2 4 1 3
2 4 1 3
2 4 1 3
2 4 1 3


Solution #: 2
3 1 4 2
3 1 4 2
3 1 4 2
3 1 4 2
Total solution 2


Enter the number of Queens
4

Solution #: 1
*       Q       *       *
*       *       *       Q
Q       *       *       *
*       *       Q       *


Solution #: 2
*       *       Q       *
Q       *       *       *
*       *       *       Q
*       Q       *       *
Total solution 2

*/