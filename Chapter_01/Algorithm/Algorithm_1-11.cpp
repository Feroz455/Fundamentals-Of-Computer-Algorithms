/*
page 22
Algorithm 1.11 Matrix addition
Algorithm Add(a,b,c,m,n)
{
    for i=: 1 to m do
        for j := 1 to n do
            c[i,j] = a[i,j] + b[i,j];
}
*/
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
void Add(int **A, int **B, int **C, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return;
}
void Print(int **A, int m, int n)
{
    cout << "\n\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << setw(5) << A[i][j] << " ";
        }
        cout << "\n";
    }
}
int main()
{
    srand(time(0));
    int m, n;
    cin >> m >> n;
    int **A = new int *[m], **B = new int *[m], **C = new int *[m];
    for (int i = 0; i < m; i++)
    {
        A[i] = new int[n];
        B[i] = new int[n];
        C[i] = new int[n];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A[i][j] = rand() % 20;
            B[i][j] = rand() % 20;
        }
    }
    Print(A, m, n);
    Print(B, m, n);
    Add(A, B, C, m, n);
    Print(C, m, n);
    return 0;
}
/*
output
5 5


   15    13     4    17     1
    4     4     4    13    10
    0     2    15    11    19
   18    16     9    13     6
    4     5     9     2     1


    4    19     8    12     6
   14    11     0     8    13
   14    16     7    13     7
   18    11    18    12    18
   15     7     0    11     8


   19    32    12    29     7
   18    15     4    21    23
   14    18    22    24    26
   36    27    27    25    24
   19    12     9    13     9
*/