/*
Page 99
Present an algorithm to start with an initially empty binary search tree
and make n random insertion. Use a unifrom random number generator to obtain the values to be
inserted. Measure the height of the resulting binary search tree and divide this height by log2n.
Do this for n = 100,500,1000,2000,30000,10000. Plot the ratio height/log2n as a function on n, The
ratio should be approximately constant (around) Verify that this is so;
*/
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
#define SPACE 10
int static COUNT;
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
    cout << i++ << "\tRatio\n";
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
            for (int i = 0; i < 1000; i++)
            {
                item = rand() % 1000;
                INSERT(&ROOT, item);
            }
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
        case 5:
            cout << "Count ratio\n";
            for (int j = 0; j < 10; j++)
            {
                for (int i = 0; i < 1000; i++)
                {
                    item = rand() % 1000;
                    INSERT(&ROOT, item);
                }
                cout << "\n"
                     << (j+1) * 100 << " " << FindHeight(ROOT)/log2((j+1) * 100) << "\n";
            }
            break;

        default:
            exit(0);
            break;
        }
    } while (option);
    return 0;
}
/*
********************************
1       Insert data
2       Show data in Tree       
3       Delete data in Tree     
4       Search Key
5       Ratio

********************************
->      5
Count ratio

100 1.95669

200 1.96236

300 1.82286

400 1.73534

500 1.67303

600 1.62534

700 1.5871

800 1.55539

900 1.52846

1000 1.50515

********************************
1       Insert data
2       Show data in Tree
3       Delete data in Tree
4       Search Key
5       Ratio

********************************
*/