/*
page 20
Algorithm 1.8 Algorithm 1.6 with count statements added

Algorithm Sum(a , n)
{
    s := 0.0;
    count = count+1;// count is global; it is initially zero
    for i = 1 to n do
    {
        count := count + 1; // For for
        s := s + a[i];
        count := count + 1; // for assignment
    }
    count := count + 1; // For last time of for
    count := count + 1; // For return;
}
*/
#include <iostream>
#include <ctime>
using namespace std;
int count;
template <typename T>
T Sum(T A[], int N)
{
    T s = 0;
    count = count + 1; // count is global; it is initially zero
    for (int i = 0; i < N; i++)
    {
        count = count + 1; // For for
        s = s + A[i];
        count = count + 1; // for assignment
    }
    count = count + 1; // For last time of for
    count = count + 1; // For return;
    return s;
}
int main()
{
    srand(time(0));
    int x = rand()%20, A[x];
    for (int i = 0; i < x; i++)
    {
        A[i] = rand() % 10;
        cout << A[i] << " ";
    }
    cout << "\n";
    cout << "Sum of all number = " << Sum<int>(A, x);
    cout << "\nNumber of operation = " << count << " \n";
    return 0;
}
/*
1 8 1 9 7 4 3 3 6 3 8 4 2 2 4
Sum of all number = 65
Number of operation = 33
*/