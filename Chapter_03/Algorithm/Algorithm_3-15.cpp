/*
Page 173
Algorithm QuickSort(p,q)
//Sorts the elemets in a[p:q];
{
    //Stack is a stack of size 2log(n);
    do
    {
        while(p < q)
        {
            j = partition(a, p, q+1);
            if((j - p ) < (q - j))
            {
                add(j+1); //add j+1 to stack
                add(q);
                q = j - 1; // add q to stack;
            }
            else
            {
                add(p); // Add p to stack
                Add(j-1);
                p = j + 1; // add j - 1 to stack
            }
        }
        //Sort the smaller subfile
        if(isempty())
        return;
        Delete(q);
        Delete(p); // Delete q and p from stack
    }while(true);
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
void quickSortIterative(int arr[], int l, int h)
{
    // Create an auxiliary stack
    int stack[h - l + 1];

    // initialize top of stack
    int top = -1;

    // push initial values of l and h to stack
    stack[++top] = l;
    stack[++top] = h;

    // Keep popping from stack while is not empty
    while (top >= 0)
    {
        // Pop h and l
        h = stack[top--];
        l = stack[top--];

        // Set pivot element at its correct position
        // in sorted array
        int p = partition(arr, l, h);

        // If there are elements on left side of pivot,
        // then push left side to stack
        if (p - 1 > l)
        {
            stack[++top] = l;
            stack[++top] = p - 1;
        }

        // If there are elements on right side of pivot,
        // then push right side to stack
        if (p + 1 < h)
        {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
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
    quickSortIterative(array, low, size);
    PrintArray(array, low, size);
    return 0;
}
/*
36 43 34 10 23 15 5 9 47 18 45 18 36 4 24 33 28 13 20 3 
3 4 5 9 10 13 15 18 18 20 23 24 28 33 34 36 36 43 45 47
*/
