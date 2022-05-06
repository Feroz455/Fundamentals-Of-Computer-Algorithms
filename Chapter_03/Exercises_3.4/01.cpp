/*
Page 158
1. Translate algorithm MaxMin into a computationally equivalent processdure that uses no recursion.
*/
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
int array[1000];
void MaxMin(int i, int j, int &max, int &min)
{
    int min1, max1, mid;

    if (i >= (j - 1))
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
            max = max1;

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