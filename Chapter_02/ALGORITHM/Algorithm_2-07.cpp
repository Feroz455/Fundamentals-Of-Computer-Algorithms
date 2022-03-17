/*
Page 97
Algorithm 2.7 Insertion into a binary search tree

Algorithm Insert(x)
//Insert x into the binary search tree
{
    found := false;
    p := tree;
    //Search for x, q is the parent of p
    while((p != 0) and not found) do
    {
        q := p // save p;
        if(x = (p->data)) then found := true;
        else if(x < p->data) then p := (p->lchild);
        else p := (p->rchild);
    }

    //Perform insertion
    if(not found) then
    {
        p := new TreeNode;
        (p->lchild) := 0; (p->rchild) := 0; (p->data) := x;
        if(tree != 0) then
        {
            if(x<(q->data)) then (q->lchild) := p;
            else (q->rchild) := p;
        }
        else tree := p;
    }
}
*/
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

struct NODE
{
    int key;
    NODE *left, *right;
};

NODE *newNODE(int item)
{
    NODE *temp = new NODE;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct NODE *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

NODE *insert(NODE *node, int key)
{
    if (node == NULL)
        return newNODE(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}
void INSERT(int x, NODE *tree)
{
    bool found = false;
    NODE *p = tree, *q;
    // Search for x , q is the parent of p
    while ((p != NULL) && !found)
    {
        q = p; // Save p
        if (x == (p->key))
        {
            found = true;
        }
        else if (x < (p->key))
        {
            p = p->left;
        }
        else
        {
            p = p->right;
        }
    }
    // Perform insertion;
    if (!found)
    {
        p = new NODE;
        p->left = NULL;
        p->right = NULL;
        p->key = x;
        if (tree != NULL)
        {
            if (x < q->key)
                q->left = p;
            else
                q->right = p;
        }
    }
}
int main()
{
    NODE *root = NULL;
    root = insert(root, 50);
    INSERT(20, root);
    INSERT(30, root);
    INSERT(40, root);
    INSERT(50, root);
    INSERT(60, root);
    INSERT(35, root);
    INSERT(35, root);
    INSERT(35, root);
    INSERT(35, root);
    INSERT(35, root);
    INSERT(35, root);

    inorder(root);
    return 0;
}
/*
20 30 35 40 50 60
*/