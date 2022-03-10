/*
Algorithm 1.6 Iterative function for sum
Algorithm Sum(a,n)
{
    s = 0.0;
    for i := 1; to n do
    s := s + a[i];
    return s;
}
*/
#include <iostream>
#include <ctime>
using namespace std;
template <typename T>
T Sum(T A[], int N)
{
    T s = 0;
    for (int i = 0; i < N; i++)
    {
        s = s + A[i];
    }
    return s;
}
int main()
{
    srand(time(0));
    int x, A[10];
    for (int i = 0; i < 10; i++)
    {
        A[i] = rand() % 10;
        cout << A[i] << " ";
    }
    cout << "\n";
    cout <<"Sum of all number = " << Sum<int>(A, 10);
    return 0;
}
/*
output
0 6 5 0 3 3 5 7 4 7   
Sum of all number = 40
*/