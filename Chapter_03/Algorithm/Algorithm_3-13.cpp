/*
Page 169
//Write a[m], a[m+1],.....,a[p-1] the elements are
//rearranged in such a manner that if initially t = a[m],
//then after completion a[q] = t for some q betwen m
//and p-1, a[k] <= t for m <= k < q and a[k] >= t
//for q < k < p. q is returned. set a[p] = INF;

Algorithm Partition(a, m, p)
{
    v = a[m];
    i = m;
    j = p;
    repeat
    {
        repeat
        {
            i = i + 1;
        }while(a[i] >= v);
        repeat
        {
            j = j - 1;
        }while(a[j] <= v);
        if(i < j)
        {
            interchange(a,i,j);
        }
    }while(i >= j);
    a[m] = a[j];
    a[j] = v;
    return j;
}
//Exchange a[i] with a[j];
Algorithm interchange(a, i, j)
{
    p = a[i];
    a[i] = a[j];
    a[j] = p;

}


*/
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
void interchange(int a[], int i, int j)
{
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
    array[low] = array[j];
    array[j] = pivot;
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