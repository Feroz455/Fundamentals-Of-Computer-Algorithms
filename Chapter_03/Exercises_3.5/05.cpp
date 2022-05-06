/*
Page 198
Given a file of n records that are partially sorted as x1
x1 <= x2 < .... <= Xm and xm+1 <= .. < xn is its possible to sort the entire file in time
O(n) using only a small fixed ammound of additional storage
*/
#include <iostream>
#include <ctime>
using namespace std;
void insertionSort(int a[], int low, int high)
{
    int item = 0, i;
    for (int j = low; j < high; j++)
    {
        // a[1:j-1] is already sorted
        item = a[j];
        i = j - 1;
        while ((i >= low) && (item < a[i]))
        {
            a[i + 1] = a[i];
            i = i - 1;
        }
        a[i + 1] = item;
    }
}
// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r)
{

    // Create L  A[p..q] and M  A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}
void printArray(int array[], int start, int size)
{
    for (int i = start; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << "\n";
}
int main()
{
    srand(time(0));
    int size = 20;
    int array[size];

    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 50;
    }
    insertionSort(array, 0, size / 2);
    printArray(array, 0, size);
    insertionSort(array, size / 2, size);
    printArray(array, 0, size);
    //remember me
    merge(array, 0, size-1 / 2, size);
    printArray(array, 0, size);
    return 0;
}
/*
1 1 3 13 20 23 23 31 36 46 29 14 35 44 6 13 27 39 24 38 
1 1 3 13 20 23 23 31 36 46 6 13 14 24 27 29 35 38 39 44 
1 1 3 13 20 23 23 31 36 46 6 13 14 24 27 29 35 38 39 44
*/