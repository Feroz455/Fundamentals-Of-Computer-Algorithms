/*
page 8
Algorithm Max(A,n)
//A is an array of size n
{
    Result := A[1];
    for i := 2 to n do
        if A[i] > Result then Result := A[i];
    return result;
}
*/
#include <iostream>
#include<ctime>
using namespace std;
int MAX(int A[], int N)
{
    int result;
    result = A[0];
    for (int i = 1; i < N; i++)
    {
        if (result < A[i])
        {
            result = A[i];
        }
    }
    return result;
}
int main()
{
    srand(time(0));
    int N = 20 , A[20];
    for(int i = 0; i < N; i++)
    {
         A[i] = rand()%100;
         cout << A[i] << " ";
    }
    cout << "\nMAX = " <<  MAX(A, N);
    return 0;
}
/*
52 14 72 31 3 58 41 78 64 21 50 68 3 50 54 54 95 23 45 64 
MAX = 95
*/