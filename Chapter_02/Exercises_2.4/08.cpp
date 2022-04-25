/*
Page 108
Algorithm 2.12 Heap Sort

Algorithm HeapSort(a, n)
//a[1:n] contains n elements to be sorted. HeapSorted
//rearranges them inplace into n nondecreasing order

{
    Heapify(a,n) // Transform the array into a heap
    //Interchange the new maximum with the element at the end of the array
    for i := n to 2 step -1 do
    {
        t := a[i];
        a[i] := a[1];
        a[1] := t;
        Adjust(a, 1, i - 1);
    }
}
*/
#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;
int parent(float i)
{
    return floor(i / 2);
}
int leftChild(float i)
{
    return ceill(i * 2);
}
int rightChild(float i)
{
    return ceill((i * 2) + 1);
}

bool Insert(int array[], int N)
{
    // Insert a[n] into the heap which is stored in a[1:n-1];
    int i = N, item = array[N];
    while ((i > 1) && (array[parent(i)] < item))
    {
        array[i] = array[i / 2];
        i = i / 2;
    }
    array[i] = item;
    return true;
}
void Adjust(int a[], int i, int n)
// The complete binary trees with roots 2i and 2i + 1 are
// combined with node i to from a heap rooted at i. NO
// Node has an address greater than n or less than 1.
{
    int j = 2 * i, item = a[i];
    while (j <= n)
    {
        if ((j < n) && (a[j] < a[j + 1]))
        {
            j = j + 1;
        }
        // compare left and right child
        // and let j be the larger child
        if (item >= a[j])
            break;
        // A position for item is found
        a[parent(j)] = a[j];
        j = 2 * j;
    }
    a[parent(j)] = item;
}
void Heapify(int a[], int n)
// ReadJust the elements in a[1:n] to from a heap
{
    for (int i = n / 2; i > 0; i--)
    {
        Adjust(a, i, n);
    }
}

bool HeapSort(int array[], int n)
{
    int t = 0;
    Heapify(array, n);
    for (int i = n; i > 1; i--)
    {
        t = array[i];
        array[i] = array[1];
        array[1] = t;
        Adjust(array, 1, i - 1);
    }
    return true;
}
int main()
{
    srand(time(0));
    int array[100], N = 10;
    for (int i = 1; i <= 10; i++)
    {
        array[i] = rand() % 100;
        cout << array[i] << "  ";
    }
    Heapify(array, N);
    cout << "\n";
    for (int i = 1; i <= N; i++)
    {
        cout << array[i] << "  ";
    }
    HeapSort(array, N);
    cout << "\n";
    for (int i = 1; i <= N; i++)
    {
        cout << array[i] << "  ";
    }
    return 0;
}
/*
91  26  38  58  56  8  41  77  67  21  
91  77  41  67  56  8  38  58  26  21
8  21  26  38  41  56  58  67  77  91
*/