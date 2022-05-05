/*
page 154
Algorithm StraightMaxMin(a,n,max,min)
//Set max to the maximum and min to the minimun of a[1:n]
{
    max = min = a[1];
    for(i = 2 to n)
    {
        if(a[i] > max)
        max = a[i];
        if(a[i] min)
        min = a[i];
    }

}
*/

#include <iostream>
#include <ctime>
using namespace std;
void StraightMaxMin(int array[], int n, int &max, int &min)
{
    max = min = array[0];
    for (int i = 1; i < n; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
        if (array[i] < min)
        {
            min = array[i];
        }
    }
}
int main()
{
    srand(time(0));
    int size = 20, array[size];
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 50;
        cout << array[i] << " ";
    }
    cout << "\n";
    int max, min;
    StraightMaxMin(array, size, max, min);
    cout << "MAX value -> " << max << "\n";
    cout << "Min value -> " << min << "\n";
    return 0;
}
/*
12 13 2 14 43 6 0 1 30 46 20 36 39 38 1 28 8 3 44 13 
MAX value -> 46
Min value -> 0
*/