/*
Page 374
Algorithm 7.4 can a new queen be placed?

Algorithm Place(int k, int i)
//return true if a queen can be placed in kth row and
//ith column. OtherWise it returns false. x[] is a global array whose first(k -1)
//values have been set.
//Abs(r) returns the absulute value of r
{
    for(j = 1; j < k; j++)
    {
        if(x[j] == i) //Two in the same column
        if (Abs(x[j] - i) == Abs(j-k))
        {
            return false;
        }
    }
    return true;

}


Algorithm 7.5 All solutions to the n-queens problem

Algorithm N Queens(k,n)
//Using backtraking, this procedure prints all
//Possible placements of n queens on an n * n
//Chesboard so that they are nonattacking
{
    for(int i = 1; i <= n ; i++)
    {
        if(place(k,i)) then
        {
        x[k] = i;
        if(k == n) then write (x[1:n]);
        else
        NQueens(k+1,n);
        }

    }

}
*/
#include <iostream>
using namespace std;
int a[30], count = 0;
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
            cout << a[k] << " " << k << " \n";

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
8


Solution #: 1
Q       *       *       *       *       *       *       *
*       *       *       *       Q       *       *       *
*       *       *       *       *       *       *       Q
*       *       *       *       *       Q       *       *
*       *       Q       *       *       *       *       *
*       *       *       *       *       *       Q       *
*       Q       *       *       *       *       *       *
*       *       *       Q       *       *       *       *


Solution #: 2
Q       *       *       *       *       *       *       *
*       *       *       *       *       Q       *       *
*       *       *       *       *       *       *       Q
*       *       Q       *       *       *       *       *
*       *       *       *       *       *       Q       *
*       *       *       Q       *       *       *       *
*       Q       *       *       *       *       *       *
*       *       *       *       Q       *       *       *


Solution #: 3
Q       *       *       *       *       *       *       *
*       *       *       *       *       *       Q       *
*       *       *       Q       *       *       *       *
*       *       *       *       *       Q       *       *
*       *       *       *       *       *       *       Q
*       Q       *       *       *       *       *       *
*       *       *       *       Q       *       *       *
*       *       Q       *       *       *       *       *


Solution #: 4
Q       *       *       *       *       *       *       *
*       *       *       *       *       *       Q       *
*       *       *       *       Q       *       *       *
*       *       *       *       *       *       *       Q
*       Q       *       *       *       *       *       *
*       *       *       Q       *       *       *       *
*       *       *       *       *       Q       *       *
*       *       Q       *       *       *       *       *


Solution #: 5
*       Q       *       *       *       *       *       *
*       *       *       Q       *       *       *       *
*       *       *       *       *       Q       *       *
*       *       *       *       *       *       *       Q
*       *       Q       *       *       *       *       *
Q       *       *       *       *       *       *       *
*       *       *       *       *       *       Q       *
*       *       *       *       Q       *       *       *


Solution #: 6
*       Q       *       *       *       *       *       *
*       *       *       *       Q       *       *       *
*       *       *       *       *       *       Q       *
Q       *       *       *       *       *       *       *
*       *       Q       *       *       *       *       *
*       *       *       *       *       *       *       Q
*       *       *       *       *       Q       *       *
*       *       *       Q       *       *       *       *


Solution #: 7
*       Q       *       *       *       *       *       *
*       *       *       *       Q       *       *       *
*       *       *       *       *       *       Q       *
*       *       *       Q       *       *       *       *
Q       *       *       *       *       *       *       *
*       *       *       *       *       *       *       Q
*       *       *       *       *       Q       *       *
*       *       Q       *       *       *       *       *


Solution #: 8
*       Q       *       *       *       *       *       *
*       *       *       *       *       Q       *       *
Q       *       *       *       *       *       *       *
*       *       *       *       *       *       Q       *
*       *       *       Q       *       *       *       *
*       *       *       *       *       *       *       Q
*       *       Q       *       *       *       *       *
*       *       *       *       Q       *       *       *


Solution #: 9
*       Q       *       *       *       *       *       *
*       *       *       *       *       Q       *       *
*       *       *       *       *       *       *       Q
*       *       Q       *       *       *       *       *
Q       *       *       *       *       *       *       *
*       *       *       Q       *       *       *       *
*       *       *       *       *       *       Q       *
*       *       *       *       Q       *       *       *


