/*
page 75
6. Compute the run time of the Las Vegas algorithm given in algorithm 1.30
 and express it using th e `O() notation


Algorithm LasVegas(
    {
        while(true)
        {
            i := Random()%2;
            if(i >= 1) then
            retrun;
        }

    }
)
*/
#include <iostream>
#include <ctime>
using namespace std;
int LasVegas()
{
    srand(time(0));
    int i, check = 0;
    while (true)
    {
        check++;
        i = rand() % 2;
        if (i >= 1)
            return check;
    }
}
int main()
{
    cout << LasVegas();
    return 0;
}
