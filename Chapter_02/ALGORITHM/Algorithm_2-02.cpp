/*
Page 82


Algorithm 2.2 Linked representation of a stack

//Type is the type of data
node = record
{
    type data;
    node *link;
}


Algoithm Add(item)
{
    // Get a new node
    temp = new node;
    if(temp != 0) then
    {
        temp->data := item;
        (temp->link) := top;
        top := temp;
        return true;
    }
    else
    {
        cout << "Out of space!";
        return false;
    }
}

Algorithm Delete(item)
{
    if(top = 0) then
    {
        write("Stack is empty!");
        return false;
    }
    else
    {
        item := top->data;
        temp = top;
        top := top->link;
        delete temp;
        return true;
    }
}
*/
#include <iostream>
#include <ctime>
using namespace std;
struct Node
{
    int Data;
    Node *link;
};
Node *top = NULL;
bool Add(int item)
{
    Node *temp = new Node;
    if (temp != NULL)
    {
        temp->Data = item;
        temp->link = top;
        top = temp;
        return true;
    }
    else
    {
        cout << "\nOut of space!\n";
        return false;
    }
}
bool Delete(int &item)
{
    Node *temp;
    if (top == NULL)
    {
        cout << "\nStack is empty\n";
        return false;
    }
    else
    {
        item = top->Data;
        temp = top;
        top = top->link;
        delete temp;
        return true;
    }
}
int main()
{
    srand(time(0));
    int item, temp, N = rand() % 20;
    for (int i = 0; i < N; i++)
    {
        temp = rand() % 20;
        if (Add(temp))
            cout << temp << " ";
    }
    cout << '\n';
    for (int i = 0; i <= N; i++)
    {
        temp = rand() % 20;
        if (Delete(item))
            cout << item << " ";
    }
    cout << "\n";
    return 0;
}
/*
6 9 19 2 5 2 
2 5 2 19 9 6
Stack is empty
*/