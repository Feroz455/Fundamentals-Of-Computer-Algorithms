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
Page 62
Analyze the computing time of SelectionSort(Algorithm 1.2);

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
    clock_t h, h1, t, t1;
    int N = 2000;

    for (int m = 100; m <= N; m = m + 100)
    {
       int  A[m];
        for (int i = 0; i < m; i++)
        {
            A[i] = rand() % 100;
        }
        cout << "\nSlection Sort\n";
        h = clock();
        Selection_Sort(A, m);
        h1 = clock();
        t = h1 - h;
        cout << ((double)t) / CLOCKS_PER_SEC << "sec\n";
    }

    return 0;
}
/*
output
Slection Sort
0sec

Slection Sort
0sec

Slection Sort
0sec

Slection Sort
0.001sec

Slection Sort
0.002sec

Slection Sort
0.002sec

Slection Sort
0.001sec

Slection Sort
0.002sec

Slection Sort
0.003sec

Slection Sort
0.004sec

Slection Sort
0.005sec

Slection Sort
0.005sec

Slection Sort
0.007sec

Slection Sort
0.006sec

Slection Sort
0.007sec

Slection Sort
0.006sec

Slection Sort
0.01sec

Slection Sort
0.012sec

Slection Sort
0.011sec

Slection Sort
0.008sec
*/