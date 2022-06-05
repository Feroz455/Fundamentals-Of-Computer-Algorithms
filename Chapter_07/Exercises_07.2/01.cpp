/*
Page 373
01_Change the two backtraking control abstractions. Algorithm 7.1
and 7.2 so that they find only a single solution rather than all solution.
*/
/*

Algorithm BackTrack(k)
//This schema describes the backtracking process using
//recursion. On entering, the first k-1 values
//x[1], x[2],....x[k-1] of the solution vector
//x[1:n] have been assigned. x[] and n are global
{
    for(each x[k] belong T(x[1],...,x[k-1]))
    {
        if(Bk(x[1],x[2],....,x[k]) != 0)
        {
            if(x[1],x[2],....x[k] is a path to an answer node)
            {
                write (x[1:k]);
                return;
            }
            if(k < n)
            Backtrack(k+1);
        }
    }

}



Algorithm IBracktrack(n)
//This schema describes the backtracking Process
//All solution are generated in x[1:n] and printed
//as soon as they are determined
{
    k = 1;
    while(k != 0)
    {
        if(there remains an untried x[k] (- T(x[1], x[2],....., x[k-1]) and Bk(x[1],....,x[k] is true) then))
        {
            if (x[1],.....x[k] is a path to an answer node)
            {
                write(x[1:k]);
                return;
            }
            k = k + 1; // consider the next set
        }

    }
    else k = k - 1; // Bracktrack to the previous set;

}
*/