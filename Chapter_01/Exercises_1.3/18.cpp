/*
page 22
Algorithm 1.11 Matrix addition
Algorithm Add(a,b,c,m,n)
{
    for i=: 1 to m do
        for j := 1 to n do
            c[i,j] = a[i,j] + b[i,j];
}

Page 62
18
Consider the algorithm Add(Algorithm 1.11)
a) Obtain run times for n = 1,10,20,,,,100
b) plote the time obtained in part (a);
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
    int m = 5, n;
    clock_t h, h1, t;

    for (n = 1; n <= 10000; n = n + 100)
    {
        h = clock();
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
        Add(A, B, C, m, n);
        h1 = clock();
        t = h1 - h;
        cout << ((double)t) / CLOCKS_PER_SEC << "sec\n";
    }

    return 0;
}
/*
output
0sec
0sec
0sec
0sec
0.001sec
0sec
0sec
0.001sec
0.001sec
0.001sec
0sec
0sec
0.001sec
0.001sec
0.001sec
0.001sec
0.001sec
0sec
0.001sec
0.001sec
0.001sec
0.001sec
0.002sec
0.001sec
0.001sec
0.001sec
0.003sec
0.001sec
0.001sec
0.001sec
0.003sec
0.002sec
0.001sec
0.002sec
0.002sec
0.002sec
0.003sec
0.002sec
0.002sec
0.002sec
0.001sec
0.003sec
0.002sec
0.003sec
0.002sec
0.003sec
0.001sec
0.003sec
0.005sec
0.002sec
0.003sec
0.001sec
0.003sec
0.004sec
0.003sec
0.004sec
0.002sec
0.003sec
0.002sec
0.002sec
0.004sec
0.001sec
0.002sec
0.002sec
0.004sec
0sec
0.002sec
0.002sec
0.002sec
0.003sec
0.003sec
0.001sec
0.005sec
0.003sec
0.003sec
0.002sec
0.003sec
0.003sec
0.002sec
0.002sec
0.003sec
0.004sec
0.001sec
0.001sec
0.002sec
0.004sec
0.004sec
0.005sec
0.002sec
0.003sec
0.003sec
0.002sec
0.004sec
0.003sec
0.003sec
0.003sec
0.003sec
0.005sec
0.002sec
0.005sec
*/