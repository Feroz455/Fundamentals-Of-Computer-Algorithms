/*
Page 217

3) We are given n task to perform in sequence. SUppose that task i needs
ti units of time. If the tasks are done in the order 1,2,...,n then
task in complete at time ci = (SUM( i,  j = 1, tj). The average compilation time
task i completes at time(ACT) is 1/nSUM(n,i=1,ci).


a) consider the case of four tasks with task times (4,2,8,1). what is the
ACT when the task order is 1, 2, 3, 4

b) What is the ACT when the task order is 2,1,4,3

c) The following method constructs a task order that tries to
minimize the ACT. Construct the order in n stage, in each stage
select from the remaining tasks one with least task time. For the
example of part (a) this strategy results in the task order 4,2,1,3;
What is the ACT for this greedy order;

d) Write an algorithm that implements the greedy strategy of (c)
The complexity if your algorithm should be O(n log n). Show
that this is so.

e) Show that the greedy strategy if (c) results in task order that have minimum ACT;
*/

#include <iostream>
#include <algorithm>
using namespace std;
struct job
{
    int id;
    int time;
};
int arr[] = {4, 2, 8, 1};
int n = sizeof(arr) / sizeof(int);
bool Compare(job a, job b)
{
    return (a.time < b.time);
}

void ATC(job task[])
{
    float average = 0.0, x[n];
    x[0] = float(task[0].time);
    for (int i = 1; i < n; i++)
    {
        x[i] = task[i].time + x[i - 1];
    }

    for (auto i : x)
    {
        average += i;
    }
    cout << "ATC -> " << average / n << "\n";
}

int main()
{
    job JOB[n];
    for (int i = 0; i < n; i++)
    {
        JOB[i].id = i;
        JOB[i].time = arr[i];
    }
    sort(JOB, JOB + n, Compare);
    ATC(JOB);
    return 0;
}
/*
a)

ATC -> 6.5

b)
ATC -> 7.5

c)
ATC -> 6.5

*/