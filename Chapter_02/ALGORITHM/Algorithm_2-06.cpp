/*
page 95
Algorithm 2.6 Searching a binaray search tree by rand;
Algorithm Search(k)
{
    found := false;
    t := tree;
    while((t!=0) and not found) do
    {
        if(k = (t->leftsize)) then found := true;
        else if(k < (t->leftsize)) then t := (t->lchild);
            else
            {
                k:=k-(t->leftsize);
                t = (t->rchild);
            }
    }
    if(not found) then return 0;
    else
    return t;
}
*/
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

struct NODE
{
    int key;
    int leftSize;
    NODE *left, *right;
};

NODE *newNODE(int item)
{
    NODE *temp = new NODE;
    temp->key = item;
    temp->leftSize = 1;
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
int size(NODE *node)
{
    if (node == NULL)
        return 0;
    else
        return (size(node->left) + 1 + size(node->right));
}
int RANK(int key, NODE *node)
{
    if (node == NULL)
        return 0;
    if (key < node->key)
        return RANK(key, node->left);
    else if (key > node->key)
        return 1 + size(node->left) + RANK(key, node->right);
    else
        return size(node->left);
}

NODE *insert(NODE *node, int key)
{
    if (node == NULL)
        return newNODE(key);
    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }
    return node;
}

NODE *Search(int k, NODE *node)
{
    bool found = false;
    NODE *t = node;
    while ((t != NULL) && !found)
    {
        if (k == size(t->left))
            found = true;
        else if (k < size(t->left))
            t = t->left;
        else
        {
            k = k - size(t->left);
            t = t->left;
        }
    }
    if (!found)
        return NULL;
    else
        return t;
}
int main()
{
    NODE *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 60);
    insert(root, 20);
    insert(root, 40);
    insert(root, 80);
    insert(root, 70);
    insert(root, 65);

    inorder(root);

    if (Search(3, root) != NULL)
    {
        cout << "\nRank found "  << Search(3,root)->key << "\n";
    }
    else
        cout << "\nRank Not found\n";
    return 0;
}
/*
20 30 40 50 60 65 70 80
Rank found
*/