Solution #: 10
*       Q       *       *       *       *       *       *
*       *       *       *       *       *       Q       *
*       *       Q       *       *       *       *       *
*       *       *       *       *       Q       *       *
*       *       *       *       *       *       *       Q
*       *       *       *       Q       *       *       *
Q       *       *       *       *       *       *       *
*       *       *       Q       *       *       *       *


Solution #: 11
*       Q       *       *       *       *       *       *
*       *       *       *       *       *       Q       *
*       *       *       *       Q       *       *       *
*       *       *       *       *       *       *       Q
Q       *       *       *       *       *       *       *
*       *       *       Q       *       *       *       *
*       *       *       *       *       Q       *       *
*       *       Q       *       *       *       *       *


Solution #: 12
*       Q       *       *       *       *       *       *
*       *       *       *       *       *       *       Q
*       *       *       *       *       Q       *       *
Q       *       *       *       *       *       *       *
*       *       Q       *       *       *       *       *
*       *       *       *       Q       *       *       *
*       *       *       *       *       *       Q       *
*       *       *       Q       *       *       *       *


Solution #: 13
*       *       Q       *       *       *       *       *
Q       *       *       *       *       *       *       *
*       *       *       *       *       *       Q       *
*       *       *       *       Q       *       *       *
*       *       *       *       *       *       *       Q
*       Q       *       *       *       *       *       *
*       *       *       Q       *       *       *       *
*       *       *       *       *       Q       *       *


Solution #: 14
*       *       Q       *       *       *       *       *
*       *       *       *       Q       *       *       *
*       Q       *       *       *       *       *       *
*       *       *       *       *       *       *       Q
Q       *       *       *       *       *       *       *
*       *       *       *       *       *       Q       *
*       *       *       Q       *       *       *       *
*       *       *       *       *       Q       *       *


Solution #: 15
*       *       Q       *       *       *       *       *
*       *       *       *       Q       *       *       *
*       Q       *       *       *       *       *       *
*       *       *       *       *       *       *       Q
*       *       *       *       *       Q       *       *
*       *       *       Q       *       *       *       *
*       *       *       *       *       *       Q       *
Q       *       *       *       *       *       *       *


Solution #: 16
*       *       Q       *       *       *       *       *
*       *       *       *       Q       *       *       *
*       *       *       *       *       *       Q       *
Q       *       *       *       *       *       *       *
*       *       *       Q       *       *       *       *
*       Q       *       *       *       *       *       *
*       *       *       *       *       *       *       Q
*       *       *       *       *       Q       *       *


Solution #: 17
*       *       Q       *       *       *       *       *
*       *       *       *       Q       *       *       *
*       *       *       *       *       *       *       Q
*       *       *       Q       *       *       *       *
Q       *       *       *       *       *       *       *
*       *       *       *       *       *       Q       *
*       Q       *       *       *       *       *       *
*       *       *       *       *       Q       *       *


Solution #: 18
*       *       Q       *       *       *       *       *
*       *       *       *       *       Q       *       *
*       Q       *       *       *       *       *       *
*       *       *       *       Q       *       *       *
*       *       *       *       *       *       *       Q
Q       *       *       *       *       *       *       *
*       *       *       *       *       *       Q       *
*       *       *       Q       *       *       *       *


Solution #: 19
*       *       Q       *       *       *       *       *
*       *       *       *       *       Q       *       *
*       Q       *       *       *       *       *       *
*       *       *       *       *       *       Q       *
Q       *       *       *       *       *       *       *
*       *       *       Q       *       *       *       *
*       *       *       *       *       *       *       Q
*       *       *       *       Q       *       *       *


Solution #: 20
*       *       Q       *       *       *       *       *
*       *       *       *       *       Q       *       *
*       Q       *       *       *       *       *       *
*       *       *       *       *       *       Q       *
*       *       *       *       Q       *       *       *
Q       *       *       *       *       *       *       *
*       *       *       *       *       *       *       Q
*       *       *       Q       *       *       *       *


Solution #: 21
*       *       Q       *       *       *       *       *
*       *       *       *       *       Q       *       *
*       *       *       Q       *       *       *       *
Q       *       *       *       *       *       *       *
*       *       *       *       *       *       *       Q
*       *       *       *       Q       *       *       *
*       *       *       *       *       *       Q       *
*       Q       *       *       *       *       *       *


