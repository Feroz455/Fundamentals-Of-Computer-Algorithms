/*
Page 104
Algorithm 2.10
Algorithm Sort(a,n)
//Sort the elements a[1:n]
{
    for i := 1 to n do intsert(a,i);
    for i := n to 1 step - 1 do
    {
        DelMax(a,i,x);
        a[i] := x;
    }
}
*/
/*
Page 103
Algorithm 2.9 Deletion from a heap

Algorithm Adjust(a, i, n)
//The complete binary trees with roots 2i and 2i + i are
//combined with node i to from a heap rooted at i. No
//node has an address greater than n or less than 1;
{
    j := 2i;
    item := a[i];
    while(j <= n) do
    {
        if((j < n) and (a[j] < a[cill(j+1)])) then j := j + 1;
        //Compare left and right child
        //and let j be the larger child
        if(item >= a[j]) then break
        //A position for item is found
        a[floor(j/2)] := a[j]; j := 2j;
    }
    a[floor(j/2)] = item;

}

Algorithm DelMax(a, n, x)
//Delete the maximum from the heap a[1:n] and store it in x.
{
    if(n == 0;)
    {
        write ("heap is empty"); return false;
    }
    x := a[1]; a[1] := a[n];
    Adjust(a, 1, n - 1); return true;

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
    srand(time(0));
    int x = 0 ;
    for (int i = 1; i <= n; i++)
    {

        a[i] = rand() % 100;
        Insert(a, i);
    }
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
    int array[100], item, choice = 1, N = 0;
    Sort(array, 10);
    for(int i = 1; i <= 10; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}
/*
3 19 27 34 38 49 64 69 83 90
*/