/*
A double-ended queue(deque) is a linear list for which inserttios and deletion can occure at either
end. Show how to represent a deque in a ondimentional array and write agorithm that insert and delete
at either end;
*/
#include <iostream>
#include <ctime>
using namespace std;
int front, rear, N, q[1000];
bool Push_Back(int item)
{
    rear = (rear + 1) % N;
    if (front == rear)
    {
        cout << "\nQueue is full\n";
        if (front == 0)
        {
            rear = N - 1;
        }
        else
            rear = rear - 1;
        return false;
    }
    else
    {
        q[rear] = item;
        return true;
    }
}
bool Push_Front(int item)
{
    rear = (rear + 1) % N;
    if (front == rear)
    {
        cout << "\nQueue is full\n";
        if (front == 0)
        {
            rear = N - 1;
        }
        else
            rear = rear - 1;
        return false;
    }
    else
    {
        if (front == 0)
        {
            q[front] = item;
            front = N - 1;
            rear = rear - 1;
        }
        else
        {
            rear = rear - 1;
            q[front] = item;
            front = front - 1;
        }
        return true;
    }
}
bool Pop(int &item)
{
    if (front == rear)
    {
        cout << "\nQueue is empty\n";
        return false;
    }
    else
    {
        front = (front + 1) % N;
        item = q[front];
        return true;
    }
}
bool Pop_Back(int &item)
{
    if (front == rear)
    {
        cout << "\nQueue is empty\n";
        return false;
    }
    else
    {
        if (rear == 0)
        {
            item = q[rear];
            rear = N - 1;
        }
        else
        {
            item = q[rear];
            rear--;
        }
        return true;
    }
}
int main()
{
    srand(time(0));
    N = 15;
    int item;
    for (int i = 0; i < 5; i++)
    {
        Push_Back(i);
    }
    for (int i = 5; i < 10; i++)
    {
        Push_Front(i);
    }
    for (int i = 0; i < 5; i++)
    {
        Pop(item);
        cout << item << " ";
    }
    cout << "\n\n";
    for (int i = 0; i < 5; i++)
    {
        Pop_Back(item);
        cout << item << " ";
    }

    return 0;
}
/*
9 8 7 6 5

4 3 2 1 0
*/