#include <iostream>
using namespace std;
#define MAX 200
int *x1;
int *x2;

int number = 0;

int *xOrder;    // The order of operations;
int *bestOrder; // The optimal order of operations;

int bestValue = MAX;

int xValue = 0;

int f1 = 0;
int *f2;

void BackTrace(int k)
{
    if (k > number)
    {
        for (int i = 1; i <= number; i++)
        {
            bestOrder[i] = xOrder[i];
        }
        bestValue = xValue;
    }
    else
    {
        for (int i = k; i <= number; i++)
        {
            f1 += x1[xOrder[i]];
            f2[k] = (f2[k - 1] > f1 ? f2[k - 1] : f1) + x2[xOrder[i]];
            xValue += f2[k];
            swap(xOrder[i], xOrder[k]);
            if (xValue < bestValue)
            {
                BackTrace(k + 1);
            }
            swap(xOrder[i], xOrder[k]);
            xValue -= f2[k];
            f1 -= x1[xOrder[i]];
        }
    }
}
int main()
{
    cout << " Please enter the number of jobs: ";
    cin >> number;
    x1 = new int[number + 1];
    x2 = new int[number + 1];
    xOrder = new int[number + 1];
    bestOrder = new int[number + 1];
    f2 = new int[number + 1];

    x1[0] = 0;
    x2[0] = 0;
    xOrder[0] = 0;
    bestOrder[0] = 0;
    f2[0] = 0;

    cout << " Please enter the time spent on machine 1 for each job: " << endl;
    for (int i = 1; i <= number; i++)
    {
        cout << " first " << i << " jobs= ";
        cin >> x1[i];
    }

    cout << " Please enter the time spent on machine 2 for each job: " << endl;
    for (int i = 1; i <= number; i++)
    {
        cout << " first " << i << " jobs= ";
        cin >> x2[i];
    }

    for (int i = 1; i <= number; i++)
    {
        xOrder[i] = i;
    }
    BackTrace(1);
    cout << " most time saved is: " << bestValue;
    cout << endl;
    cout << "The corresponding scheme is: ";
    for (int i = 1; i <= number; i++)
    {
        cout << bestOrder[i] << "   ";
    }
    return 0;
}