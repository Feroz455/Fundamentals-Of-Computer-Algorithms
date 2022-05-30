/*
page 339
Algorithm 6.4 A nonrecursive algorithm for the triple-order traversal for Exercise 10

Algoritm Trip(t)
//It is assumed that lchild and rchild fields are > 0
{
    p = t;
    q = -1;
    while(p!= -1)
    {
        visit(p);
        r = (p->lchild);
        (p->lchild) = (p->rchild);
        (p->rchild) = q;
        q = p;
        p = r;
    }
}*/

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

// Iterative function to perform inorder traversal on the tree
void inorderIterative(Node *root)
{
    // create an empty stack
    stack<Node *> stack;

    // start from the root node (set current node to the root node)
    Node *curr = root;

    // if the current node is null and the stack is also empty, we are done
    while (!stack.empty() || curr != nullptr)
    {
        // if the current node exists, push it into the stack (defer it)
        // and move to its left child
        if (curr != nullptr)
        {
            stack.push(curr);
            curr = curr->left;
        }
        else
        {
            // otherwise, if the current node is null, pop an element from the stack,
            // print it, and finally set the current node to its right child
            curr = stack.top();
            stack.pop();
            cout << curr->data << " ";

            curr = curr->right;
        }
    }
}
void Trip(Node *root)
{
    Node *p = root, *r;
    Node *q = NULL;
    while (p != NULL)
    {
        cout << p->data << " ";
        r = p->left;
        p->left = p->right;
        p->right = q;
        q = p;
        p = r;
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

    Trip(root);

    return 0;
}
/*
4 2 1 7 5 8 3 6
*/