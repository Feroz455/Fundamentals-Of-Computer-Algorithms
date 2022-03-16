/*
page 91
03. In a k-ary tree, k>1, each node may have up to k children. These children are called, respectively
the first, second , ,,,,, kth child of the node, A 2-ary tree is a binary tree;
*/
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cmath>
using namespace std;
int parent(int i)
{
    if (i != 1)
        return floor(i / 2);
    else
        return 1;
}
int Lchild(int i, int n)
{
    if ((2 * i) < n)
    {
        return (2 * i);
    }
    else
        return 0;
}

int Rchild(int i, int n)
{
    if (((2 * i) + 1) <= n)
    {
        return ((2 * i) + 1);
    }
    else
        return 0;
}
int main()
{
    srand(time(0));
    int temp, n = 5, height, node;
    node = rand() % 20;

    for (int i = 1; i <= n; i++)
    {
        cout << "Maximum number of nodes on level " << i << " of a binaray tree is " << pow(2, i - 1) << "\n";
    }
    for (int i = 1; i <= n; i++)
    {
        cout << "Maximum number of nodes in a binray tree of depth " << i << " is " << pow(2, i) - 1 << "\n";
    }
    node = rand() % 5;
    for (int i = 1; i <= n; i++)
    {
        cout << "Maximum number of nodes on level " << i << " of a " << node
             << " - ary  tree is " << pow(node, i - 1) << "\n";
    }
    for (int i = 1; i <= n; i++)
    {
        cout << "Maximum number of nodes  of a " << node
             << " tree of depth " << i << " is " << pow(node, i) - 1 << "\n";
    }

    for (int i = 0; i < 5; i++)
    {
        temp = rand() % 20;
        if (parent(temp) == 0)
        {
            cout << "parent of " << temp << " is " << parent(temp)<< "\n";
        }
        else 
        cout << "This node is root node\n";
    }

    for (int i = 0; i < 5; i++)
    {
        temp = rand() % 10;
        node = rand() % 20;
        if (Lchild(temp, node) != 0)
        {
            cout << "Left child of " << temp << " is " << parent(temp)<< "\n";
        }
        else
            cout << "Has no left child\n";
    }
    for (int i = 0; i < 5; i++)
    {
        temp = rand() % 10;
        node = rand() % 20;
        if (Rchild(temp, node) != 0)
        {
            cout << "Right child of " << temp << " is " <<Rchild(temp, node) << "\n";
        }
        else
            cout << "Has no Right child\n";
    }
}
/*
Maximum number of nodes on level 1 of a binaray tree is 1
Maximum number of nodes on level 2 of a binaray tree is 2
Maximum number of nodes on level 3 of a binaray tree is 4
Maximum number of nodes on level 4 of a binaray tree is 8
Maximum number of nodes on level 5 of a binaray tree is 16
Maximum number of nodes in a binray tree of depth 1 is 1
Maximum number of nodes in a binray tree of depth 2 is 3
Maximum number of nodes in a binray tree of depth 3 is 7
Maximum number of nodes in a binray tree of depth 4 is 15
Maximum number of nodes in a binray tree of depth 5 is 31
Maximum number of nodes on level 1 of a 3 - ary  tree is 1
Maximum number of nodes on level 2 of a 3 - ary  tree is 3
Maximum number of nodes on level 3 of a 3 - ary  tree is 9
Maximum number of nodes on level 4 of a 3 - ary  tree is 27
Maximum number of nodes on level 5 of a 3 - ary  tree is 81
Maximum number of nodes  of a 3 tree of depth 1 is 2
Maximum number of nodes  of a 3 tree of depth 2 is 8
Maximum number of nodes  of a 3 tree of depth 3 is 26
Maximum number of nodes  of a 3 tree of depth 4 is 80
Maximum number of nodes  of a 3 tree of depth 5 is 242
parent of 0 is 0
This node is root node
This node is root node
This node is root node
This node is root node
Has no left child
Left child of 4 is 2
Has no left child
Left child of 1 is 1
Has no left child
Right child of 3 is 7
Right child of 2 is 5
Has no Right child
Has no Right child
Right child of 0 is 1
*/