/*
Page 81



Algorithm Add(item)
//push an element onto the stack. Return true if successfull
//else return false. item is used as an input
{
    if(top >= n - 1) then
    {
        write("Stack is full!!");
        return false;
    }
    else
    {
        top := top+1;
        stack[top] := item;
        return true;
    }
}



Algorithm Delete(item)
//Pop the top element from the stack. Return true if successfull
//Else return false. item is used as an output;
{
    if(top < 0) then
    {
        write("Stack is empty");
        return false;
    }
    else
    {
        item := stack[top];
        top = top - 1;
        return true;
    }
}
*/
/*
Page 84
Modify the array implemention of a stack(algorithm 2.1)
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
int N, top, m;
int *stack, *tt;
bool ADD(int item)
{
    m++;
    if (top > N)
    {
        int *tempStack;
        N = N * 2;
        tempStack = tt;
        stack = new int[N];
        tt = stack;
        for (int i = 1; i <= top; i++)
        {
            stack[i] = tempStack[i];
        }
        delete tempStack;
        cout << "\nStack was new your stack is 2 times bigger then previous\n";
        goto position;
    }
    else
    {
    position:
        top = top + 1;
        stack[top] = item;
        return true;
    }
}
bool DELETE(int &item)
{
    if (top <= 0)
    {
        cout << "\nStack is empty\n";
        return false;
    }
    else
    {
        item = stack[top];
        top = top - 1;
        return true;
    }
}
int main()
{
    srand(time(0));
    N = rand() % 20;
    int MM = N;
    cout << N << "\n";
    int temp, item;
    stack = new int[N];
    tt = stack;
    for (int i = 0; i < MM; i++)
    {
        temp = rand() % 20;
        ADD(temp);
    }
    cout << "\n";
    for (int i = 0; i <= MM; i++)
    {
        if (DELETE(item))
            cout << item << " ";
    }
    cout << "\n Add() time " << m;
    return 0;
}
/*
15
3 4 13 7 16 13 9 3 19 9 16 11 8 1 1
1 1 8 11 16 9 19 3 9 13 16 7 13 4 3
Stack is empty
*/