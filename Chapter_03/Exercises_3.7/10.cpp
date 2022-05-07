/*
page 188
10. Input is a (not necessarily sorted) sequence S = k1, k2, ....kn of n
arbitary numbers. Consider the collection C of n*n numbers of the from min(ki, kj)
for 1 <= i <= n. Present an O(n) time and O(n) space algorithm to find the midian of C
*/

#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <ctime>
using namespace std;
int R = 5;
int partition(int arr[], int l, int r, int k);
void InsertionSort(int a[], int low, int high)
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
// A simple function to find median of arr[].  This is called
// only for an array of size R in this program.
int findMedian(int arr[], int n)
{
    InsertionSort(arr, 0, n); // Sort the array
    return arr[n / 2];        // Return middle element
}

// Returns k'th smallest element in arr[l..r] in worst case
// linear time. ASSUMPTION: ALL ELEMENTS IN ARR[] ARE DISTINCT
int Select2(int arr[], int l, int r, int k)
{
    // If k is smaller than number of elements in array
    if (k > 0 && k <= r - l + 1)
    {
        int n = r - l + 1; // Number of elements in arr[l..r]

        // Divide arr[] in groups of size R, calculate median
        // of every group and store it in median[] array.
        int i, median[(n + 4) / R]; // There will be floor((n+4)/R) groups;
        for (i = 0; i < n / R; i++)
            median[i] = findMedian(arr + l + i * R, R);
        if (i * R < n) // For last group with less than R elements
        {
            median[i] = findMedian(arr + l + i * R, n % R);
            i++;
        }

        // Find median of all medians using recursive call.
        // If median[] has only one element, then no need
        // of recursive call
        int medOfMed = (i == 1) ? median[i - 1] : Select2(median, 0, i - 1, i / 2);

        // Partition the array around a random element and
        // get position of pivot element in sorted array
        int pos = partition(arr, l, r, medOfMed);

        // If position is same as k
        if (pos - l == k - 1)
            return arr[pos];
        if (pos - l > k - 1) // If position is more, recur for left
            return Select2(arr, l, pos - 1, k);

        // Else recur for right subarray
        return Select2(arr, pos + 1, r, k - pos + l - 1);
    }

    // If k is more than number of elements in array
    return INT_MAX;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// It searches for x in arr[l..r], and partitions the array
// around x.
int partition(int arr[], int l, int r, int x)
{
    // Search for x in arr[l..r] and move it to end
    int i;
    for (i = l; i < r; i++)
        if (arr[i] == x)
            break;
    swap(&arr[i], &arr[r]);

    // Standard partition algorithm
    i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}
void PrintArray(int array[], int low, int high)
{
    for (int i = low; i < high; i++)
    {
        cout << array[i] << " ";
    }
    cout << "\n";
}
int min(int x, int y)
{
    return (x > y) ? x : y;
}
int main()
{
    srand(time(0));
    int size = 10, key, csize = size * size;
    int S[100], C[200];
    for (int i = 0; i <= size; i++)
    {
        S[i] = rand() % 100;
    }
    for (int i = 1; i < csize; i++)
    {
        C[i] = min(S[rand() % size], S[rand() % size]);
    }
    // Select1(S, size, 5);
    cout << "Midian -> " << Select2(C, 1, csize, csize / 2) << "\n";
    PrintArray(C, 1, csize);
    return 0;
}
/*
Midian -> 77
12 70 70 70 70 12 33 70 12 33 33 33 33 33 12 70 70 70 
70 33 70 70 70 12 12 33 12 12 33 70 70 4 70 70 70 70 
70 12 70 70 70 77 77 77 77 77 77 77 77 77 77 
77 77 77 77 77 77 85 86 89 85 85 85 85 86 85 86 89 89 
89 85 89 89 85 89 89 86 85 86 89 89 86 85 85 86 86 89 
85 86 89 86 85 85 89 86 89 89 89 89 

*/