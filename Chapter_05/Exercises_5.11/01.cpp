/*
Page 327
01
Matrix product chains
 */
#include <iostream>
using namespace std;
int main()
{
    int n = 5;
    int p[] = {5, 4, 6, 2, 7};
    int m[5][5] = {0};
    int s[5][5] = {0};
    int j, min, q;

    for (int d = 1; d < n - 1; d++)
    {
        for (int i = 1; i < n - d; i++)
        {
            j = i + d;
            min = 32867;
            for (int k = i; k <= j - 1; k++)
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < min)
                {
                    min = q;
                    s[i][j] = k;
                }
            }
            m[i][j] = min;
        }
    }
    cout << m[1][n - 1] << "\n";

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << s[i][j] << " ";
        }
        cout << "\n";
    }
}
/*
Matrix_chain_Multiplication
142
*/
/*
158
0 0 0 0 0
0 0 120 88 158
0 0 0 48 104
0 0 0 0 84
0 0 0 0 0


0 0 0 0 0
0 0 1 1 3
0 0 0 2 3
0 0 0 0 3
0 0 0 0 0
*/