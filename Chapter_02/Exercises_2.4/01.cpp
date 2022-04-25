/*
Page 109
1. Consider the array [-3, 5, 6, 7, 20, 8, 2, 9, 12, 25, 15, 30, 17]
a) Drow the corresponding complete binray tree
b) Heapify the tree by using the method of algorithm 2.11. Show the result in both tree and array format
c) Now insert the elements 15 , 20 and 45 (in this order) using the bubbling up process of algorithm 2.8
Show the max heap following each insert.
d) Perform fout delete max operations on the max heap of part (c) Use the method of algorithm 2.9. Show the max heap
following each delete.
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
    while ((i > 1) && (array[(i / 2)] < item))
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

bool DelMax(int a[], int n, int &x)
{
    // Delete the maximum from the heap a[i:n] and store it in x
    if (n == 0)
    {
        cout << "Heap is empty\n";
        return false;
    }
    // cout << "\nN = " << n << endl;
    x = a[1];
    a[1] = a[n];
    Adjust(a, 1, n - 1);
    return true;
}
int main()
{
    srand(time(0));
    int array[100], N = 12;
    for (int i = 1; i <= N; i++)
    {
        cin >> array[i];
    }
    // b) Heapify the tree by using the method of algorithm 2.11. Show the result in both tree and array format
    Heapify(array, N);
    cout << "\n";
    for (int i = 1; i <= N; i++)
    {
        cout << array[i] << "  ";
    }
    /*
    c) Now insert the elements 15 , 20 and 45 (in this order) using the bubbling up process of algorithm 2.8
    Show the max heap following each insert.
    */
    array[++N] = 15;
    Insert(array, N);
    array[++N] = 20;
    Insert(array, N);
    array[++N] = 45;
    Insert(array, N);
    cout << "\n";
    for (int i = 1; i <= N; i++)
    {
        cout << array[i] << "  ";
    }
    int x = 0;

    /*
    d) Perform fout delete max operations on the max heap of part (c) Use the method of algorithm 2.9. Show the max heap
    following each delete.
    */
   cout << "\n";
    while (N)
    {
        DelMax(array, N, x);
        cout << x << " ";
        N--;
    }
    return 0;
}
/*
Output
3 5 6 7 20 8 2 9 12 15 30 17
30  20  17  12  15  8  2  9  7  3  5  6
45  20  30  12  15  15  20  9  7  3  5  6  8  2  17  
45 30 20 20 17 15 15 12 9 8 7 6 5 3 2
*/