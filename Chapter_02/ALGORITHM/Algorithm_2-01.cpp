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
#include <iostream>
#include <ctime>
using namespace std;
int N, top;
bool ADD(int stack[], int item)
{
    if (top >= N)
    {
        cout << "\nStack is full\n";
        return false;
    }
    else
    {
        top = top + 1;
        stack[top] = item;
        return true;
    }
}
bool DELETE(int stack[], int &item)
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
    cout << N << "\n";

    int temp, stack[N], item;
    for (int i = 0; i <= N; i++)
    {
        temp = rand() % 20;
        if (ADD(stack, temp))
            cout << temp << " ";
    }
    cout << "\n";
    for (int i = 0; i <= N; i++)
    {
        if (DELETE(stack, item))
            cout << item << " ";
    }
    return 0;
}
/*
15
4 11 9 18 14 2 10 19 4 2 2 14 17 7 2
Stack is full

2 7 17 14 2 2 4 19 10 2 14 18 9 11 4
Stack is empty
*/