Solution #: 22
*       *       Q       *       *       *       *       *
*       *       *       *       *       Q       *       *
*       *       *       Q       *       *       *       *
*       Q       *       *       *       *       *       *
*       *       *       *       *       *       *       Q
*       *       *       *       Q       *       *       *
*       *       *       *       *       *       Q       *
Q       *       *       *       *       *       *       *


Solution #: 23
*       *       Q       *       *       *       *       *
*       *       *       *       *       Q       *       *
*       *       *       *       *       *       *       Q
Q       *       *       *       *       *       *       *
*       *       *       Q       *       *       *       *
*       *       *       *       *       *       Q       *
*       *       *       *       Q       *       *       *
*       Q       *       *       *       *       *       *


Solution #: 24
*       *       Q       *       *       *       *       *
*       *       *       *       *       Q       *       *
*       *       *       *       *       *       *       Q
Q       *       *       *       *       *       *       *
*       *       *       *       Q       *       *       *
*       *       *       *       *       *       Q       *
*       Q       *       *       *       *       *       *
*       *       *       Q       *       *       *       *


Solution #: 25
*       *       Q       *       *       *       *       *
*       *       *       *       *       Q       *       *
*       *       *       *       *       *       *       Q
*       Q       *       *       *       *       *       *
*       *       *       Q       *       *       *       *
Q       *       *       *       *       *       *       *
*       *       *       *       *       *       Q       *
*       *       *       *       Q       *       *       *


Solution #: 26
*       *       Q       *       *       *       *       *
*       *       *       *       *       *       Q       *
*       Q       *       *       *       *       *       *
*       *       *       *       *       *       *       Q
*       *       *       *       Q       *       *       *
Q       *       *       *       *       *       *       *
*       *       *       Q       *       *       *       *
*       *       *       *       *       Q       *       *


Solution #: 27
*       *       Q       *       *       *       *       *
*       *       *       *       *       *       Q       *
*       Q       *       *       *       *       *       *
*       *       *       *       *       *       *       Q
*       *       *       *       *       Q       *       *
*       *       *       Q       *       *       *       *
Q       *       *       *       *       *       *       *
*       *       *       *       Q       *       *       *


Solution #: 28
*       *       Q       *       *       *       *       *
*       *       *       *       *       *       *       Q
*       *       *       Q       *       *       *       *
*       *       *       *       *       *       Q       *
Q       *       *       *       *       *       *       *
*       *       *       *       *       Q       *       *
*       Q       *       *       *       *       *       *
*       *       *       *       Q       *       *       *


Solution #: 29
*       *       *       Q       *       *       *       *
Q       *       *       *       *       *       *       *
*       *       *       *       Q       *       *       *
*       *       *       *       *       *       *       Q
*       Q       *       *       *       *       *       *
*       *       *       *       *       *       Q       *
*       *       Q       *       *       *       *       *
*       *       *       *       *       Q       *       *


Solution #: 30
*       *       *       Q       *       *       *       *
Q       *       *       *       *       *       *       *
*       *       *       *       Q       *       *       *
*       *       *       *       *       *       *       Q
*       *       *       *       *       Q       *       *
*       *       Q       *       *       *       *       *
*       *       *       *       *       *       Q       *
*       Q       *       *       *       *       *       *


Solution #: 31
*       *       *       Q       *       *       *       *
*       Q       *       *       *       *       *       *
*       *       *       *       Q       *       *       *
*       *       *       *       *       *       *       Q
*       *       *       *       *       Q       *       *
Q       *       *       *       *       *       *       *
*       *       Q       *       *       *       *       *
*       *       *       *       *       *       Q       *


Solution #: 32
*       *       *       Q       *       *       *       *
*       Q       *       *       *       *       *       *
*       *       *       *       *       *       Q       *
*       *       Q       *       *       *       *       *
*       *       *       *       *       Q       *       *
*       *       *       *       *       *       *       Q
Q       *       *       *       *       *       *       *
*       *       *       *       Q       *       *       *


Solution #: 33
*       *       *       Q       *       *       *       *
*       Q       *       *       *       *       *       *
*       *       *       *       *       *       Q       *
*       *       Q       *       *       *       *       *
*       *       *       *       *       Q       *       *
*       *       *       *       *       *       *       Q
*       *       *       *       Q       *       *       *
Q       *       *       *       *       *       *       *


