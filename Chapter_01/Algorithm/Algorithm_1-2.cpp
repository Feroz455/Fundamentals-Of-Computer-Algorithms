/*
page 10
Algorithm SlectionSort(a,n)
sort the array a[i:n] into nondecreasing order
{
    for  i := 1 to n do
    {
        j := i;
        for k := i + 1 to n do 
        if(a[k] < a[j]) then j ;= k;
        t := a[i];
        a[i] := a[j];
        a[j] := t;
    } 
}
*/
#include <iostream>
#include <ctime>
using namespace std;
void interchange(int &x, int &y)
{
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
}
void Selection_Sort(int A[], int N)
{
    int temp = 0;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (A[i] > A[j])
            {
                interchange(A[j], A[i]);
            }
        }
    }
}
int main()
{
    srand(time(0));
    int N = 20, A[N];
    for (int i = 0; i < N; i++)
    {
        A[i] = rand() % 100;
        cout << A[i] << " ";
    }
    cout << "\nSlection Sort\n";
    Selection_Sort(A, N);
    for (int i = 0; i < N; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}
/*
output 
76 54 25 22 17 84 23 58 95 68 85 39 33 51 40 84 11 75 24 9 
Slection Sort
9 11 17 22 23 24 25 33 39 40 51 54 58 68 75 76 84 84 85 95 
*/