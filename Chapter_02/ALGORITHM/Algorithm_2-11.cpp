/*
Page 106
Algorithm 2.11 Creating a heap out of n arbitrary elements

Algorithm Heapify(a,n)
//ReadJust the elements in a[1:n] to from a heap
{
    for i = floor(n/2) to 1 step - 1 do Adjust (a, i, n);
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
    for (int i = n/2; i > 0; i--)
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
bool Sort(int a[], int n)
{
    int x = 0 ;
    for(int i = n ; i >= 1; i--)
    {
        DelMax(a, i, x);
        a[i] = x;
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
    Sort(array, N);
    cout << "\n";
    for (int i = 1; i <= N; i++)
    {
        cout << array[i] << "  ";
    }
    return 0;
}
/*
10  14  64  22  29  78  58  37  61  55  
78  61  64  37  55  10  58  14  22  29  
10  14  22  29  37  55  58  61  64  78 
*/
