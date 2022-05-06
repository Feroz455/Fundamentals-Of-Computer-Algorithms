/*
Page 168
A version of insertion sort is used by algorithm 3.11 to sort small
subarray. However, its parameters and intent are slightly different from
the procedure InsertionSort of algorithm 3.10. Write a version of the insertion sort that will work as
algorithm 3.11 expects
*/
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

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
    int size = 20;
    int array[size];
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 50;
    }
    PrintArray(array, 0, size);
    insertionSort(array, 0, size);
    PrintArray(array, 0, size);
}
/*
33 37 38 36 2 35 9 9 22 47 22 31 6 46 28 3 42 43 2 48
2 2 3 6 9 9 22 22 28 31 33 35 36 37 38 42 43 46 47 48
*/