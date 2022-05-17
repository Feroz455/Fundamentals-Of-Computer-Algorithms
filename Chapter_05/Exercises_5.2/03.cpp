/*
Page 282
03) Program Algorithm 5.1. Asume that G is an array G[1:e, 1:3]
Each edge <i,j>, i < j , of G is store in G[q], for some q and G[q,1] = i,
G[q,2] = 2, and G[q,3] = cost of edge of edge <i,j>. Asume that G[q,1] <= G[q+1, 1] 
for 1 <= q < e, Where is the time complexity of your function.

*/ 
#include <iostream>
#include <iomanip>
using namespace std;
void PrintArray(int array[], int n)
{
    cout << "\n";
    for (int i = 1; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << "\n";
}
void FGraph(int c[][9])
{
    int stages = 4, min;
    int n = 8;
    int cost[9] = {-1, -1, -1, -1, -1, -1, -1, -1, -1}, d[9], p[stages + 1];
    cost[n] = 0;
    // PrintArray(cost, n + 1);
    for (int i = n - 1; i >= 1; i--)
    {
        min = 32767;
        for (int k = i + 1; k <= n; k++)
        {
            cout << "cost " << k << " , " << i << "  -> " << c[k][i] << " \n";
            if (c[i][k] != 0 && c[i][k] + cost[k] < min)
            {
                min = c[i][k] + cost[k];
                d[i] = k;
                // cout << " d[" << i << "]" << d[i] << "\n";
            }
        }
        cost[i] = min;
    }
    // PrintArray(cost, n + 1);
    p[1] = 1;
    p[stages] = n;
    int temp = 0;
    for (int i = 2; i < stages; i++)
    {
        p[i] = d[i - 1];
    }
    cout << "\npath is  ";
    for (int i = 1; i <= stages; i++)
    {
        cout << "-> " << p[i] << " ";
        temp += p[i];
    }
    cout << "\nTotal cost will be " << temp << " \n";
}
int main()
{

    int c[9][9] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 2, 1, 3, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 2, 3, 0, 0},
                   {0, 0, 0, 0, 0, 6, 7, 0, 0},
                   {0, 0, 0, 0, 0, 6, 4, 9, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 6},
                   {0, 0, 0, 0, 0, 0, 0, 0, 4},
                   {0, 0, 0, 0, 0, 0, 0, 0, 5},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0}};
    FGraph(c);
}
/*
path is  -> 1 -> 2 -> 6 -> 8
Total cost will be 17
*/