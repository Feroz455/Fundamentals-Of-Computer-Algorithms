/*
page 192

a) What test data would you use to determine worst-case and average times for selec4;


*/

#include <iostream>
#include <ctime>
#include <cmath>
#include <queue>
#include <iomanip>
using namespace std;
void PrintArray(int array[], int size)
{
    for (int i = 1; i < size; i++)
    {
        cout << setw(3) << array[i] << " ";
    }
    cout << "\n";
}
void select4(int array[], int size)
{
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i < size; i++)
    {
        q.push(array[i]);
    }
    for (int i = 1; i < size; i++)
    {
        array[i] = q.top();
        q.pop();
    }
}
int main()
{
    srand(time(0));
    int size = 20;
    int array[size];

    for (int i = 1; i < size; i++)
    {
        array[i] = size - i;
    }
    PrintArray(array, size);
    select4(array, size);
    PrintArray(array, size);
    return 0;
}
/*
average case
30  33  49  12  14  14  10  49  10  25  14  43  35   0  23   5  48   9   7 
  0   5   7   9  10  10  12  14  14  14  23  25  30  33  35  43  48  49  49


worst case
19  18  17  16  15  14  13  12  11  10   9   8   7   6   5   4   3   2   1 
1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19 
*/