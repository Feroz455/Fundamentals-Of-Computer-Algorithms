/*
page 189

11. Given two vectors X = (x1,....xn) and Y = (y1,....yn), X < Y if there exists an i,
1 <= i <= n, such that xj = yj for i <= j < i and xi < yi.
Given m vectors each of size n, Write an algorithm that determines the minimum vetor.
Analyze the time complexity of your algorithm.

*/
#include <iostream>
#include <ctime>
using namespace std;
bool minimum(int X[], int Y[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (X[i] > Y[i])
            return false;
    }
    return true;
}
int main()
{
    srand(time(0));
    int size = 20;
    int X[size], Y[size];
    for (int i = 0; i < size; i++)
    {
        X[i] = rand() % 50;
        Y[i] = rand() % 50;
    }
    if (minimum(X, Y, size))
        cout << "X < Y";
    else
        cout << "X !< Y";

    return 0;
}

/*
time complexity
O(n);
*/