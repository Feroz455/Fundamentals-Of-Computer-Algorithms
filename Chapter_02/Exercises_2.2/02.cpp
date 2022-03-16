/*
page 91
What is the maximum number of nodes in a binary tree that has m leaves?
*/
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    srand(time(0));
    int temp, height;
    for (int i = 0; i < rand() % 20; i++)
    {
        temp = rand() % 20;
        cout << "Number of leaves -> " << setw(5) << temp << " ";
        height = ceil(log2(temp + 1));
        cout << " Roral number of node in binary tree -> " << setw(5) << pow(2, height) << "\n";
    }

    return 0;
}
/*
Number of leaves ->    18  Roral number of node in binary tree ->    32
Number of leaves ->    16  Roral number of node in binary tree ->    32
Number of leaves ->    14  Roral number of node in binary tree ->    16
Number of leaves ->     6  Roral number of node in binary tree ->     8
Number of leaves ->    17  Roral number of node in binary tree ->    32
Number of leaves ->     6  Roral number of node in binary tree ->     8
*/