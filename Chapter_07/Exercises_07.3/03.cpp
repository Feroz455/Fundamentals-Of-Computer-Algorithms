/*
Page 379
03) Write a backtraking algorithm for the sum of subsets problem using the
state space tree corresponding to the variable tuple size formulation
*/
#include <iostream>
#include <algorithm>
#include <chrono>
#include <vector>
using namespace std;
using namespace chrono;
#define N 7
#define M 35
int x[N];
void SumOfSub(int s, int k, int r, int w[])
// Find all subsets of w[1:n] that sum to m. The values of x[j],
// a <= j < k; have already been determined . s = sumof(w[j]*x[j])
// and r = sumof(w[j]). the w[j]'s are in nondecreasing order.
// It is assumed that w[1] <= m  and sumof(w[i] > = m)
{
    // cout << "s -> " << s << " k-> " << k + 1 << " r-> " << r << "\n";

    // Generate left child. Notes s + w[k]<= m since B[k-1] is true
    x[k] = 1;
    if (s + w[k] == M)
    {
        // Subset found
        for (int i = 0; i <= k; i++)
        {
            cout << x[i] << " ";
        }
        cout << "\n";
    }
    // there is no recursive call here as w[j] > 0, 1 <= j <= n
    else if ((s + w[k] + w[k + 1]) <= M)
    {
        SumOfSub(s + w[k], k + 1, r - w[k], w);
    }
    // Generate right child and evaluate Bk;
    if ((s + r - w[k] >= M) && s + w[k + 1] <= M)
    {
        x[k] = 0;
        SumOfSub(s, k + 1, r - w[k], w);
    }
}
int Sum(int w[])
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += w[i];
    }
    return sum;
}
void calculate_Time(int w[])
{
    vector<int> values(10000);
    // Get starting timepoint
    auto start = high_resolution_clock::now();

    // Call the function, here sort()
    int s = 0, k = 0, r;
    for (int i = 0; i < N; i++)
    {
        x[i] = 0;
    }
    r = Sum(w);
    SumOfSub(s, k, r, w);

    // Get ending timepoint
    auto stop = high_resolution_clock::now();

    // Get duration. Substart timepoints to
    // get duration. To cast it to proper unit
    // use duration cast method
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
}
int main()
{
    int w1[N] = {5, 7, 10, 12, 15, 18, 20};
    int w2[N] = {20, 18, 15, 12, 10, 7, 5};
    int w3[N] = {15, 7, 20, 5, 18, 10, 12};
    cout << "\n#1\n";
    calculate_Time(w1);
    cout << "\n#2\n";
    calculate_Time(w2);
    cout << "\n#3\n";
    calculate_Time(w3);
}
/*
#1
1 0 1 0 0 0 1
1 0 0 1 0 1
0 1 1 0 0 1
0 0 0 0 1 0 1
Time taken by function: 5996 microseconds

#2
0 1 0 0 1 1
Time taken by function: 998 microseconds

#3
1 0 1
0 1 0 0 1 1
0 0 0 1 1 0 1
Time taken by function: 3995 microseconds
*/