/*
page 21
Algorithm 1.10 Algorithm 1.7 with ount statements added
Algorithm RSum(a, n)
{
    count := count + 1; // For the if condition
    if(n <= 0)
    {
        count := count + 1; // For the return statement
        return 0.0;
    }
    else
    {
        count := count + 1; // For the addition , function Invocation and return
        return (a, n-1)+A[n];
    }

}
*/
#include <iostream>
#include <ctime>
using namespace std;
int count = 0;
int Rsum(int A[], int N)
{
    count++;
    if (N < 0)
    {
        count++;
        return 0;
    }
    else
    {
        count++;
        return (Rsum(A, N - 1) + A[N]);
    }
}
int main()
{
    srand(time(0));
    int x = rand() % 500, A[x];
    for (int i = 0; i < x; i++)
    {
        A[i] = rand() % 100;
        cout << A[i] << " ";
    }
    cout << "\n";
    cout << "Number of element = " << x << '\n';
    cout << "Sum of all number = " << Rsum(A, x) << "\n";
    cout << "Number of operation  = "<< count << "\n";
    return 0;
}
/*
output
9 9 7 9 4 0 2 8 3 5 
Number of element = 10
Sum of all number = 56
Number of operation  = 24
*/