/*
Page 145
Exercises
03. Write a complete program for the defective-chessboard problem. Include modules to welcome the
user to the problem; input the chessboard size and location of the defect; and output the tited hessboard.
The output is to be provided on a color monitor using colored tiled. No two tiles that share a common
boundary should be colored the same.Science the chessboard is a plannar figure, it is possible to color
the tiles in this way using at most four colors. however, for this esercises it is sufficient to devise a greedy
coloring heuristic that attemps to use as few color as possible

*/
#include <bits/stdc++.h>
using namespace std;

int size_of_grid, b, a, cnt = 0;
int arr[128][128];

// Placing tile at the given coordinates
// 4, 3, 4, 4, 3, 4
void place(int x1, int y1, int x2, int y2, int x3, int y3)
{
    //   cout << " x1 = " << x1 << " y1 = " << y1 << " x2 = " << x2 << " x3 = " << x3 << " y3 = " << y3 << "\n";
    cnt++;
    arr[x1][y1] = cnt;
    //  cout << "arr[" << x1 << "][" << y1 << "] = " << arr[x1][y1] << "\n";
    arr[x2][y2] = cnt;
    // cout << "arr[" << x2 << "][" << y2 << "] = " << arr[x2][y2] << "\n";
    arr[x3][y3] = cnt;
    //  cout << "arr[" << x3 << "][" << y3 << "] = " << arr[x3][y3] << "\n";
    return;
}
// Quadrant names
// 1   2
// 3   4

// Function based on divide and conquer
int tile(int n, int x, int y)
{
    //  cout << " n = " << n << "  x = " << x << " y = " << y << " \n";

    int r, c;
    if (n == 2)
    {
        cnt++;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[x + i][y + j] == 0)
                {
                    arr[x + i][y + j] = cnt;
                    //   cout <<  "arr[" << x + i << "][" << y + j << "] = " <<  arr[x + i][y + j] << "\n";
                }
            }
        }
        return 0;
    }
    //  finding hole location
    for (int i = x; i < x + n; i++)
    {

        for (int j = y; j < y + n; j++)
        {
            if (arr[i][j] != 0)
            {
                r = i, c = j;
                //  cout << " r = " << r << " c = " << c << "\n";
            }
        }
    }

    // If missing tile is 1st quadrant

    if (r < x + n / 2 && c < y + n / 2)
    {
        // cout << " If missing tile is 1st quadrant\n";
        place(x + n / 2, y + (n / 2) - 1, x + n / 2, y + n / 2, x + n / 2 - 1, y + n / 2);
    }

    // If missing Tile is in 3rd quadrant
    else if (r >= x + n / 2 && c < y + n / 2)
    {
        //  cout << "If missing Tile is in 3rd quadrant \n";
        place(x + (n / 2) - 1, y + (n / 2), x + (n / 2), y + n / 2, x + (n / 2) - 1, y + (n / 2) - 1);
    }

    // If missing Tile is in 2nd quadrant
    else if (r < x + n / 2 && c >= y + n / 2)
    {
        //   cout << " If missing Tile is in 2nd quadrant \n";
        place(x + n / 2, y + (n / 2) - 1, x + n / 2, y + n / 2, x + n / 2 - 1, y + n / 2 - 1);
    }

    // If missing Tile is in 4th quadrant
    else if (r >= x + n / 2 && c >= y + n / 2)
    {
        //  cout << "If missing Tile is in 4th quadrant\n";
        place(x + (n / 2) - 1, y + (n / 2), x + (n / 2), y + (n / 2) - 1, x + (n / 2) - 1, y + (n / 2) - 1);
    }

    // dividing it again in 4 quadrants
    // cout << "   dividing it again in 4 quadrants  " << "1\n";
    tile(n / 2, x, y + n / 2);
    // cout << "   dividing it again in 4 quadrants  " << "2\n";
    tile(n / 2, x, y);
    // cout << "   dividing it again in 4 quadrants  " << "3\n";
    tile(n / 2, x + n / 2, y);
    //  cout << "   dividing it again in 4 quadrants  " << "4\n";
    tile(n / 2, x + n / 2, y + n / 2);

    return 0;
}
// Driver program to test above function
int main()
{
    // size of box
    cout << "Enter Chess board size->\t";
    cin >> size_of_grid;
    memset(arr, 0, sizeof(arr));
    // Coordinates which will be marked
    cout << "Enter defect position->\t";
    cin >> a >> b;
    // Here tile can not be placed
    arr[a][b] = -111;
    /*
    GO 1

    */
    tile(size_of_grid, 0, 0);
    // The grid is
    for (int i = 0; i < size_of_grid; i++)
    {
        for (int j = 0; j < size_of_grid; j++)
            cout << arr[i][j] << " \t";
        cout << "\n";
    }
}
/*
Enter Chess board size->        8
Enter defect position-> 2 2
9       9       8       8       4       4       3       3 
9       7       7       8       4       2       2       3 
10      7       -111    11      5       5       2       6  
10      10      11      11      1       5       6       6  
14      14      13      1       1       19      18      18 
14      12      13      13      19      19      17      18 
15      12      12      16      20      17      17      21 
15      15      16      16      20      20      21      21
*/