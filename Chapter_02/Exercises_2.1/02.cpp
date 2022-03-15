/*
page 86
02. Do Exercises 1 for the array representation of a queue (Algorithm 2.3)

Modify the array implemention of a stack(algorithm 2.3)
so that when we are to add an element to a ful stack, an attemp is
made to double the size of the array. For this alloacte a new array
of twice the size and copy elements from the old array to the new one
The cost of array doubling is linear in the size of the new array



A) Test the correstness of your modifid stack class
B)Show that while the compluxety of an individual add is now O(m),
Where m is the size of the stack, the complexity of performing a sequenc of
m adds (possible with some deletes) is O(m);
*/
#include <iostream>
#include <ctime>
using namespace std;
bool Delete(int &item);
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
        N = N * 2;
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
    int item, LOOP;
    LOOP = N;
    cout << N << "\n";
    for (int i = 0; i < LOOP; i++)
    {
        item = rand() % 20;
        if (Add(item))
            cout << item << " ";
    }
    for (int i = 0; i < LOOP; i++)
    {
        item = rand() % 20;
        if (Add(item))
            cout << item << " ";
    }
    cout << "\n*******************\n";
    while (Delete(item))
        cout << item << " ";

    return 0;
}
/*
10
4 8 8 4 16 10 17 12 8   
Queue is full
13 2 10 8 8 12 8 5 16 5 
*******************     
4 8 8 4 16 10 17 12 8 13 2 10 8 8 12 8 5 16 5 
Queue is empty
*/