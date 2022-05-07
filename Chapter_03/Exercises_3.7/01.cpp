/*
Page 186 
1. Rewrite Select2, Partition and InsertionSort using b-space array;
*/

#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;
int r = 5;

void InsertionSort(int a[], int low, int high)
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
int select2(int a[], int k, int low, int up)
{
    int n, temp, x, y, j;
    do
    {
        n = up - low + 1; // Number of elements;
        if (n <= r)
        {
            InsertionSort(a, low, up);
            return low + k - 1;
        }
        for (int i = 1; i < floor(n / r); i++)
        {
            InsertionSort(a, low + (i - 1) * r, low + i * r - 1);
            // Collect medians in the front part of a[low:up];
            x = low + i - 1;
            y = low + (i - 1) * r + ceil(r / 2) - 1;
            temp = a[x];
            a[x] = a[y];
            a[y] = temp;
        }
        j = select2(a, ceil(floor(n / r) / 2), low, low + floor(n / r) - 1); // mm
        temp = a[low];
        a[low] = a[j];
        a[j] = temp;
        j = partition(a, low, up + 1);
        if (k == (j - low + 1))
            return j;
        else if (k < (j - low + 1))
            up = j - 1;
        else
        {
            k = k - (j - low + 1);
            low = j + 1;
        }
    } while (true);
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
    int size = 10, key, low = 0;
    int array[100];
    for (int i = low; i < size; i++)
    {
        array[i] = rand() % 100;
    }
    PrintArray(array, low, size);
    // Select1(array, size, 5);
    for (int i = low; i < size; i++)
        select2(array, i, low, size - 1);
    PrintArray(array, low, size);

    return 0;
}
/*

19 23 21 15 19 17 73 73 69 81
15 17 19 19 21 23 69 73 73 81


*/