Solution #: 34
*       *       *       Q       *       *       *       *
*       Q       *       *       *       *       *       *
*       *       *       *       *       *       Q       *
*       *       *       *       Q       *       *       *
Q       *       *       *       *       *       *       *
*       *       *       *       *       *       *       Q
*       *       *       *       *       Q       *       *
*       *       Q       *       *       *       *       *


Solution #: 35
*       *       *       Q       *       *       *       *
*       Q       *       *       *       *       *       *
*       *       *       *       *       *       *       Q
*       *       *       *       Q       *       *       *
*       *       *       *       *       *       Q       *
Q       *       *       *       *       *       *       *
*       *       Q       *       *       *       *       *
*       *       *       *       *       Q       *       *


Solution #: 36
*       *       *       Q       *       *       *       *
*       Q       *       *       *       *       *       *
*       *       *       *       *       *       *       Q
*       *       *       *       *       Q       *       *
Q       *       *       *       *       *       *       *
*       *       Q       *       *       *       *       *
*       *       *       *       Q       *       *       *
*       *       *       *       *       *       Q       *


Solution #: 37
*       *       *       Q       *       *       *       *
*       *       *       *       *       Q       *       *
Q       *       *       *       *       *       *       *
*       *       *       *       Q       *       *       *
*       Q       *       *       *       *       *       *
*       *       *       *       *       *       *       Q
*       *       Q       *       *       *       *       *
*       *       *       *       *       *       Q       *


Solution #: 38
*       *       *       Q       *       *       *       *
*       *       *       *       *       Q       *       *
*       *       *       *       *       *       *       Q
*       Q       *       *       *       *       *       *
*       *       *       *       *       *       Q       *
Q       *       *       *       *       *       *       *
*       *       Q       *       *       *       *       *
*       *       *       *       Q       *       *       *


Solution #: 39
*       *       *       Q       *       *       *       *
*       *       *       *       *       Q       *       *
*       *       *       *       *       *       *       Q
*       *       Q       *       *       *       *       *
Q       *       *       *       *       *       *       *
*       *       *       *       *       *       Q       *
*       *       *       *       Q       *       *       *
*       Q       *       *       *       *       *       *


Solution #: 40
*       *       *       Q       *       *       *       *
*       *       *       *       *       *       Q       *
Q       *       *       *       *       *       *       *
*       *       *       *       *       *       *       Q
*       *       *       *       Q       *       *       *
*       Q       *       *       *       *       *       *
*       *       *       *       *       Q       *       *
*       *       Q       *       *       *       *       *


Solution #: 41
*       *       *       Q       *       *       *       *
*       *       *       *       *       *       Q       *
*       *       Q       *       *       *       *       *
*       *       *       *       *       *       *       Q
*       Q       *       *       *       *       *       *
*       *       *       *       Q       *       *       *
Q       *       *       *       *       *       *       *
*       *       *       *       *       Q       *       *


Solution #: 42
*       *       *       Q       *       *       *       *
*       *       *       *       *       *       Q       *
*       *       *       *       Q       *       *       *
*       Q       *       *       *       *       *       *
*       *       *       *       *       Q       *       *
Q       *       *       *       *       *       *       *
*       *       Q       *       *       *       *       *
*       *       *       *       *       *       *       Q


Solution #: 43
*       *       *       Q       *       *       *       *
*       *       *       *       *       *       Q       *
*       *       *       *       Q       *       *       *
*       *       Q       *       *       *       *       *
Q       *       *       *       *       *       *       *
*       *       *       *       *       Q       *       *
*       *       *       *       *       *       *       Q
*       Q       *       *       *       *       *       *


Solution #: 44
*       *       *       Q       *       *       *       *
*       *       *       *       *       *       *       Q
Q       *       *       *       *       *       *       *
*       *       Q       *       *       *       *       *
*       *       *       *       *       Q       *       *
*       Q       *       *       *       *       *       *
*       *       *       *       *       *       Q       *
*       *       *       *       Q       *       *       *


Solution #: 45
*       *       *       Q       *       *       *       *
*       *       *       *       *       *       *       Q
Q       *       *       *       *       *       *       *
*       *       *       *       Q       *       *       *
*       *       *       *       *       *       Q       *
*       Q       *       *       *       *       *       *
*       *       *       *       *       Q       *       *
*       *       Q       *       *       *       *       *


