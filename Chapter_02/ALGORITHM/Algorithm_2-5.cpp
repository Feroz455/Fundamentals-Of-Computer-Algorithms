/*
page 95
Algorithm 2.5 Iterative search of a binaray search tree

Algorithm Search(x)
{
    fount = false;
    t := tree;
    while((t != 0) and not found) do
    {
        if(x = (t->data)) then found := true;
        else if(x<(t->data)) then t := (t->lchild);
        else t := (t -> rchild);
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

NODE *Search(NODE *node, int x)
{
    bool found = false;
    NODE *t = node;
    while ((t != NULL) && !found)
    {
        if ((t->key) == x)
        {
            found = true;
        }
        else if (x < (t->key))
        {
            t = t->left;
        }
        else
            t = t->right;
    }
    if (!found)
    {
        return NULL;
    }
    else
        return t;
}
int main()
{
    NODE *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    inorder(root);
    if (Search(root, 100) != NULL)
    {
        cout << "\nKEY FOUND\n";
    }
    else
        cout << "\nKEY NOT FOUND\n";

    return 0;
}
/*
20 30 40 50 60 70 80
KEY NOT FOUN
*/