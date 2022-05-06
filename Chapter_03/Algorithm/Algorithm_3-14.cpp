/*
page 170
//Sorts the elements a[p],....a[q] which reside in the gloabl
//Array a[1:n] into ascending order a[n+1] is considered to be
//defined and must be all the elements in a[1:n];

Algorithm QuickSort(p,q)
{
    if(p < q) // if there are more than one element
    {
        //devide P into two subproblems
        j := Partition(a, p, q+1);
        //j is the position of the partitioning element
        QuickSort(p, j -1);
        QuickSort(j+1, q);
        //There is no need for combining solutions.
    }
}
*/
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
void interchange(int a[], int i, int j)
{
    cout << ".";
    int p = a[i];
    a[i] = a[j];
    a[j] = p;
}
int Partition(int array[], int low, int high)
{

    int pivot = array[low];
    int i, j;
    i = low, j = high;
    do
    {

        do
        {
            i += 1;
        } while (array[i] >= pivot);
        do
        {
            j -= 1;
        } while (array[j] <= pivot);
        if (i < j)
        {
            interchange(array, i, j);
        }

    } while (i >= j);
    interchange(array, j, low);

    return j;
}
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