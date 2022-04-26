/*
page 115
Algorithm 2.14 Union algorithm with weighting rule

Algorithm WeightedUnion(int i, int j)
//Union sets with roots i and j, where i != j using the 
//Weighting rule Array[i] = -cunt[i] and Array[j] = - count[j];
{
    temp := Array[i] + Array[j];
    if(Array[i] > Array[j]) 
    then
    {
        //I has fewer nodes
        Array[i] := j;
        Array[j] = temp;
    }
    else
    {
        //j has fewer or equal nodes
        Array[j] := i;
        Array[i] := temp;
    }
}
*/
#include<iostream>
using namespace std;
int Array[100], count[100];
void option()
{
    int i = 1;
    cout << "\n************************************\n";
    //cout << i++ << "Enter sets value\n";
    cout << i++ << "\tUnion set\n";
    cout << i++ << "\tFind Parent\n";
    cout << i++ << "\tShow result\n";
    cout << i++ << "\tExit\n";
    cout << "\n************************************\n";
}
void SimpleUnion(int i,int j)
{
    Array[i] = j;
}
int SimpleFind(int i)
{
    while(Array[i] >= 0)
    {
        i = Array[i];
    }
    return i;
}
void WeightedUnion(int i, int j)
//Union sets with roots i and j, where i != j using the 
//Weighting rule Array[i] = -cunt[i] and Array[j] = - count[j];
{
    Array[i] = -count[i], Array[j] = -count[j]; 
    int temp = Array[i] + Array[j];
    if(Array[i] > Array[j]) 
    {
        //I has fewer nodes
        Array[i] = j;
        Array[j] = temp;
    }
    else
    {
        //j has fewer or equal nodes
        Array[j] = i;
        Array[i] = temp;
    }
}


int main()
{
    int opcode, tempi, tempj, N;
    cout << "Enter Number of element\n";
    cin >> N;
    
    for(int i = 1; i <= N; i++)
    {
        cout << i << "'s parent is ";
        cin >> Array[i];
        if(Array[i] > 0)
        count[Array[i]]++;
    }
    while(1)
    {
        option();
        cin >> opcode;
        switch (opcode)
        {
        case 1:
            cout << "Enter 2 sets number\n";
            cin >> tempi >> tempj;
            if(tempi > N || tempj > N)
            break;
            else
            WeightedUnion(tempi, tempj);
            break;
        case 2:
            cout << "Enter set value\n";
            cin >> tempi;
            if(tempi >= N)
            break;
            else
            cout << SimpleFind(tempi) << "\n";
            break;
        case 3:
            for(int i = 1; i <= N; i++)
            {
                cout << i << " -> "  << Array[i] << "\n";
            }
            break;
        case 4:
            exit(1);
        default:
            break;
        }

    };
    return 0;
}


/*
Enter Number of element
9
1's parent is -1
2's parent is 5
3's parent is -1
4's parent is 3
5's parent is -1
6's parent is 3
7's parent is 1
8's parent is 1
9's parent is 1

************************************
1       Union set
2       Find Parent
3       Show result
4       Exit

************************************
3
1 -> -1
2 -> 5
3 -> -1
4 -> 3
5 -> -1
6 -> 3
7 -> 1
8 -> 1
9 -> 1

************************************
1       Union set
2       Find Parent
3       Show result
4       Exit

************************************
1
Enter 2 sets number
5 1

************************************
1       Union set
2       Find Parent
3       Show result
4       Exit

************************************
3
1 -> -4
2 -> 5
3 -> -1
4 -> 3
5 -> 1
6 -> 3
7 -> 1
8 -> 1
9 -> 1

************************************
1       Union set
2       Find Parent
3       Show result
4       Exit

************************************
4