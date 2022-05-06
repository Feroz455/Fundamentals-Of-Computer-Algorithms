/*
Page 175
Algorithm 3.16 Randomized quick sort algorithm


//Sorts the elements a[p],...a[q] which reside in the global
//Array a[1:n] into ascending order. a[n+1] is considered to
//to be defined and must be >= all the elements is a[1:n];
Algorithm RQuickSort(p,q)
{
    if((p - p) > 5)
    {
        interchange(a, Random()%(q-p+1)+p, p);
    }
    j = partition(a,p,q+1);
    //j is the position of the partitioning elements
    RQuickSort(p,j-1);
    RQuickSort(j+1, q);
}
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
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void RQuickSort(int array[], int p, int q)
{
    int j, random;
    if (p < q) // if there are more than one element
    {
        if ((q - p) > 5)
        {
            random = (rand() % (q - p + 1) + p);
            swap(&array[random], &array[p]);
        }
        // devide P into two subproblems
        j = partition(array, p, q);
        // j is the position of the partitioning element
        RQuickSort(array, p, j - 1);
        RQuickSort(array, j + 1, q);
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
    RQuickSort(array, low, size);
    PrintArray(array, low, size);
    return 0;
}
/*
30 24 10 37 5 15 25 29 20 27 26 38 39 28 31 47 16 40 18 38 
5 10 15 16 18 20 24 25 26 27 28 29 30 31 37 38 38 39 40 47
*/