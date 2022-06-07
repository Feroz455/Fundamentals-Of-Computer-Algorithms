/*
Page 378



Algorithm SumOfSub(s,k,r)
//Find all subsets of w[1:n] that sum to m. The values of x[j],
//a <= j < k; have already been determined . s = sumof(w[j]*x[j])
//and r = sumof(w[j]). the w[j]'s are in nondecreasing order.
//It is assumed that w[1] <= m  and sumof(w[i] > = m)
{
    //Generate left child. Notes s + w[k]<= m since B[k-1] is true
    x[k] = 1;
    if(s+w[k] == m)
    {
        write ("x[i:k]"); // Subset found
    }
    //there is no recursive call here as w[j] > 0, 1 <= j <= n
    else if(s + w[k] + w[k+1] <= m)
    {
        SumOfSub(s+w[k], k+1, r - w[k]);
    }
    //Generate right child and evaluate Bk;
    if((s+r - w[k] >= m) && (s+w[k+1] <= m)
    {
        X[K] = 0;
        sumOfSub(s,k+1, r-w[k]);
    }
}
*/
#include <iostream>
using namespace std;
#define N 6
#define M 30
int x[N];
int w[N] = {5, 10, 12, 13, 15, 18};
void SumOfSub(int s, int k, int r)
// Find all subsets of w[1:n] that sum to m. The values of x[j],
// a <= j < k; have already been determined . s = sumof(w[j]*x[j])
// and r = sumof(w[j]). the w[j]'s are in nondecreasing order.
// It is assumed that w[1] <= m  and sumof(w[i] > = m)
{

    // Generate left child. Notes s + w[k]<= m since B[k-1] is true
    x[k] = 1;
    if (s + w[k] == M)
    {
        // Subset found
        for (int i = 0; i < k; i++)
        {
            cout << x[i] << " ";
        }
        cout << "\n";
    }
    // there is no recursive call here as w[j] > 0, 1 <= j <= n
    else if ((s + w[k] + w[k + 1]) <= M)
    {
        SumOfSub(s + w[k], k + 1, r - w[k]);
    }
    // Generate right child and evaluate Bk;
    if ((s + r - w[k] >= M) && s + w[k + 1] <= M)
    {
        x[k] = 0;
        SumOfSub(s, k + 1, r - w[k]);
    }
}
int main()
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += w[i];
    }
    int s = 0, k = 0, r = sum;
    SumOfSub(s, k, r);
}
/*
1 1 0 0 1 0
1 0 1 1 1 0
0 0 1 0 0 1
*/
