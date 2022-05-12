/*
Page 214
a) Show that the greedy algorithm of Example 4.2 always finds an
optiaml task algorithm

b) Program your algorithm so that its complexity is O(n log n); n is the number of task;
*/
#include <iostream>
#include <sstream>
#include <set>
#include <ctime>
#include <queue>
#include <iomanip>
using namespace std;
struct TASK
{
    string ID;
    int start;
    int end;
};
struct compare
{
    bool operator()(TASK const &a, TASK const &b) const
    {
        return a.start > b.start;
    }
};
int Machine_Schedule(priority_queue<TASK, vector<TASK>, compare> task, int size, int max)
{
    TASK jobs;
    string array[size][max];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < max; j++)
        {
            array[i][j] = "....";
        }
    }
    while (!task.empty())
    {
        jobs = task.top();
        int start = jobs.start;
        int end = jobs.end;
        for (int j = 0; j < size; j++)
        {
            if ((array[j][start] == "....") && (array[j][end + 1] == "...."))
            {
                for (int k = start; k <= end; k++)
                {
                    array[j][k] = jobs.ID;
                }
                break;
            }
        }
        task.pop();
    }
    for (int ii = 0; ii < size; ii++)
    {
        for (int jj = 0; jj < max; jj++)
        {
            cout << setw(6) << array[ii][jj] << "  ";
        }
        cout << "\n";
    }
    return 0;
}
int main()

{
    srand(time(0));
    TASK job;
    priority_queue<TASK, vector<TASK>, compare> task;
    int numberOfTask, max = 0;

    cout << "Enter number of task\n";
    cin >> numberOfTask;
    cout << "Enter task details\n";
    for (int i = 0; i < numberOfTask; i++)
    {
        string str;
        stringstream ss;
        ss << (i + 1);
        ss >> str;
        job.ID = "JOB" + str;

        cin >> job.start >> job.end;
        task.push(job);
        if (max < job.end)
            max = job.end;
    }
    Machine_Schedule(task, numberOfTask, max + 1);
    return 0;
}
/*
Enter number of task
7
Enter task details
0 2
1 5
3 7
4 7
6 8
7 10
9 11
  JOB1    JOB1    JOB1    JOB3    JOB3    JOB3    JOB3    JOB3    ....    JOB7    JOB7    JOB7  
  ....    JOB2    JOB2    JOB2    JOB2    JOB2    JOB5    JOB5    JOB5    ....    ....    ....  
  ....    ....    ....    ....    JOB4    JOB4    JOB4    JOB4    ....    ....    ....    ....  
  ....    ....    ....    ....    ....    ....    ....    JOB6    JOB6    JOB6    JOB6    ....
  ....    ....    ....    ....    ....    ....    ....    ....    ....    ....    ....    ....  
  ....    ....    ....    ....    ....    ....    ....    ....    ....    ....    ....    ....  
  ....    ....    ....    ....    ....    ....    ....    ....    ....    ....    ....    .... 
*/