Solution #: 46
*       *       *       Q       *       *       *       *
*       *       *       *       *       *       *       Q
*       *       *       *       Q       *       *       *
*       *       Q       *       *       *       *       *
Q       *       *       *       *       *       *       *
*       *       *       *       *       *       Q       *
*       Q       *       *       *       *       *       *
*       *       *       *       *       Q       *       *


Solution #: 47
*       *       *       *       Q       *       *       *
Q       *       *       *       *       *       *       *
*       *       *       Q       *       *       *       *
*       *       *       *       *       Q       *       *
*       *       *       *       *       *       *       Q
*       Q       *       *       *       *       *       *
*       *       *       *       *       *       Q       *
*       *       Q       *       *       *       *       *


Solution #: 48
*       *       *       *       Q       *       *       *
Q       *       *       *       *       *       *       *
*       *       *       *       *       *       *       Q
*       *       *       Q       *       *       *       *
*       Q       *       *       *       *       *       *
*       *       *       *       *       *       Q       *
*       *       Q       *       *       *       *       *
*       *       *       *       *       Q       *       *


Solution #: 49
*       *       *       *       Q       *       *       *
Q       *       *       *       *       *       *       *
*       *       *       *       *       *       *       Q
*       *       *       *       *       Q       *       *
*       *       Q       *       *       *       *       *
*       *       *       *       *       *       Q       *
*       Q       *       *       *       *       *       *
*       *       *       Q       *       *       *       *


Solution #: 50
*       *       *       *       Q       *       *       *
*       Q       *       *       *       *       *       *
*       *       *       Q       *       *       *       *
*       *       *       *       *       Q       *       *
*       *       *       *       *       *       *       Q
*       *       Q       *       *       *       *       *
Q       *       *       *       *       *       *       *
*       *       *       *       *       *       Q       *


Solution #: 51
*       *       *       *       Q       *       *       *
*       Q       *       *       *       *       *       *
*       *       *       Q       *       *       *       *
*       *       *       *       *       *       Q       *
*       *       Q       *       *       *       *       *
*       *       *       *       *       *       *       Q
*       *       *       *       *       Q       *       *
Q       *       *       *       *       *       *       *


Solution #: 52
*       *       *       *       Q       *       *       *
*       Q       *       *       *       *       *       *
*       *       *       *       *       Q       *       *
Q       *       *       *       *       *       *       *
*       *       *       *       *       *       Q       *
*       *       *       Q       *       *       *       *
*       *       *       *       *       *       *       Q
*       *       Q       *       *       *       *       *


Solution #: 53
*       *       *       *       Q       *       *       *
*       Q       *       *       *       *       *       *
*       *       *       *       *       *       *       Q
Q       *       *       *       *       *       *       *
*       *       *       Q       *       *       *       *
*       *       *       *       *       *       Q       *
*       *       Q       *       *       *       *       *
*       *       *       *       *       Q       *       *


Solution #: 54
*       *       *       *       Q       *       *       *
*       *       Q       *       *       *       *       *
Q       *       *       *       *       *       *       *
*       *       *       *       *       Q       *       *
*       *       *       *       *       *       *       Q
*       Q       *       *       *       *       *       *
*       *       *       Q       *       *       *       *
*       *       *       *       *       *       Q       *


Solution #: 55
*       *       *       *       Q       *       *       *
*       *       Q       *       *       *       *       *
Q       *       *       *       *       *       *       *
*       *       *       *       *       *       Q       *
*       Q       *       *       *       *       *       *
*       *       *       *       *       *       *       Q
*       *       *       *       *       Q       *       *
*       *       *       Q       *       *       *       *


Solution #: 56
*       *       *       *       Q       *       *       *
*       *       Q       *       *       *       *       *
*       *       *       *       *       *       *       Q
*       *       *       Q       *       *       *       *
*       *       *       *       *       *       Q       *
Q       *       *       *       *       *       *       *
*       *       *       *       *       Q       *       *
*       Q       *       *       *       *       *       *


