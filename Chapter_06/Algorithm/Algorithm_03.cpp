/*
Page 339
Algorithm 6.3 Triple-Order traversal for Exercise 10


Algorithm void Triple(t)
{
    if(t != NULL)
    {
        cout << t->data;
        Triple(t->lchild);
        cout << t->data;
        Triple(t->rchild);
         cout << t->data;
    }
}
*/
// C++ program for different tree traversals
#include <iostream>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct Node
{
    int data;
    struct Node *left, *right;
};

// Utility function to create a new tree node
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
void Triple(struct Node *node)
{
    if (node != NULL)
    {
        /* first print data of node */
        cout << node->data << " ";
        Triple(node->left);
        cout << node->data << " ";
        Triple(node->right);
        cout << node->data << " ";
    }
}
/* Driver program to test above functions*/
int main()
{
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << "\nTriple traversal of binary tree is \n";
    Triple(root);

    return 0;
}
/*
Triple traversal of binary tree is 
1 2 4 4 4 2 5 5 5 2 1 3 3 3 1 
*/