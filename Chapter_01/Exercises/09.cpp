/*
The pigeonhole principle states that if a function f has n distinct inputs
but less then n distink outputs, then thete exist two input a and b such
that a != b and f(a) == f(b). Present an algorithm to find a and b sach that f(a) = f(b).
Assume that the function in inputs are 1,2... and n
*/
#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
void pigeonhole(int A[], int N)
{
    for (int i = 0; i < N; i++)
    {
        if (A[i] > 1)
        {
            cout << "A[" << i << "] contain " << A[i] << " element\n";
        }
    }
    cout << "\n";
    return ;
}
int main()
{
    srand(time(0));
    int N;
    cout << "Entre number of element\n-> ";
    cin >> N;
    int Arr[N], Brr[N] = {0};
    for (int i = 0; i < N; i++)
    {
        Arr[i] = rand() % 10;
        Brr[Arr[i]]++;
    }
    pigeonhole(Brr, N);
    for (int i = 0; i < N; i++)
    {
        while (Brr[i]--)
        {
            cout << i << " ";
        }
    }
    return 0;
}
/*
output

Entre number of element
-> 20
A[2] contain 2 element
A[3] contain 3 element
A[4] contain 6 element
A[7] contain 3 element
A[8] contain 2 element
A[9] contain 2 element

1 2 2 3 3 3 4 4 4 4 4 4 5 7 7 7 8 8 9 9 
*/