Solution #: 57
*       *       *       *       Q       *       *       *
*       *       *       *       *       *       Q       *
Q       *       *       *       *       *       *       *
*       *       Q       *       *       *       *       *
*       *       *       *       *       *       *       Q
*       *       *       *       *       Q       *       *
*       *       *       Q       *       *       *       *
*       Q       *       *       *       *       *       *


Solution #: 58
*       *       *       *       Q       *       *       *
*       *       *       *       *       *       Q       *
Q       *       *       *       *       *       *       *
*       *       *       Q       *       *       *       *
*       Q       *       *       *       *       *       *
*       *       *       *       *       *       *       Q
*       *       *       *       *       Q       *       *
*       *       Q       *       *       *       *       *


Solution #: 59
*       *       *       *       Q       *       *       *
*       *       *       *       *       *       Q       *
*       Q       *       *       *       *       *       *
*       *       *       Q       *       *       *       *
*       *       *       *       *       *       *       Q
Q       *       *       *       *       *       *       *
*       *       Q       *       *       *       *       *
*       *       *       *       *       Q       *       *


Solution #: 60
*       *       *       *       Q       *       *       *
*       *       *       *       *       *       Q       *
*       Q       *       *       *       *       *       *
*       *       *       *       *       Q       *       *
*       *       Q       *       *       *       *       *
Q       *       *       *       *       *       *       *
*       *       *       Q       *       *       *       *
*       *       *       *       *       *       *       Q


Solution #: 61
*       *       *       *       Q       *       *       *
*       *       *       *       *       *       Q       *
*       Q       *       *       *       *       *       *
*       *       *       *       *       Q       *       *
*       *       Q       *       *       *       *       *
Q       *       *       *       *       *       *       *
*       *       *       *       *       *       *       Q
*       *       *       Q       *       *       *       *


Solution #: 62
*       *       *       *       Q       *       *       *
*       *       *       *       *       *       Q       *
*       *       *       Q       *       *       *       *
Q       *       *       *       *       *       *       *
*       *       Q       *       *       *       *       *
*       *       *       *       *       *       *       Q
*       *       *       *       *       Q       *       *
*       Q       *       *       *       *       *       *


Solution #: 63
*       *       *       *       Q       *       *       *
*       *       *       *       *       *       *       Q
*       *       *       Q       *       *       *       *
Q       *       *       *       *       *       *       *
*       *       Q       *       *       *       *       *
*       *       *       *       *       Q       *       *
*       Q       *       *       *       *       *       *
*       *       *       *       *       *       Q       *


Solution #: 64
*       *       *       *       Q       *       *       *
*       *       *       *       *       *       *       Q
*       *       *       Q       *       *       *       *
Q       *       *       *       *       *       *       *
*       *       *       *       *       *       Q       *
*       Q       *       *       *       *       *       *
*       *       *       *       *       Q       *       *
*       *       Q       *       *       *       *       *


Solution #: 65
*       *       *       *       *       Q       *       *
Q       *       *       *       *       *       *       *
*       *       *       *       Q       *       *       *
*       Q       *       *       *       *       *       *
*       *       *       *       *       *       *       Q
*       *       Q       *       *       *       *       *
*       *       *       *       *       *       Q       *
*       *       *       Q       *       *       *       *


Solution #: 66
*       *       *       *       *       Q       *       *
*       Q       *       *       *       *       *       *
*       *       *       *       *       *       Q       *
Q       *       *       *       *       *       *       *
*       *       Q       *       *       *       *       *
*       *       *       *       Q       *       *       *
*       *       *       *       *       *       *       Q
*       *       *       Q       *       *       *       *


Solution #: 67
*       *       *       *       *       Q       *       *
*       Q       *       *       *       *       *       *
*       *       *       *       *       *       Q       *
Q       *       *       *       *       *       *       *
*       *       *       Q       *       *       *       *
*       *       *       *       *       *       *       Q
*       *       *       *       Q       *       *       *
*       *       Q       *       *       *       *       *


Solution #: 68
*       *       *       *       *       Q       *       *
*       *       Q       *       *       *       *       *
Q       *       *       *       *       *       *       *
*       *       *       *       *       *       Q       *
*       *       *       *       Q       *       *       *
*       *       *       *       *       *       *       Q
*       Q       *       *       *       *       *       *
*       *       *       Q       *       *       *       *


