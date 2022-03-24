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
    x = a[1];
    a[1] = a[n];
    Adjust(a, 1, n - 1);
    return true;
}
void option()
{
    int i = 0;
    cout << "\n******************************************\n";
    cout << ++i << "\tInsert Item into heap\n";
    cout << ++i << "\tShow item\n";
    cout << ++i << "\tDelete item from Heap\n";
    cout << ++i << "\tExit Progeam\n";
    cout << "\n******************************************\n";
}
int main()
{
    srand(time(0));
    int array[100], item, choice = 1, i = 0;
    do
    {
        option();
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter a integer\n";
            cin >> item;
            i = i + 1;
            array[i] = item;
            if (Insert(array, i))
                cout << "Insert Successfull\n";
            else
                cout << "Insert failed\n";
            break;
        case 2:
            cout << "Showing heap onorderd \n";
            if (i)
            {
                for (int j = 1; j <= i; j++)
                {
                    cout << array[j] << " ";
                }
                cout << "\n";
            }
            else
                cout << "List is empty\n";

            break;
        case 3:
            cout << "Delete Max\n";
            DelMax(array, i, item);
            i = i - 1;
            cout << item;
            break;
        case 4:
            exit(0);

        default:
            cout << "Invalid input!!\ntry again\n";
            break;
        }

    } while (choice);
    return 0;
}
