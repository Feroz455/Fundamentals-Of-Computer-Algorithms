/*
page 22
Algorithm 1.11 Matrix addition
Algorithm Add(a,b,c,m,n)
{

    for i=: 1 to m do
    {
        count := count + 1; // For for
        for j := 1 to n do
        {
            count := count + 1; // For for j
            c[i,j] = a[i,j] + b[i,j];
            count := count + 1; // For the assignment
        }
        count := count + 1; // For loop initializaion and last time of for j
    }
    count := count + 1; // For loop initializaion and last time of for i

}
*/
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
int count = 0;
void Add(int **A, int **B, int **C, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        count++;
        for (int j = 0; j < n; j++)
        {
            count++;
            C[i][j] = A[i][j] + B[i][j];
            count++;
        }
        count++;
    }
    count++;
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
    cout << "Number of operation = " << count << '\n';
    return 0;
}
/*
output
9 9 


    5     6     6    16     5    17     4    13     3
   11     2    13     6     7    18    15     8     9
    0     7    12    16     1    12     9    19    17
   15    16    11     5    18     6    19    18     2 
    0    19     4     9    13     2    19    17    11
   12    10     3    18    17     7    17     4    11
    8     0     8     4     5     3     3    14     8
   10     1     9    16     4     9    13    10    10
   17    17    11    17     7    17     7    16    15 


    3    13     1     8    14    18    14     0     3
    1    16     6     6    18    18    16     7    18
    2    17     7    18     1    13     0    12    19
   19     1     1     8     1    12     1     0     3 
    2     7    12     8     6     6    18     3     6
    5    13     0    17     4     7     4    19     4
    9    13    13    15    19    19     2     6     1
   16     6    13    19    18    11     3     2    11
   15     3     9    12     3    11    13    10     8 


    8    19     7    24    19    35    18    13     6
   12    18    19    12    25    36    31    15    27
    2    24    19    34     2    25     9    31    36 
   34    17    12    13    19    18    20    18     5
    2    26    16    17    19     8    37    20    17
   17    23     3    35    21    14    21    23    15 
   17    13    21    19    24    22     5    20     9
   26     7    22    35    22    20    16    12    21
   32    20    20    29    10    28    20    26    23
Number of operation = 181
*/