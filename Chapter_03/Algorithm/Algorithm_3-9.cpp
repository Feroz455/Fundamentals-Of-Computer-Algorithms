/*
page 161
//a[low:high] is a global array containing two sorted
//subsets in a[low : high] and in a [mid+1:high]. The goal
//is to merge these two sets into a single set residing
//in a[low : high]. b[] is an auxiliary global array;
Algorithm Merge(low, mid, high)
{
    h = low;
    i = low;
    j = mid + 1;
    while((h <= mid) && (j <= high))
    {
        if(a[h] <= a[j])
        {
            b[i] = a[ah];
            h = h+1;
        }
        else
        {
            b[i] = a[j];
            j = j + 1;
        }
        i = i + 1;
    }
    if(h > mid)
    {
        for(k = j to high do)
        {
            b[i] = a[k];
            i = i + 1;
        }
        else
        for  k = h to mid do
        {
            b[i] = a[k];
            i = i + 1;
        }
        for(k = low to high do a[k] = b[k]);
    }
}
*/
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

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

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively

    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}
void MergeSort(int array[], int low, int high)
{
    if (low < high) // If there are more than one element
    {
        int mid;
        // Divide p into subproblems.
        // Find where to split the set
        mid = floor(low + high) / 2;
        // solve the subproblems
        MergeSort(array, low, mid);
        MergeSort(array, mid + 1, high);
        // Combine the solutions
        merge(array, low, mid, high);
    }
}
// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << "\n";
}

// Driver code
int main()
{
    srand(time(0));
    int size = 20;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 50;
    }
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    printArray(arr, arr_size);

    MergeSort(arr, 0, arr_size - 1);

    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
}
/*
Given array is 
23 41 43 5 34 7 4 18 1 8 42 7 22 23 21 48 10 30 15 11 

Sorted array is 
1 4 5 7 7 8 10 11 15 18 21 22 23 23 30 34 41 42 43 48 
*/