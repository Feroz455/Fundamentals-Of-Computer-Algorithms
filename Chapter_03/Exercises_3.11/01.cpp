/*
Page 207
01. What happens to the worst-case run time of quick sort if we use the
median of the given keys as the splitter key?
(Assume that the selection algorithm of section 3.6 is employes to determine the midian)
*/
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1);     // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j < high; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void QuickSort(int array[], int p, int q)
{
    int j;
    if (p < q) // if there are more than one element
    {
        // devide P into two subproblems
        j = partition(array, p, q);
        // j is the position of the partitioning element
        QuickSort(array, p, j - 1);
        QuickSort(array, j + 1, q);
        // There is no need for combining solutions.
    }
}
void PrintArray(int array[], int low, int high)
{
    for (int i = low; i < high; i++)
    {
        cout << array[i] << " ";
    }
    cout << "\n";
}
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
    QuickSort(array, low, size);
    PrintArray(array, low, size);
    return 0;
}
/*
To analyze the quickSort function, note that for a list of length n, 
if the partition always occurs in the middle of the list, there will 
again be \(\log n\) divisions. In order to find the split point, each 
of the n items needs to be checked against the pivot value. The result 
is \(n\log n\). In addition, there is no need for additional memory as 
in the merge sort process.

Unfortunately, in the worst case, the split points may not be in the 
middle and can be very skewed to the left or the right, leaving a very 
uneven division. In this case, sorting a list of n items divides into 
sorting a list of 0 items and a list of \(n-1\) items. Then sorting a 
list of \(n-1\) divides into a list of size 0 and a list of size \(n-2\), 
and so on. The result is an \(O(n^{2})\) sort with all of the overhead that 
recursion requires.
*/