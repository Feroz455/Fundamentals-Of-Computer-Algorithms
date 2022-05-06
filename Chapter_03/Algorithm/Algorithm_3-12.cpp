/*
Page 166
//q and r are pointers to lists contained in the global array
//link[0:n]. link[0] is introduced only for convenience and need
//Not to initialized. The list pointer at by q and r are merged
//and a pointer to the beginnig of the merged list returned

Algorithm Merge1(q, r)
{
    i = q; j = r; k = 0;
    //The new list starts at link[0]
    while((i != 0) && (j != 0))
    {
        //While both lists are nonempty do
        if(a[i] <= a[j])
        {
            //Finds the smaller key
            link[k] = i;
            k = i;
            i = link[i];
            //Add a new key to the list
        }
        else
        {
            link[k] = j;
            k = j;
            j = link[j];
        }
    }
    if(i == 0)
    {
        link[k] = j;
    }
    else
    {
        link[k] = i;
    }
    return link;
}


*/

#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
void printArray(int array[], int start, int size)
{
    for (int i = start; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << "\n";
}

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
void MergeSort1(int a[], int low, int high)
{
    int mid, q, r, link;
    if (high - low < 15)
    {
        insertionSort(a, low, high);
        // printArray(a, low, high);
    }
    else
    {
        mid = floor((low + high) / 2);
        MergeSort1(a, low, mid);
        MergeSort1(a, mid + 1, high);
        merge(a, low , mid, high);
    }
    return;
}

int main()
{
    srand(time(0));
    int size = 30;
    int array[size];

    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 50;
    }
    printArray(array, 0, size);
    // insertionSort1(array, size);
    MergeSort1(array, 0, size);
    printArray(array, 0, size);
}