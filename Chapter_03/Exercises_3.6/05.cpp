/*
Page 178

05. In Addition to Partition there are many other ways to partition a set 
Consider modifying Partition so that i  is incremented while a[i] <= v instead of a[i] < v. 
Rewrite Partition making all of the necessary changes to it and then compare the new version 
with the original.
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
        while (a[i] <= v && i < u);

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
0 20 14 36 33 7 22 4 20 30 14 31 43 2 13 38 5 27 24 46 
0 2 4 5 7 13 14 14 20 20 22 24 27 30 31 33 36 38 43 46 
*/