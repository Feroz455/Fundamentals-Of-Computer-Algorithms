/*
Page 214
a) Show that the greedy algorithm of Example 4.2 always finds an
optiaml task algorithm

b) Program your algorithm so that its complexity is O(n log n); n is the number of task;
*/

#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;
struct Task
{
    string ID;
    int start;
    int end;
};

bool cmp(Task a, Task b)
{
    return (a.start < b.start);
}
void Print(Task job[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << job[i].ID << "\t" << job[i].start << "\t" << job[i].end << "\n";
    }
    cout << "\n";
}
int Machine_Schedule(Task jobs[], int size)
{
    int max = 12;
    int array[size][max], check = 1;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < max; j++)
        {
            array[i][j] = 0;
        }
    }
    for (int i = 1; i <= size; i++)
    {
        int start = jobs[i - 1].start;
        int end = jobs[i - 1].end;
        for (int j = 0; j < size; j++)
        {
            if ((array[j][start] == 0) && (array[j][end + 1] == 0))
            {
                for (int k = start; k <= end; k++)
                {
                    array[j][k] = i;
                }
                break;
            }
        }
    }
    for (int ii = 0; ii < size; ii++)
    {
        for (int jj = 0; jj < max; jj++)
        {
            cout << array[ii][jj] << "  ";
        }
        cout << "\n";
    }
    return 0;
}
int main()
{
    string str;
    stringstream ss;
    int numberOfTask;
    cout << "Enter number of task\n";
    cin >> numberOfTask;
    Task tasks[numberOfTask];
    cout << "Enter task details\n";
    for (int i = 0; i < numberOfTask; i++)
    {
        string str;
        stringstream ss;
        ss << (i + 1);
        ss >> str;
        tasks[i].ID = "JOB" + str;
        cin >> tasks[i].start >> tasks[i].end;
    }
    Print(tasks, numberOfTask);
    sort(tasks, tasks + numberOfTask, cmp);
    Print(tasks, numberOfTask);
    Machine_Schedule(tasks, numberOfTask);
}
/*
Enter number of task
7
Enter task details  
0       2
    3       7
    4       7
    9       11
    7       10
    1       5 
    6       8 
JOB1    0       2 
JOB2    3       7 
JOB3    4       7 
JOB5    7       10
JOB6    1       5
JOB7    6       8

JOB1    0       2
JOB6    1       5
JOB2    3       7
JOB3    4       7
JOB7    6       8
JOB5    7       10
JOB4    9       11

1  1  1  3  3  3  3  3  0  7  7  7
0  2  2  2  2  2  5  5  5  0  0  0
0  0  0  0  4  4  4  4  0  0  0  0
0  0  0  0  0  0  0  6  6  6  6  0
0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0
*/