Solution #: 69
*       *       *       *       *       Q       *       *
*       *       Q       *       *       *       *       *
Q       *       *       *       *       *       *       *
*       *       *       *       *       *       *       Q
*       *       *       Q       *       *       *       *
*       Q       *       *       *       *       *       *
*       *       *       *       *       *       Q       *
*       *       *       *       Q       *       *       *


Solution #: 70
*       *       *       *       *       Q       *       *
*       *       Q       *       *       *       *       *
Q       *       *       *       *       *       *       *
*       *       *       *       *       *       *       Q
*       *       *       *       Q       *       *       *
*       Q       *       *       *       *       *       *
*       *       *       Q       *       *       *       *
*       *       *       *       *       *       Q       *


Solution #: 71
*       *       *       *       *       Q       *       *
*       *       Q       *       *       *       *       *
*       *       *       *       Q       *       *       *
*       *       *       *       *       *       Q       *
Q       *       *       *       *       *       *       *
*       *       *       Q       *       *       *       *
*       Q       *       *       *       *       *       *
*       *       *       *       *       *       *       Q


Solution #: 72
*       *       *       *       *       Q       *       *
*       *       Q       *       *       *       *       *
*       *       *       *       Q       *       *       *
*       *       *       *       *       *       *       Q
Q       *       *       *       *       *       *       *
*       *       *       Q       *       *       *       *
*       Q       *       *       *       *       *       *
*       *       *       *       *       *       Q       *


Solution #: 73
*       *       *       *       *       Q       *       *
*       *       Q       *       *       *       *       *
*       *       *       *       *       *       Q       *
*       Q       *       *       *       *       *       *
*       *       *       Q       *       *       *       *
*       *       *       *       *       *       *       Q
Q       *       *       *       *       *       *       *
*       *       *       *       Q       *       *       *


Solution #: 74
*       *       *       *       *       Q       *       *
*       *       Q       *       *       *       *       *
*       *       *       *       *       *       Q       *
*       Q       *       *       *       *       *       *
*       *       *       *       *       *       *       Q
*       *       *       *       Q       *       *       *
Q       *       *       *       *       *       *       *
*       *       *       Q       *       *       *       *


Solution #: 75
*       *       *       *       *       Q       *       *
*       *       Q       *       *       *       *       *
*       *       *       *       *       *       Q       *
*       *       *       Q       *       *       *       *
Q       *       *       *       *       *       *       *
*       *       *       *       *       *       *       Q
*       Q       *       *       *       *       *       *
*       *       *       *       Q       *       *       *


Solution #: 76
*       *       *       *       *       Q       *       *
*       *       *       Q       *       *       *       *
Q       *       *       *       *       *       *       *
*       *       *       *       Q       *       *       *
*       *       *       *       *       *       *       Q
*       Q       *       *       *       *       *       *
*       *       *       *       *       *       Q       *
*       *       Q       *       *       *       *       *


Solution #: 77
*       *       *       *       *       Q       *       *
*       *       *       Q       *       *       *       *
*       Q       *       *       *       *       *       *
*       *       *       *       *       *       *       Q
*       *       *       *       Q       *       *       *
*       *       *       *       *       *       Q       *
Q       *       *       *       *       *       *       *
*       *       Q       *       *       *       *       *


Solution #: 78
*       *       *       *       *       Q       *       *
*       *       *       Q       *       *       *       *
*       *       *       *       *       *       Q       *
Q       *       *       *       *       *       *       *
*       *       Q       *       *       *       *       *
*       *       *       *       Q       *       *       *
*       Q       *       *       *       *       *       *
*       *       *       *       *       *       *       Q


Solution #: 79
*       *       *       *       *       Q       *       *
*       *       *       Q       *       *       *       *
*       *       *       *       *       *       Q       *
Q       *       *       *       *       *       *       *
*       *       *       *       *       *       *       Q
*       Q       *       *       *       *       *       *
*       *       *       *       Q       *       *       *
*       *       Q       *       *       *       *       *


Solution #: 80
*       *       *       *       *       Q       *       *
*       *       *       *       *       *       *       Q
*       Q       *       *       *       *       *       *
*       *       *       Q       *       *       *       *
Q       *       *       *       *       *       *       *
*       *       *       *       *       *       Q       *
*       *       *       *       Q       *       *       *
*       *       Q       *       *       *       *       *


