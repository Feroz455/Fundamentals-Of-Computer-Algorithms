/*
Page 177

Show how QuickSort sorts he following sequences of keys 1,1,1,1,1,1,1,1 and 5, 5, 8, 3, 4, 3, 2
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
            cout << "Swap "
                 << "array[" << i << "] = " << arr[i] << "\tarray[" << j << "] = " << arr[j] << "\n";
            swap(&arr[i], &arr[j]);
        }
    }
    cout << "Swap pivot "
         << "array[" << i + 1 << "] = " << arr[i + 1] << "\tarray[" << high << "] = " << arr[high] << "\n";
    swap(&arr[i + 1], &arr[high]);

    return (i + 1);
}
void QuickSort(int array[], int p, int q)
{
    cout << "p ->  " << p << " q -> " << q << "\n";
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
    int size, low = 0;
    int array[] = {1,1,1,1,1,1,1,1};
    size = sizeof(array) / sizeof(array[0]);
    PrintArray(array, low, size);
    QuickSort(array, low, size-1);
    PrintArray(array, low, size);
    return 0;
}
/*
for input 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
p ->  0 q -> 7
Swap pivot array[0] = 1 array[7] = 1
p ->  0 q -> -1
p ->  1 q -> 7
Swap pivot array[1] = 1 array[7] = 1
p ->  1 q -> 0
p ->  2 q -> 7
Swap pivot array[2] = 1 array[7] = 1
p ->  2 q -> 1
p ->  3 q -> 7
Swap pivot array[3] = 1 array[7] = 1
p ->  3 q -> 2
p ->  4 q -> 7
Swap pivot array[4] = 1 array[7] = 1
p ->  4 q -> 3
p ->  5 q -> 7
p ->  5 q -> 4
p ->  6 q -> 7
Swap pivot array[6] = 1 array[7] = 1
p ->  6 q -> 5
p ->  7 q -> 7
1 1 1 1 1 1 1 1




for input 
5 5 8 3 4 3 2 



5 5 8 3 4 3 2 
p ->  0 q -> 6
Swap pivot array[0] = 5 array[6] = 2
p ->  0 q -> -1
p ->  1 q -> 6
Swap array[1] = 5       array[3] = 3
Swap array[2] = 8       array[4] = 4
Swap array[3] = 5       array[5] = 3
Swap pivot array[4] = 8 array[6] = 5
p ->  1 q -> 3
Swap pivot array[1] = 3 array[3] = 3
p ->  1 q -> 0
p ->  2 q -> 3
Swap pivot array[2] = 4 array[3] = 3
p ->  2 q -> 1
p ->  3 q -> 3
p ->  5 q -> 6
Swap array[5] = 5       array[5] = 5
Swap pivot array[6] = 8 array[6] = 8
p ->  5 q -> 5
p ->  7 q -> 6
2 3 3 4 5 5 8
*/