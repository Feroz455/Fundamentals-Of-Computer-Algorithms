/*
Algorithm TowerOfHonoi(n, x, y, z);
//Move the top n disk from tower x to tower y
{
    if(n > 1) then
    {
        TowerOfhonai(n-1), x, z, y);
        write("Move top disk from tower ", x , "to top of tower", y);
        TowerOfHonai(n-1, z, y, x);
    }
}
*/
#include<iostream>
using namespace std;
void Tower_Of_Honai(int n, char x, char y, char z)
{
    if(n > 0)
    {
        Tower_Of_Honai(n-1, x, z, y);
        cout << "Move top disk from tower " << x << " to top of tower " << y << "\n";
        Tower_Of_Honai(n-1, z, y, x);
    }
}
int main()
{
    int n = 5;
    char x, y, z;
    x = 'A';
    y = 'B';
    z = 'C';
    Tower_Of_Honai(n, x, y, z);
    return 0;
}
/*
Move top disk from tower A to top of tower B
Move top disk from tower A to top of tower C
Move top disk from tower B to top of tower C
Move top disk from tower A to top of tower B
Move top disk from tower C to top of tower A
Move top disk from tower C to top of tower B
Move top disk from tower A to top of tower B
Move top disk from tower A to top of tower C
Move top disk from tower B to top of tower C
Move top disk from tower B to top of tower A
Move top disk from tower C to top of tower A
Move top disk from tower B to top of tower C
Move top disk from tower A to top of tower B
Move top disk from tower A to top of tower C
Move top disk from tower B to top of tower C
Move top disk from tower A to top of tower B
Move top disk from tower C to top of tower A
Move top disk from tower C to top of tower B
Move top disk from tower A to top of tower B
Move top disk from tower C to top of tower A
Move top disk from tower B to top of tower C
Move top disk from tower B to top of tower A
Move top disk from tower C to top of tower A
Move top disk from tower C to top of tower B
Move top disk from tower A to top of tower B
Move top disk from tower A to top of tower C
Move top disk from tower B to top of tower C
Move top disk from tower A to top of tower B
Move top disk from tower C to top of tower A
Move top disk from tower C to top of tower B
Move top disk from tower A to top of tower B
*/