Solution #: 81
*       *       *       *       *       *       Q       *
Q       *       *       *       *       *       *       *
*       *       Q       *       *       *       *       *
*       *       *       *       *       *       *       Q
*       *       *       *       *       Q       *       *
*       *       *       Q       *       *       *       *
*       Q       *       *       *       *       *       *
*       *       *       *       Q       *       *       *


Solution #: 82
*       *       *       *       *       *       Q       *
*       Q       *       *       *       *       *       *
*       *       *       Q       *       *       *       *
Q       *       *       *       *       *       *       *
*       *       *       *       *       *       *       Q
*       *       *       *       Q       *       *       *
*       *       Q       *       *       *       *       *
*       *       *       *       *       Q       *       *


Solution #: 83
*       *       *       *       *       *       Q       *
*       Q       *       *       *       *       *       *
*       *       *       *       *       Q       *       *
*       *       Q       *       *       *       *       *
Q       *       *       *       *       *       *       *
*       *       *       Q       *       *       *       *
*       *       *       *       *       *       *       Q
*       *       *       *       Q       *       *       *


Solution #: 84
*       *       *       *       *       *       Q       *
*       *       Q       *       *       *       *       *
Q       *       *       *       *       *       *       *
*       *       *       *       *       Q       *       *
*       *       *       *       *       *       *       Q
*       *       *       *       Q       *       *       *
*       Q       *       *       *       *       *       *
*       *       *       Q       *       *       *       *


Solution #: 85
*       *       *       *       *       *       Q       *
*       *       Q       *       *       *       *       *
*       *       *       *       *       *       *       Q
*       Q       *       *       *       *       *       *
*       *       *       *       Q       *       *       *
Q       *       *       *       *       *       *       *
*       *       *       *       *       Q       *       *
*       *       *       Q       *       *       *       *


Solution #: 86
*       *       *       *       *       *       Q       *
*       *       *       Q       *       *       *       *
*       Q       *       *       *       *       *       *
*       *       *       *       Q       *       *       *
*       *       *       *       *       *       *       Q
Q       *       *       *       *       *       *       *
*       *       Q       *       *       *       *       *
*       *       *       *       *       Q       *       *


Solution #: 87
*       *       *       *       *       *       Q       *
*       *       *       Q       *       *       *       *
*       Q       *       *       *       *       *       *
*       *       *       *       *       *       *       Q
*       *       *       *       *       Q       *       *
Q       *       *       *       *       *       *       *
*       *       Q       *       *       *       *       *
*       *       *       *       Q       *       *       *


Solution #: 88
*       *       *       *       *       *       Q       *
*       *       *       *       Q       *       *       *
*       *       Q       *       *       *       *       *
Q       *       *       *       *       *       *       *
*       *       *       *       *       Q       *       *
*       *       *       *       *       *       *       Q
*       Q       *       *       *       *       *       *
*       *       *       Q       *       *       *       *


Solution #: 89
*       *       *       *       *       *       *       Q
*       Q       *       *       *       *       *       *
*       *       *       Q       *       *       *       *
Q       *       *       *       *       *       *       *
*       *       *       *       *       *       Q       *
*       *       *       *       Q       *       *       *
*       *       Q       *       *       *       *       *
*       *       *       *       *       Q       *       *


Solution #: 90
*       *       *       *       *       *       *       Q
*       Q       *       *       *       *       *       *
*       *       *       *       Q       *       *       *
*       *       Q       *       *       *       *       *
Q       *       *       *       *       *       *       *
*       *       *       *       *       *       Q       *
*       *       *       Q       *       *       *       *
*       *       *       *       *       Q       *       *


Solution #: 91
*       *       *       *       *       *       *       Q
*       *       Q       *       *       *       *       *
Q       *       *       *       *       *       *       *
*       *       *       *       *       Q       *       *
*       Q       *       *       *       *       *       *
*       *       *       *       Q       *       *       *
*       *       *       *       *       *       Q       *
*       *       *       Q       *       *       *       *


Solution #: 92
*       *       *       *       *       *       *       Q
*       *       *       Q       *       *       *       *
Q       *       *       *       *       *       *       *
*       *       Q       *       *       *       *       *
*       *       *       *       *       Q       *       *
*       Q       *       *       *       *       *       *
*       *       *       *       *       *       Q       *
*       *       *       *       Q       *       *       *
Total solution 92
*/