/*
Page 368
Algorithm 7.1 Recursive backtracking algorithm


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
            }
            if(k < n)
            Backtrack(k+1);
        }
    }

}
*/