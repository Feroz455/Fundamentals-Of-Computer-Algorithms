/*
page 13
Devise an algorithm that inputs three integers and outputs them in nondecreasing oreder

*/
#include <iostream>
#include <ctime>
using namespace std;
void interchange(int &x, int &y)
{
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
}
void Selection_Sort(int A[], int N)
{
    int temp = 0;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (A[i] > A[j])
            {
                interchange(A[j], A[i]);
            }
        }
    }
}
int main()
{
    srand(time(0));
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    cout << "\nNon Decreasing order\n";
    Selection_Sort(A, N);
    for (int i = 0; i < N; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}
/*
output
3
11
4
5

Non Decreasing order
4 5 11
*/