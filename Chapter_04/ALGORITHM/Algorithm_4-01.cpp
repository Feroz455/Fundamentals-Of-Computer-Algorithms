/*
Page 211
Algorithm 4.1 Greedy method control abstruction for the subset paradigm
*/
/*
//a[1:n] contains the n inputs.
Algorithm Greedy(a,n)
{
    solution = 0; // Initialize the solution.

    for(int i = 1; i< n; i++)
    {
        x =  Select(a);
        if(Feasible(solution, x))
        {
            solution = union(solution, x);
        }
    }
}
*/