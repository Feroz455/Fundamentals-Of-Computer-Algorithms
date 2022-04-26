/*
Page 113
Algorithm 2.13 Simple algorithm for union and find

Algorithm SimpleUnion(i, j)
{
    p[i] = j;
}
Algorithm SimpleFind(int i)
{
    while(p[i] >= 0) do
    {
        i = p[i];
    }
    return i;
}
*/
#include<iostream>
using namespace std;
int Array[100];
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
int main()
{
    int opcode, tempi, tempj, N;
    cout << "Enter Number of element\n";
    cin >> N;
    
    for(int i = 1; i <= N; i++)
    {
        cout << i << "'s parent is ";
        cin >> Array[i]; 
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
            SimpleUnion(tempi, tempj);
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