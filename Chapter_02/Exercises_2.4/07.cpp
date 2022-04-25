/*
Write an algorithm to delete the element in position i of a max heap.
The complexity of your algrithm should be O (log n)
*/
#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;
int parent(float i)
{
    return floor(i / 2);
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
bool Del_At(int a[], int n, int position, int &x)
{
    // Delete the maximum from the heap a[i:n] and store it in x
    if (n == 0)
    {
        cout << "Heap is empty\n";
        return false;
    }
    // cout << "\nN = " << n << endl;
    x = a[position];
    a[position] = a[n];
    Adjust(a, position, n - 1);
    return true;
}

int main()
{
    srand(time(0));
    int array[100], N = 10, x = 0;
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
    Del_At(array, N, 3, x);
    N = N - 1;
    cout << "\n";
    for (int i = 1; i <= N; i++)
    {
        cout << array[i] << "  ";
    }
    return 0;
}
/*
Output
72  72  86  29  48  52  86  3  0  84  
86  84  86  29  72  52  72  3  0  48  
86  84  72  29  72  52  48  3  0     
*/