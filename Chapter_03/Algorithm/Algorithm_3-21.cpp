/*
page 190

Algorithm 3.21 Straightforword selection algorithm
//Rearrange a[] such that a[k] is the k-th smallest
Algorithm Select3(a,n,k)
{
    if(k <= floor(n/2))
    for(i = 1; i <= k; i++)
    {
        q = i;
        min = a[i];

        for(j = i + 1; j <= n; j++)
        {
            if (a[j] < min)
                {
                    q = j;
                    min = a[j];
                }
        }
        interchange(a, q, i);
    }
    else
    {
        for(i = n; i => k; i--)
        {
            q = i;
            max = a[i];
            for (j = (i - 1); j >= 1; j--)
            {
                if (a[j] > max)
                {
                    q = j;
                    max = a[j];
                }
            }
            interchange(a, j, i);
        }
    }

}
*/

#include <iostream>
#include <climits>
#include <ctime>
#include <cmath>
#include <iomanip>
using namespace std;

void Select3(int a[], int n, int k)
{
    int q, min, max, temp;
    if (k <= floor(n / 2))
        for (int i = 1; i <= k; i++)
        {
            q = i;
            min = a[i];

            for (int j = i + 1; j <= n; j++)
            {
                if (a[j] < min)
                {
                    q = j;
                    min = a[j];
                }
            }
            temp = a[q];
            a[q] = a[i];
            a[i] = temp;
            // interchange(a, q, i);
        }
    else
    {
        for (int i = n; i >= k; i--)
        {
            q = i;
            max = a[i];
            for (int j = (i - 1); j >= 1; j--)
            {
                if (a[j] > max)
                {
                    q = j;
                    max = a[j];
                }
            }
            temp = a[q];
            a[q] = a[i];
            a[i] = temp;
        }
    }
}
void PrintArray(int array[], int size)
{
    for (int i = 1; i < size; i++)
    {
        cout << setw(3) << array[i] << " ";
    }
    cout << "\n";
}
int main()
{
    srand(time(0));
    int size = 10;
    int array[size];
    for (int i = 1; i < size; i++)
        array[i] = rand() % 50;
    PrintArray(array, size);
    for (int i = 1; i < size; i++)
        Select3(array, size - 1, i);
    PrintArray(array, size);
}
/*
7  48  26  35  26  17  19  33   7
7   7  17  19  26  26  33  35  48
*/