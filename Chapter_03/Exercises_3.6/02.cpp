/*
page 177
2. QuickSort is not a stable sorting algorithm. How ever, if the key in
a[i] is changed to a[i]*n+i-1, then the new key are all distinct. After
sorting, which transformation will restore the keys to their original
*/
#include <iostream>
#include <ctime>
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
    int size = 5;
    int array[size];
    for (int i = 0; i < size; i++)
    {
        array[i] = i + +5;
    }
    PrintArray(array, 0, size);
    for (int i = 0; i < size; i++)
    {
        array[i] = (((array[i] * size) + i) - 1);
    }
    PrintArray(array, 0, size);
    QuickSort(array, 0, size - 1);
    PrintArray(array, 0, size);
    for (int i = 0; i < size; i++)
    {
        // array[i] = array[i] / size - i + 1;
        array[i] = ((array[i] - (i + 1)) / size) + 1;
    }
    PrintArray(array, 0, size);
    return 0;
}
/*
5 6 7 8 9
24 30 36 42 48
24 30 36 42 48
5 6 7 8 9
*/