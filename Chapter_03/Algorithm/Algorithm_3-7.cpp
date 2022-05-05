/*
page 156
Algorithm MaxMin(i, j, max, min)
//a[1:n] is a global array. Parameters i and j are intergers
//a <= i <= j <= n.The effect is to set max and min to the
//largest and smallest values in a[i:j] respectively
{
    if(i == j)
    max = min = a[i]; // Small(p)
    else
    if(i == (j-1))
    {
        if(a[i] < a [j])
        {
            max = a[j];
            min = a[i];
        }
        else
        {
            max = a[i];
            min = a[j];
        }
    }
    else
    {
        //If P is not small, divide p into subProblems
        //Find where to split the set
        mid = floor((i+j))/2;
        //Solve the subproblems
        MaxMin(i, mid, max, min);
        MaxMin(mid+1, j, max1, min1);
        //combine the solutions
        if(max < max1)
        {
            max = max1;
        }
        if(min > min1)
        min = min1;
    }
}
*/

#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
int array[1000];
void MaxMin(int i, int j, int &max, int &min)
{
    int min1, max1, mid;
    if (i == j)
        max = min = array[i]; // Small(p)
    else if (i == (j - 1))
    {
        if (array[i] < array[j])
        {
            max = array[j];
            min = array[i];
        }
        else
        {
            max = array[i];
            min = array[j];
        }
    }
    else
    {
        // If P is not small, divide p into subProblems
        // Find where to split the set
        mid = floor((i + j)) / 2;
        // Solve the subproblems
        MaxMin(i, mid, max, min);
        MaxMin(mid + 1, j, max1, min1);
        // combine the solutions
        if (max < max1)
        {
            max = max1;
        }
        if (min > min1)
            min = min1;
    }
}
int main()
{
    srand(time(0));
    int size = 20;
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 50;
        cout << array[i] << " ";
    }
    cout << "\n";
    int max, min;
    MaxMin(0, size - 1, max, min);
    cout << "MAX value -> " << max << "\n";
    cout << "Min value -> " << min << "\n";
    return 0;
}
/*
20 9 10 38 36 40 1 36 14 46 31 27 42 43 6 11 16 37 13 30 
MAX value -> 46
Min value -> 1
*/