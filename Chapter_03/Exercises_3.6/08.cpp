/*
page 178

*/
#include <bits/stdc++.h>
using namespace std;

// Function to perform the insertion sort

void insertion_sort(int arr[], int low, int n)
{

    for (int i = low + 1; i < n + 1; i++)
    {
        int val = arr[i];
        int j = i;
        while (j > low && arr[j - 1] > val)
        {
            arr[j] = arr[j - 1];
            j -= 1;
        }
        arr[j] = val;
    }
}

// The following two functions are used
//  to perform quicksort on the array.

// Partition function for quicksort

int partition(int a[], int l, int u)
{
    int v, i, j, temp;
    v = a[l];
    i = l;
    j = u + 1;

    do
    {
        do
            i++;
        while (a[i] <= v && i <= u);

        do
            j--;
        while (v < a[j]);

        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);

    a[l] = a[j];
    a[j] = v;
    return (j);
}

// Function to call the partition function
// and perform quick sort on the array

void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quick_sort(arr, low, pivot - 1);
        quick_sort(arr, pivot + 1, high);
    }
}

// Hybrid function -> Quick + Insertion sort

void hybrid_quick_sort(int arr[], int low, int high)
{
    while (low < high)
    {

        // If the size of the array is less
        // than threshold apply insertion sort
        // and stop recursion

        if (high - low + 1 < 10)
        {
            insertion_sort(arr, low, high);
            break;
        }
        else
        {
            int pivot = partition(arr, low, high);

            // Optimised quicksort which works on
            // the smaller arrays first

            // If the left side of the pivot
            // is less than right, sort left part
            // and move to the right part of the array

            if (pivot - low < high - pivot)
            {
                hybrid_quick_sort(arr, low, pivot - 1);
                low = pivot + 1;
            }
            else
            {
                // If the right side of pivot is less
                // than left, sort right side and
                // move to the left side

                hybrid_quick_sort(arr, pivot + 1, high);
                high = pivot - 1;
            }
        }
    }
}
void PrintArray(int array[], int low, int high)
{
    for (int i = low; i < high; i++)
    {
        cout << array[i] << ", ";
    }
    cout << "\n";
}
// Driver Code
int main()
{
    srand(time(0));
    int size = 20, low = 0;
    int array[size];
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 50;
    }
    PrintArray(array, low, size);
    hybrid_quick_sort(array, low, size);
    PrintArray(array, low, size);
    return 0;
}
/*
14, 0, 21, 28, 11, 32, 45, 21, 21, 42, 31, 26, 23, 7, 25, 29, 12, 15, 21, 48, 
0, 7, 11, 12, 14, 15, 21, 21, 21, 21, 23, 25, 26, 28, 29, 31, 32, 42, 45, 48,
*/