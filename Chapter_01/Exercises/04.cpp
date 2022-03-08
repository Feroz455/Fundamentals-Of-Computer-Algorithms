/*
Present an algorithm that searchs an unsorted array a[1:n] for the
elemets x. If x occurs, then return a position in the array;
else return zero;
*/
#include <iostream>
#include <ctime>
using namespace std;
int serach(int A[], int key, int N)
{
    int position = -1;
    for (int i = 0; i < N; i++)
    {
        if (key == A[i])
        {
            position = i + 1;
            break;
        }
    }
    return position;
}
int main()
{
    int N, key;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    cout << "Enter search key\n";
    cin >> key;
    int position = serach(A, key, N);
    if (position > -1)
        cout << "Item found at " << position;
    else
        cout << "Item not found\n";
    return 0;
}
/*
output
***********
5
15 42 62 24 54
Enter search key
62
Item found at 3
************
5
15 42 65 45
15
Enter search key
22
Item not found
*/