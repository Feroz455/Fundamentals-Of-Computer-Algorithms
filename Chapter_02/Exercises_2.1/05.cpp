/*
Let X = (X1, ,,,,,, Xn) and Y = (Y1,,,,,,,,Yn) be two linked lists. Write an algorithm to merge
the two list to obtain the linked list Z = (x1, y1, x2, y2 ,,,,,,,,,,,,,,,xm, ym, xm+1, ym+1)
if m <= n or Z = (x1, y1, x, y2 ................xn, yn, yn+1, ,,,,,,ym) if m > n;

bool Add_list(NODE **X, NODE **Y, NODE **Z)
{
    NODE *tempX = *X, *tempY = *Y;
    if (tempX != NULL || tempY != NULL)
    {
        while (tempX != NULL || tempY != NULL)
        {
            if (tempX != NULL)
            {
                Add(tempX->data, Z);
                tempX = tempX->link;
            }
            if (tempY != NULL)
            {
                Add(tempY->data, Z);
                tempY = tempY->link;
            }
        }
        return true;
    }
    else
    cout << "List is empty\n";
    return false;
}
*/
#include <iostream>
#include <ctime>
using namespace std;
struct NODE
{
    int data;
    NODE *link;
};
bool Add(int item, NODE **top)
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
void PRINT(NODE **HEAE)
{
    NODE *temp = *HEAE;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->link;
    }
}
bool Add_list(NODE **X, NODE **Y, NODE **Z)
{
    NODE *tempX = *X, *tempY = *Y;
    if (tempX != NULL || tempY != NULL)
    {
        while (tempX != NULL || tempY != NULL)
        {
            if (tempX != NULL)
            {
                Add(tempX->data, Z);
                tempX = tempX->link;
            }
            if (tempY != NULL)
            {
                Add(tempY->data, Z);
                tempY = tempY->link;
            }
        }
        return true;
    }
    else
        cout << "List is empty\n";
    return false;
}
int main()
{
    srand(time(0));
    NODE *X = NULL, *Y = NULL, *Z = NULL;
    int item = 0;
    for (int i = 0; i < 10; i++)
    {
        item = rand() % 20;
        Add(item, &X);
        item = rand() % 20;
        Add(item, &Y);
    }
    cout << "\n";
    PRINT(&X);
    cout << "\n";
    PRINT(&Y);

    Add_list(&X, &Y, &Z);
    cout << "\n";
    PRINT(&Z);
    return 0;
}
/*
9 11 6 15 13 11 16 6 3 11
14 2 16 18 12 8 19 19 1 7
7 11 1 3 19 6 19 16 8 11 12 13 18 15 16 6 2 11 14 9
*/