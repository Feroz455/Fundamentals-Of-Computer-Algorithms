/*
page 338
10) Triple Order Traversal
*/
#include <iostream>
#include <stack>
using namespace std;

// Data structure to store a binary tree node
struct Node
{
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

// Function to print Triple Order traversal
void tripleOrderTraversal(struct Node *root)
{
    if (root)
    {

        // Print the current node
        cout << root->data << " ";

        // Traverse left subtree
        tripleOrderTraversal(root->left);

        // Print the current node
        cout << root->data << " ";

        // Traverse right subtree
        tripleOrderTraversal(root->right);

        // Print the current node
        cout << root->data << " ";
    }
}
int main()
{
    /* Construct the following tree
               1
             /   \
            /     \
           2       3
          /      /   \
         /      /     \
        4      5       6
              / \
             /   \
            7     8
    */

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
    cout << "\n";
    tripleOrderTraversal(root);

    return 0;
}
/*
4 2 1 7 5 8 3 6
1 2 4 4 4 2 2 1 3 5 7 7 7 5 8 8 8 5 3 6 6 6 3 1
*/