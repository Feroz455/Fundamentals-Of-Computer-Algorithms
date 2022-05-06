/*
page 158

Test your iterative version of MaxMin derived above against Straight MaxMin. Count All comparisons
*/
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
int array[1000];
int count1, count2;
void MaxMin(int i, int j, int &max, int &min)
{
    int min1, max1, mid;
    count1++;
    if (i >= (j - 1))
    {
        count1++;
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
        count1++;
        if (max < max1)
            max = max1;
        count1++;
        if (min > min1)
            min = min1;
    }
}
void StraightMaxMin(int array[], int n, int &max, int &min)
{
    max = min = array[0];
    for (int i = 1; i < n; i++, count2++)
    {

        count2++;
        if (array[i] > max)
        {
            max = array[i];
        }
        else if (array[i] < min)
        {
            min = array[i];
        }
        count2++;
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
    cout << "MaxMin comparison -> " << count1 << "\n";
    StraightMaxMin(array, size - 1, max, min);
    cout << "StrightMaxMin comparison -> " << count2 << "\n";
    return 0;
}
/*
33 46 4 25 45 43 4 42 3 7 46 4 14 28 5 33 39 30 0 39
MAX value -> 46
Min value -> 0
MaxMin comparison -> 57
StrightMaxMin comparison -> 54
*/