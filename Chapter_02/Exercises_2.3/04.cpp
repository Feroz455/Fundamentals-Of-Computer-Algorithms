#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
#define SPACE 10
int static COUNT;
struct TreeNode
{
    int data;
    int leftSize;
    TreeNode *lchild;
    TreeNode *rchild;
};
TreeNode *NewNode(int data)
{
    TreeNode *temp = new TreeNode;
    temp->data = data;
    temp->lchild = temp->rchild = NULL;
    return temp;
}
int MAX(int x, int y)
{
    return (x > y ? x : y);
}
int FindHeight(TreeNode *node)
{
    if (node == NULL)
    {
        return -1;
    }
    else
        return MAX(FindHeight(node->lchild), FindHeight(node->rchild) + 1);
}
void INSERT(TreeNode **root, int DATA)
{
    if (*root == NULL)
    {
        *root = NewNode(DATA);
        return;
    }
    TreeNode *temp = *root, *parentNode = NULL;
    while (temp != NULL)
    {
        parentNode = temp;
        temp = (DATA > temp->data) ? temp->rchild : temp->lchild;
    }
    if (DATA > parentNode->data)
    {
        parentNode->rchild = NewNode(DATA);
    }
    else
        parentNode->lchild = NewNode(DATA);
}

TreeNode *insert(TreeNode *node, int key)
{
    if (node == NULL)
        return NewNode(key);
    if (key < node->data)
        node->lchild = insert(node->lchild, key);
    else if (key > node->data)
        node->rchild = insert(node->rchild, key);
    node->leftSize = FindHeight(node->lchild);
    return node;
}
void In_order(TreeNode *root)
{
    if (root != NULL)
    {
        In_order(root->lchild);
        cout << " (" << root->data << "," << root->leftSize << ") ";
        In_order(root->rchild);
    }
}
void print2D(TreeNode *root, int Space)
{
    if (root == NULL)
    {
        return;
    }
    Space += SPACE;
    print2D(root->rchild, Space);
    cout << endl;
    for (int i = SPACE; i < Space; i++)
    {
        cout << " ";
    }
    cout << " (" << root->data << "," << root->leftSize << ")\n";
    print2D(root->lchild, Space);
}
TreeNode *FindMin(TreeNode *root)
{
    while (root->lchild != NULL)
    {
        root = root->lchild;
    }
    return root;
}
TreeNode *DELETE(TreeNode *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (data < root->data)
    {
        root->lchild = DELETE(root->lchild, data);
    }
    else if (data > root->data)
    {
        root->rchild = DELETE(root->rchild, data);
    }
    else
    {
        // Case 1: NO child
        if (root->lchild == NULL && root->rchild == NULL)
        {
            delete root;
            return NULL;
        }
        // Case 2: One Child
        else if (root->lchild == NULL)
        {
            TreeNode *temp = root;
            root = root->lchild;
            delete temp;
        }
        else if (root->rchild == NULL)
        {
            TreeNode *temp = root;
            root = root->lchild;
            delete temp;
        }
        else
        {
            TreeNode *temp = FindMin(root->lchild);
            root->data = temp->data;
            root->rchild = DELETE(root->rchild, temp->data);
        }
    }
    root->leftSize = FindHeight(root->lchild);
    return root;
}

bool FIND(TreeNode *root, int key)
{

    TreeNode *temp = root;
    if (key == temp->data)
    {
        return true;
    }
    while ((temp != NULL) && temp->data != key)
    {
        COUNT++;
        temp = (key > temp->data) ? temp->rchild : temp->lchild;
    }
    if (temp == NULL)
    {
        return false;
    }
    return true;
}
void option()
{
    int i = 1;
    cout << "\n********************************\n";
    cout << i++ << "\tInsert data\n";
    cout << i++ << "\tShow data in Tree\n";
    cout << i++ << "\tDelete data in Tree\n";
    cout << i++ << "\tSearch Key\n";

    cout << "\n********************************\n->\t";
    return;
}
int main()
{
    srand(time(0));
    TreeNode *ROOT = NULL;
    int N = (rand() % 20) + 5, item, choice;
    do
    {
        option();
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Insert data\n";
            for (int i = 0; i < 10; i++)
            {
                item = rand() % 1000;
                ROOT = insert(ROOT, item);
            }
            break;
        case 2:
            cout << "Show Data\n";
            In_order(ROOT);
            cout << "\n";

            print2D(ROOT, 1);
            break;

        case 3:
            cout << "Enter key to delete\n";
            cin >> item;
            DELETE(ROOT, item);
            break;
        case 4:
            cout << "Enter Search key\n";
            cin >> item;
            COUNT = 0;
            if (FIND(ROOT, item))
            {
                cout << "KEY FOUND!!";
            }
            else
                cout << "KEY NOT FOUND!!";
            cout << "NUMBER OF COMPARISION\n"
                 << COUNT << "\n";
            break;

        default:
            exit(0);
            break;
        }
    } while (option);
    return 0;
}