/*
page 99
Write an algorithm to delelte an elemenet x from a binaray search tree T.
What is the time complexity of your algorithm.
*/
#include <iostream>
#include <ctime>
using namespace std;
#define SPACE 10
struct TreeNode
{
    int data;
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
void In_order(TreeNode *root)
{
    if (root != NULL)
    {
        In_order(root->lchild);
        cout << root->data << " ";
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
    cout << root->data << "\n";
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
    return root;
}
void option()
{
    int i = 1;
    cout << "\n********************************\n";
    cout << i++ << "\tInsert data\n";
    cout << i++ << "\tShow data in Tree\n";
    cout << i++ << "\tDelete data in Tree\n";
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
            item = rand() % 20;
            INSERT(&ROOT, item);
            break;
        case 2:
            cout << "Show Data\n";
            In_order(ROOT);
            cout << "\n";
            break;

        case 3:
            cout << "Enter key to delete\n";
            cin >> item;
            DELETE(ROOT, item);
        default:
        exit(0);
            break;
        }
    } while (option);
    return 0;
}