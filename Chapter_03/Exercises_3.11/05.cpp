/*
page 208

Consider the problem of sorting n two-digit integers. The idea of radix
sort can be employed. We first sort the numbers only with respect to their
lest significant digits. (LSDs). Followed this we apply a sort with respect to
their second LSDs. More generaly d-digit numbers can be sorted in d phases, where
in the ith phase (i < i <= d) we sort the key only with respect to their ith LSDs. Will this
algorithm always work.


*/
// C++ implementation of Radix Sort
#include <iostream>
using namespace std;

// A utility function to get maximum value in arr[]
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
// 1,7
void countSort(int arr[], int n, int exp)
{
    int output[n]; // output array
    int i, count[10] = {0};

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % 10]++;
        // cout << count[(arr[i] / exp) % 10];
    }
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void radixsort(int arr[], int n)
{
    //{170, 45, 75, 90, 802, 24, 2, 66};
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);
    // m = 802
    //  Do counting sort for every digit. Note that instead
    //  of passing digit number, exp is passed. exp is 10^i
    //  where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

// A utility function to print an array
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

// Driver Code
int main()
{
    int arr[] = {170, 45, 75};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Function Call
    radixsort(arr, n);
    print(arr, n);
    return 0;
}