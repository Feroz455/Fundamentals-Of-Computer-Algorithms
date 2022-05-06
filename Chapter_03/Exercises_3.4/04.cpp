/*
page 159
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

4. In algorithm 3.7 what happens if lines 7 to 17 are droped? Does 
the resultant function still compute the maximum and minimum elements correctly ?
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
yes it does
6 47 9 35 1 23 34 23 16 27 48 36 8 5 26 35 48 28 39 17 
MAX value -> 48
Min value -> 1
*/