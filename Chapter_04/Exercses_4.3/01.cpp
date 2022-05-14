/*
Page 222

1)
a) Find an optimal solution to the knapsack instance n = 7, m 15;
, (p1, p2, ....p7) = (10,5,15,7,6,18,3) and (w1, w2, ....w7) = (2,3,5,7,1,4,1);

b) Let F(i) be the value of the solution generated on the problem instance I by GreedyKnapsack when the
obeject are input in non-incresing order of the pi's, Let F*(i) be the value an optiomal
solution for this instance. How large can the ratio F * (I) / F(I) get;

c) Answer (b) for the case in which the input is in nondecresing order of the wi's
*/
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
/***********************************/
template <typename T>
void PrintArray(T array[], int size);
template <typename T>
void Swap(T &a, T &b);
void knapsack(float weight[], float profit[], float capacity, int object);
void Sort(float profit[], float weight[], float ratio[], int size);
/***********************************/
// Main start here
int main()
{
    int size = 20;
    float weight[size], profit[size], capacity, ratio[size], temp;
    int object, i, j;

    cout << "Enter the number of object-: \t";
    cin >> object;

    cout << "\nEnter the capacity of knapsack:- \t";
    cin >> capacity;

    cout << "\nEnter weight  and Profit of each object:- \n";
    for (i = 0; i < object; i++)
    {
        cin >> weight[i] >> profit[i];
    }

    for (i = 0; i < object; i++)
    {
        ratio[i] = profit[i] / weight[i];
    }
    cout << "Before sort \n";
    PrintArray<float>(ratio, object);
    PrintArray<float>(weight, object);
    PrintArray<float>(profit, object);

    Sort(profit, weight, ratio, object);
    cout << "After sort \n";

    PrintArray<float>(ratio, object);
    PrintArray<float>(weight, object);
    PrintArray<float>(profit, object);

    knapsack(weight, profit, capacity, object);
}

template <typename T>
void Swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}
template <typename T>
void PrintArray(T array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << setw(6) << array[i] << " ";
    }
    cout << "\n";
}
// We bubble sort
void Sort(float profit[], float weight[], float ratio[], int size)
{
    int i, j;
    float temp;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (ratio[j] < ratio[j + 1])
            {
                Swap<float>(ratio[j], ratio[j + 1]);
                Swap<float>(weight[j], weight[j + 1]);
                Swap<float>(profit[j], profit[j + 1]);
            }
        }
    }
}

void knapsack(float weight[], float profit[], float capacity, int object)
{
    float x[20] = {0.0}, final_Value = 0.0, Wgt;
    int i, j;
    Wgt = capacity;

    for (i = 0; i < object; i++)
    {

        if (weight[i] <= Wgt)
        {
            Wgt -= weight[i];
            x[i] = 1.0;
            final_Value += profit[i];
        }
        else
        {

            x[i] = ((double)Wgt / (double)weight[i]);
            final_Value += profit[i] * ((double)Wgt / (double)weight[i]);
            break;
        }
    }
    PrintArray<float>(x, object);
    cout << "Maximum Profit is:-  " << final_Value << "\n";
}

/*
Enter the number of object-:    7
Enter the capacity of knapsack:-   15
Enter the weight of and Profit of each object:-
2 10
3 5
5 15
7 7
1 6
4 18
1 3


6 5 4.5 3 3 1.66667 1
1 2 4 5 1 3 7
6 10 18 15 3 5 7
1 1 1 1 1 0.666667 0
Maximum Profit is:-  55.3333
*/