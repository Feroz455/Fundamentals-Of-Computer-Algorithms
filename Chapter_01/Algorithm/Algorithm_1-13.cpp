/*
page 22
Algorithm 1.11 Matrix addition
Algorithm Add(a,b,c,m,n)
{

    for i=: 1 to m do
    {
        count := count + 2; // For for
        for j := 1 to n do
        {
            count := count + 2; // For for j
        }
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
         count = count + 2;
        for (int j = 0; j < n; j++)
        {
            count = count + 2;
        }
    }
    count++;
    return;
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
    Add(A, B, C, m, n);
    cout << "Number of operation = " << count << '\n';
    return 0;
}
/*
output
4 4
Number of operation = 41
*/