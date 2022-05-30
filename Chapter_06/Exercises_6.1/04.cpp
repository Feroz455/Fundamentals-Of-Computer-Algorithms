/*
Page 337
04. Show the following
a) Inorder and postorder sequences of a binary tree uniquely define the binary tree
b) Inorder and preorder sequences of a binary tree uniquely define the binary tree
c) PreOrder and post order sequence of a binary tree do not uniquely define the binary tree.
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

/* Given a binary tree, print its nodes according to the
"bottom-up" postorder traversal. */
void printPostorder(struct Node *node)
{
    if (node != NULL)
    {
        // first recur on left subtree
        printPostorder(node->left);

        // then recur on right subtree
        printPostorder(node->right);

        // now deal with the node
        cout << node->data << " ";
    }
}

/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct Node *node)
{
    if (node != NULL)
    {
        /* first recur on left child */
        printInorder(node->left);

        /* then print the data of node */
        cout << node->data << " ";

        /* now recur on right child */
        printInorder(node->right);
    }
}

/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct Node *node)
{
    if (node != NULL)
    {
        /* first print data of node */
        cout << node->data << " ";

        /* then recur on left subtree */
        printPreorder(node->left);

        /* now recur on right subtree */
        printPreorder(node->right);
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

    cout << "\nPreorder traversal of binary tree is \n";
    printPreorder(root);

    cout << "\nInorder traversal of binary tree is \n";
    printInorder(root);

    cout << "\nPostorder traversal of binary tree is \n";
    printPostorder(root);

    return 0;
}
/*
Preorder traversal of binary tree is
1 2 4 5 3
Inorder traversal of binary tree is
4 2 5 1 3
Postorder traversal of binary tree is
4 5 2 3 1
*/