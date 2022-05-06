/*
Page 168
8.
The sequences X1, X2, ...... Xl are sorted sequence suth that SUM(l, i = 1) = Xi = n;
show how to merge these l sequences in time O(nlog l);
*/
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
int count;
// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r)
{

    // Create L  A[p..q] and M  A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;
    // without auxiliary array value in array would be garbeg
    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
    {
        count++;
        L[i] = arr[p + i];
    }

    for (int j = 0; j < n2; j++)
    {
        count++;
        M[j] = arr[q + 1 + j];
    }

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2)
    {
        count += 3;
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

void MergeSort(int array[], int low, int high)
{
    count++;
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
        arr[i] = i;
    }
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    printArray(arr, arr_size);

    MergeSort(arr, 0, arr_size - 1);

    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    cout << "Number of compesion -> " << count << "\n";
    return 0;
}
/*
Given array is 
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 

Sorted array is 
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 
Number of compesion -> 271
*/