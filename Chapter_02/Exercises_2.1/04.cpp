/*
Page 86
A linear list is being maintaind circularly in an array c[0:n-1] with
f and r set up as for circular queues.
A) Obtained a formula in terms of f, r, and n for the number of elements in the list.
B) Write an algorithm to delete the kth element in the list.

bool Delete_K(int &item, int position)
{
    if (front == rear)
    {
        cout << "\nQueue is empty\n";
        return false;
    }
    else
    {
        item = q[position];
        if (front == position)
        {
            front++;
        }
        else
        {
            for (int i = position; i < rear; i++)
            {
                q[i] = q[i + 1];
            }
            rear = rear - 1;
        }
        return true;
    }
}

C) Write an algorithm to insert an element y imidiately after the kth element.

bool Add_K(int item, int position)
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
        if (rear < position)
        {
            for (int i = rear; i > 0; i--)
            {
                q[i] = q[i - 1];
            }
            q[0] = q[N - 1];
            for (int i = N - 1; i > position; i--)
            {
                q[i] = q[i - 1];
            }
            q[position] = item;
        }

        for (int i = rear; i > position; i--)
        {
            q[i] = q[i - 1];
        }

        q[position] = item;
        return true;
    }
}

Write an alagorithm to insert an element y immediately after the kth element.
*/
#include <iostream>
#include <ctime>
using namespace std;
int front, rear, N, q[1000];
bool Add(int item)
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

bool Add_K(int item, int position)
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
        if (rear < position)
        {
            for (int i = rear; i > 0; i--)
            {
                q[i] = q[i - 1];
            }
            q[0] = q[N - 1];
            for (int i = N - 1; i > position; i--)
            {
                q[i] = q[i - 1];
            }
            q[position] = item;
        }

        for (int i = rear; i > position; i--)
        {
            q[i] = q[i - 1];
        }

        q[position] = item;
        return true;
    }
}

bool Delete(int &item)
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
bool Delete_K(int &item, int position)
{
    if (front == rear)
    {
        cout << "\nQueue is empty\n";
        return false;
    }
    else
    {
        item = q[position];
        if (front == position)
        {
            front++;
        }
        else
        {
            for (int i = position; i < rear; i++)
            {
                q[i] = q[i + 1];
            }
            rear = rear - 1;
        }
        return true;
    }
}
int main()
{
    srand(time(0));
    N = (rand() % 20) + 2;
    int item, temp1 = (rand() % N), temp2 = (rand() % N);
    for (int i = 0; i < N - 2; i++)
    {
        item = rand() % 20;
        if (Add(item))
            cout << item << " ";
    }

    item = rand() % 20;
    if (Add_K(item, temp2))
    {
        cout << temp2 << "\n";
    }

    while (Delete(item))
    {
        cout << item << " ";
    }

    cout << "\n";
    if (Delete_K(item, temp))
    {
        cout << "Position - > " << temp << " Deleted item " << item << "\n";
    }

    while (Delete(item))
    {
        cout << item << " ";
    }
    return 0;
}
/*
14 14 10 15 12 8 16 18 13 12 5 4 5
Queue is full

Deleted position ->  10
Position - > 10 Deleted item 12
14 14 10 15 12 8 16 18 13 5 4 5
Queue is empty
*/