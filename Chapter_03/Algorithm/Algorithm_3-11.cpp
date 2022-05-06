/*
page 165
//The Global array a[low:high] is sorted in nondecreasing order
//Using the auxiliary array link[low:high].The values in link
//Repersent a list of the indices low through high giving a[] in
//Sorted order. A pointer to the begining of the list is returned
Algorithm MergeSort(low, high)
{
    if(high - low < 15)
    {
        return insertionSort1(a, link, low, high);
    }
    else
    {
        mid = floor((low+high)/2);
        q = MergeSort1(low, mid);
        r = MergeSort1(mid+1, high);
        return Merge1(q,r);
    }
}
*/

#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
void printArray(int array[], int start, int size)
{
    for (int i = start; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << "\n";
}

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

void insertionSort(int a[], int low, int high)
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
void MergeSort1(int a[], int low, int high)
{
    int mid, q, r, link;
    if (high - low < 15)
    {
        insertionSort(a, low, high);
        // printArray(a, low, high);
    }
    else
    {
        mid = floor((low + high) / 2);
        MergeSort1(a, low, mid);
        MergeSort1(a, mid + 1, high);
        merge(a, low , mid, high);
    }
    return;
}

int main()
{
    srand(time(0));
    int size = 30;
    int array[size];

    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 50;
    }
    printArray(array, 0, size);
    // insertionSort1(array, size);
    MergeSort1(array, 0, size);
    printArray(array, 0, size);
}
/*
24 8 14 30 10 18 8 26 31 45 31 18 16 20 8 16 43 47 25 26 17 19 30 27 19 49 15 21 12 40
8 8 10 14 18 24 30
8 16 18 20 31 31 45
12 15 17 19 19 21 25 26 27 30 40 43 47 49
8 8 8 10 12 14 15 16 17 18 18 19 19 20 21 24 25 26 27 30 26 30 31 31 40 43 45 16 47 49
*/