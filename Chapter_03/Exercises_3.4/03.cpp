/*
page 159

3.
There is an iterative algorithm for finding the maximum and minimum which, though not a divide-and-conquer
based algorithm, is probly more efficient than MaxMin. It works by comparing consecutive pairs of elelements
and then comparing the larger one with the current maximum and the smaller one with the current minimum.
Write the algorithm completely and analyze the number of comparaison it requires.
*/
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
int array[1000];
int count1, count2;

void StraightMaxMin(int array[], int n, int &max, int &min)
{
    max = min = array[0];
    for (int i = 1; i < n; i++)
    {

        if (array[i] > max)
        {
            max = array[i];
        }
        else if (array[i] < min)
        {
            min = array[i];
        }
        count2 += 3;
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

    StraightMaxMin(array, size - 1, max, min);
    cout << "MAX value -> " << max << "\n";
    cout << "Min value -> " << min << "\n";
    cout << "StrightMaxMin comparison -> " << count2 << "\n";
    return 0;
}
/*
49 27 5 13 33 1 20 48 20 36 25 4 17 43 32 0 0 9 34 29
MAX value -> 49
Min value -> 0
StrightMaxMin comparison -> 54
*/