/*
page 94
Algorithm 2.4
Reacursive search of a binary search tree;
Algorithm Search(t,x)
{
    if(t = 0) then return 0;
    else if(x = t->data) then return t;
        else if(x < t->data) then
            return Search(t->lchild,x);
            else return Search(t->rchild,x);
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
    if (node == NULL)
    {
        return NULL;
    }
    else if (x == node->key)
    {
        return node;
    }
    if (x < node->key)
    {
        return Search(node->left, x);
    }
    else
    {
        return Search(node->right, x);
    }
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