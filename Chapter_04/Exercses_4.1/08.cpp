/*
page 214
8) Consider the machine-scheduling problem of Example 4.2. Asume
that only one matchine is availabe and that we are to slelect the
largest number of tasks that can be schedule one this machin. For
the example, the largest task selection is(a, b, e). A greedy algorithm for
this task-selection problem would select the tasks in stage. In each stage
one task is selected using the following criterion: From the remaining
task select the one that has the least finish time and does not overlap
with any of the already selected tasks.


a) Show that this greedy algorithm obtains optimal selection
b) Develop an O(n log n) implementioon of this algorithm(hint: use a min heap of finish times)
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
        int x = a.start, y = a.end, m = b.start, n = b.end;
        return (y - x) > (n - m);
    }
};
int Machine_Schedule(priority_queue<TASK, vector<TASK>, compare> task, int size, int max)
{
    TASK jobs;
    string array[max];

    for (int j = 0; j < max; j++)
    {
        array[j] = ".";
    }
    while (!task.empty())
    {
        jobs = task.top();
        int start = jobs.start;
        int end = jobs.end;
        // cout << start << " " << end << " \n";
        if ((array[start] == ".") && (array[end] == "."))
        {
            for (int k = start; k <= end; k++)
            {
                array[k] = jobs.ID;
            }
        }

        task.pop();
    }
    cout << "Macchine-Scheduling -> \n";
    for (int jj = 0; jj < max; jj++)
    {
        cout << setw(6) << array[jj];
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

        job.ID = char(65 + i);

        cin >> job.start >> job.end;
        task.push(job);
        if (max < job.end)
            max = job.end;
    }
    cout << "\n";
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

Macchine-Scheduling ->
     A     A     A     .     .     .     E     E     E     G     G     G
*/