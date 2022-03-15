/*
Page 85
Algorithm 2.3 Basic queue operation

//Algorithm
Add(item)
//Insert item in the circular queue store in q[0;n-1];
//Rear points to the last item, and front is one
//position counterclockwise from the first item in q
{
    rear := (rear+1) mod n; // Advance rear clockwise
    if(front == rear) then
    {
        cout << "Queue is full";
        if(front = 0) then rear := n - 1;
        else
        rear := rear - 1;
        //Move rear one position counterclockwise
        return false;
    }
    else
    {
        q[rear] := item; // inset new item;
        return true;
    }
}
********************Addition of an element ********************

Algorithm DeleteQ(item)
//Remove and return the front element of the queue q[0:n-1];
{
    if(front == rear) then
    {
        write ("Queue is empty!");
        return flase;S
    }
    else
    {
        front := (front + 1) mod n; // advance front clockwise
        item := q[front]; // Set item to front queue
        return true;
    }

}
********************Deletion of an element
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
int main()
{
    srand(time(0));
    N = rand() % 20;
    int item;
    for (int i = 0; i < N; i++)
    {
        item = rand() % 20;
        if (Add(item))
            cout << item << " ";
    }
    for (int i = 0; i <= N; i++)
    {
        if (Delete(item))
            cout << item << " ";
    }
    return 0;
}
/*
17 3 15 10 14 16 10 10 15 18 9 18 16 9 2 18 12 19 
Queue is full
17 3 15 10 14 16 10 10 15 18 9 18 16 9 2 18 12 19 
Queue is empty

Queue is empty
*/