/*
Page 178
09. Take the iterative version of mergeSort and QuickSort and 
compare them for the same size data sets as used in section 3.6.1
*/
#include <iostream>
#include <ctime>
#include <chrono>
#include <algorithm>
#include <cmath>
using namespace std;
using namespace std::chrono;

void quickSortIterative(int arr[], int l, int h);
int partition(int[], int, int);
void PrintArray(int array[], int low, int high);
void MergeSort(int array[], int low, int high);
void merge(int arr[], int p, int q, int r);

int main()
{
    srand(time(0));
    int size = 12000, low = 0;
    int array[size];
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 50;
    }
    cout << "Array size =  " << size << "\n";
    auto start = high_resolution_clock::now();

    // Call the function, here sort()
    quickSortIterative(array, low, size);

    // Get ending timepoint
    auto stop = high_resolution_clock::now();

    // Get duration. Substart timepoints to
    // get duration. To cast it to proper unit
    // use duration cast method
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: QuickSort -> "
         << duration.count() << " microseconds" << endl;

    start = high_resolution_clock::now();
    MergeSort(array, low, size);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: MergeSort -> "
         << duration.count() << " microseconds" << endl;
    return 0;
}
void PrintArray(int array[], int low, int high)
{
    for (int i = low; i < high; i++)
    {
        cout << array[i] << " ";
    }
    cout << "\n";
}
void quickSortIterative(int arr[], int l, int h)
{
    // Create an auxiliary stack
    int stack[h - l + 1];

    // initialize top of stack
    int top = -1;

    // push initial values of l and h to stack
    stack[++top] = l;
    stack[++top] = h;

    // Keep popping from stack while is not empty
    while (top >= 0)
    {
        // Pop h and l
        h = stack[top--];
        l = stack[top--];

        // Set pivot element at its correct position
        // in sorted array
        int p = partition(arr, l, h);

        // If there are elements on left side of pivot,
        // then push left side to stack
        if (p - 1 > l)
        {
            stack[++top] = l;
            stack[++top] = p - 1;
        }

        // If there are elements on right side of pivot,
        // then push right side to stack
        if (p + 1 < h)
        {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}
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
        while (a[i] <= v && i < u);

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

/*
Array size =  1000
Time taken by function: QuickSort -> 0 microseconds
Time taken by function: MergeSort -> 0 microseconds

Array size =  4000
Time taken by function: QuickSort -> 999 microseconds
Time taken by function: MergeSort -> 1001 microseconds

Array size =  8000
Time taken by function: QuickSort -> 3994 microseconds
Time taken by function: MergeSort -> 1999 microseconds

Array size =  12000
Time taken by function: QuickSort -> 5995 microseconds
Time taken by function: MergeSort -> 2001 microseconds
*/