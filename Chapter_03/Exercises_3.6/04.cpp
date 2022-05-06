/*
Page 178
4. Function QuickSort uses the output of function Partition, Which returns
the position where the partition elements is places. If equal keys are present, then two eleemts
can be properly placed instead of one.

Show how you might change Partition so that QuickSort can take advantage of this situation


*/
#include <iostream>
#include <ctime>
using namespace std;

void quick_sort(int[], int, int);
int partition(int[], int, int);
void PrintArray(int array[], int low, int high);
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
    quick_sort(array, low, size);
    PrintArray(array, low, size);
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
33 22 25 12 35 43 28 47 38 20 2 14 15 21 31 47 12 28 21 17
2 12 12 14 15 17 20 21 21 22 25 28 28 31 33 35 38 43 47 47
*/