/*
Page 178

7.
a) On which input data does the algorithm QuickSort exibit its worst-case

b) Answer part (a) for case in which the partitioning elements is selected according to the
   median of three rule

*/
#include <iostream>
#include <ctime>
#include <chrono>
#include <algorithm>
#include <cmath>
using namespace std;
using namespace std::chrono;

void quick_sort(int[], int, int);
int partition(int[], int, int);
void PrintArray(int array[], int low, int high);
int main()
{
    srand(time(0));
    int size = 12000, low = 0;
    int array[size];
    for (int i = 0; i < size; i++)
    {
        array[i] = size - i;
    }
    cout << "Array size =  " << size << "\n";
    auto start = high_resolution_clock::now();

    // Call the function, here sort()
    quick_sort(array, low, size);

    // Get ending timepoint
    auto stop = high_resolution_clock::now();

    // Get duration. Substart timepoints to
    // get duration. To cast it to proper unit
    // use duration cast method
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: QuickSort -> "
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
void quick_sort(int a[], int l, int u)
{
    int j;
    if (l < u)
    {
        j = partition(a, l, u);
        quick_sort(a, l, j - 1);
        quick_sort(a, j + 1, u);
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
        while (a[i] <= v && i <= u);

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

/*
decresing order
Array size =  12000
Time taken by function: QuickSort -> 254855 microseconds

incresing order
Array size =  12000
Time taken by function: QuickSort -> 265851 microseconds
*/