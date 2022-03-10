/*
page 16
Algorithm 1.7 Recursive function for sum
Algorithm RSum(a, n)
{
    if(n <= 0)
    {
        return 0.0;
    }
    else
    return (a, n-1)+A[n];
}
*/
#include <iostream>
#include <ctime>
using namespace std;
int Rsum(int A[], int N)
{
    if (N < 0)
    {
        return 0;
    }
    else
    {
        return (Rsum(A, N - 1) + A[N]);
    }
}
int main()
{
    srand(time(0));
    int x = 10, A[x];
    for (int i = 0; i < x; i++)
    {
        A[i] = rand() % 10;
        cout << A[i] << " ";
    }
    cout << "\n";
    cout << "Sum of all number = " << Rsum(A, x);
    return 0;
}
/*
output
4 1 4 9 7 2 6 3 7 9   
Sum of all number = 52
*/