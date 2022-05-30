/*
Page 338
08.
Write a non recursive algorithm for the inorder traversal of a binary tree T.
Your algorithm may use a stack. What are the time and space requirements of your
algorithm?
*/
// C++ program to print inorder traversal
// using stack.
#include <bits/stdc++.h>
using namespace std;

/* A binary tree Node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void Preorder(Node *root)
{
    // Base Case
    if (root == NULL)
        return;

    // Create an empty stack and push root to it
    stack<Node *> NodeStack;
    NodeStack.push(root);
    while (NodeStack.empty() == false)
    {
        // Pop the top item from stack and print it
        struct Node *Node = NodeStack.top();
        printf("%d ", Node->data);
        NodeStack.pop();

        // Push right and left children of the popped Node to stack
        if (Node->right)
            NodeStack.push(Node->right);
        if (Node->left)
            NodeStack.push(Node->left);
    }
}
/* Driver program to test above functions*/
int main()
{

    /* Constructed binary tree is
              1
            /   \
          2      3
        /  \
      4     5
    */
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Preorder(root);
    return 0;
}
/*
1 2 4 5 3
*/