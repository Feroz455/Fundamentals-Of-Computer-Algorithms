/*
Page 179
3. In the function Partition Algorithm 3.13 discuss the merits or demerits of altering
the statement if(i < j) to if (i <= j). Simulate the both algorithm in the data set
5, 4, 3, 2, 5, 8, 9
*/
#include <iostream>
#include <ctime>
#include <iomanip>
#include <stack>
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
        if (arr[j] <= pivot)
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
    int size, low = 0;
    int array[] = {5, 4, 3, 2, 5, 8, 9};
    size = sizeof(array) / sizeof(array[0]);
    PrintArray(array, low, size);
    QuickSort(array, low, size - 1);
    PrintArray(array, low, size);
    return 0;
}
/*
same no problem
5 4 3 2 5 8 9
2 3 4 5 5 8 9

5 4 3 2 5 8 9 
2 3 4 5 5 8 9
*/
