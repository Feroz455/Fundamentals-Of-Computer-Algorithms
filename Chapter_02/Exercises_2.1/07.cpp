/*
Page 86
Consider the hypothetical data object X2. The object X2 is a linear list with the restriction that
although addition to the list can be made at either end, deletion can be made from one end only.
Design a linked list represention for X2, Specify initial and boundary condition for your
representation
*/
#include <iostream>
#include <ctime>
using namespace std;
struct NODE
{
    int data;
    NODE *link;
};
bool Add_front(int item, NODE **top)
{
    NODE *temp = new NODE;
    if (temp != NULL)
    {
        temp->data = item;
        temp->link = *top;
        *top = temp;
        return true;
    }
    else
    {
        cout << "\nOut of space!\n";
        return false;
    }
}
void Add_back(int item, NODE **HEAD)
{
    NODE *temp = *HEAD;
    NODE *temp1 = new NODE;
    temp1->data = item;
    temp1->link = NULL;
    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = temp1;
}
void PRINT(NODE **HEAD)
{
    NODE *temp = *HEAD;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->link;
    }
}
bool Delete(int &item, NODE **top)
{
    NODE *temp;
    if (top == NULL)
    {
        cout << "\nStack is empty\n";
        return false;
    }
    else
    {
        item = (*top)->data;
        temp = *top;
        *top = (*top)->link;
        delete temp;
        return true;
    }
}
int main()
{
    srand(time(0));
    NODE *X = NULL;
    int item = 0;
    for (int i = 0; i < 5; i++)
    {
        item = i;
        Add_front(item, &X);
    }
    for (int i = 5; i < 10; i++)
    {
        item = i;
        Add_back(item, &X);
    }
    while (Delete(item, &X))
    {
        cout << item << " ";
    }
    return 0;
}
/*
output
4 3 2 1 0 5 6 7 8 9 
*/