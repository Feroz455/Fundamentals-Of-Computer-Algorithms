/*
Page 189

14. Given a set X of n numbers how will you find an element of X
whose  rank is at most n/f(n), using a Monte carlo algorithm? your
Algorithm should run in time O(f(n)log n). Prove that the output
will be correct with high probabiliry.
*/
#include <iostream>
#include <cmath>
#include <ctime>
#include <iomanip>
using namespace std;
void RepeatedElement(int a[], int n, int &r, int &s)
{
    srand(time(0));
    int i, j;
    while (true)
    {
        i = rand() % n + 1;
        j = rand() % n + 1;
        if ((i != j) && (a[i] == a[j]))
        {
            //cout << "index  " << j << " &  " << i;
            r = j, s = i;
            return;
        }
    }
}
void rankify(int A[], int n)
{

    // Rank Vector
    float R[n] = {0};
    int r, s;
    // Sweep through all elements in A for each
    // element count the number of less than and
    // equal elements separately in r and s.
    for (int i = 0; i < n; i++)
    {
        RepeatedElement(A, n, r, s);
        R[r]++;
        R[s]++;
    }
    float sum = 0.0;
    for (int i = 0; i < n; i++)
    {
        cout << R[i] << ' ';
    }
}

void PrintArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << setw(3) << array[i] << " ";
    }
    cout << "\n";
}
int main()
{
    srand(time(0));
    int size = 20;
    int array[20];
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 20;
    }
    PrintArray(array, size);
    rankify(array, size);
    return 0;
}