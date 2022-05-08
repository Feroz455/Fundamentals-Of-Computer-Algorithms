/*
Page 194
02. Write an algorithm that multiplies two n * n matrices using O(n^3)
operations. Determine the precise number of multiplications, additions
and array elements accesses.
*/

#include <iostream>
#include <ctime>
using namespace std;
#define R1 4 // number of rows in Matrix-1
#define C1 4 // number of columns in Matrix-1
#define R2 4 // number of rows in Matrix-2
#define C2 4 // number of columns in Matrix-2

void mulMat(int mat1[][C1], int mat2[][C2])
{
    int rslt[R1][C2];

    cout << "Multiplication of given two matrices is:\n"
         << endl;

    for (int i = 0; i < R1; i++)
    {
        for (int j = 0; j < C2; j++)
        {
            rslt[i][j] = 0;

            for (int k = 0; k < R2; k++)
            {
                rslt[i][j] += mat1[i][k] * mat2[k][j];
            }

            cout << rslt[i][j] << "\t";
        }

        cout << endl;
    }
}

int main(void)
{
    srand(time(0));
    // Square Matrices
    // R1 = 4, C1 = 4 and R2 = 4, C2 = 4 (Update these values in MACROs)
    int mat1[R1][C1] = {
        {1, 1, 1, 1},
        {2, 2, 2, 2},
        {3, 3, 3, 3},
        {4, 4, 4, 4}};

    int mat2[R2][C2] = {
        {1, 1, 1, 1},
        {2, 2, 2, 2},
        {3, 3, 3, 3},
        {4, 4, 4, 4}};

    if (C1 != R2)
    {
        cout << "The number of columns in Matrix-1  must be equal to the number of rows in "
                "Matrix-2"
             << endl;
        cout << "Please update MACROs according to your array dimension in #define section"
             << endl;

        exit(EXIT_FAILURE);
    }

    mulMat(mat1, mat2);

    return 0;
}
/*
10      10      10      10
20      20      20      20
30      30      30      30
40      40      40      40
*/