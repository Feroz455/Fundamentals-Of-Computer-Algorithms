/*
page 187
4. Selction 3.7 describes an alternative way to handle the situation when
a[] is not restricted to distinct elements. Using the partitioning elemet v, a[] is devided into three
subsets. Write algorithm corresponding to select1 and select2 using this idea. Using
your new version of select2 show that the wrost-case computing time O(n) even when r = 5
*/
#include <iostream>
#include <ctime>
#include <cmath>
#define INF 2147483647
using namespace std;
int r = 5;
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
/// i think i did not get actually whats is going one  here
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
8 44 10 96 21 58 98 55 13 82 
8 10 13 21 44 55 58 96 98 82
*/