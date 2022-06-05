/*
Page 372
Algorithm 7.3 Estimating the efficiency of backtraking 

Algorithm Estimate()
//This algorithm follows a random path 
/in a state space tree and produces an 
//estimate of the number of nodes in the tree
{
    k = 1; m = 1; r = 1;
    do 
    {
        T[k] = {x|K| :|x[k] belong T(x[1],x[2],....x[k-1] and B[k](x[1],......x[k])}
        if(Size(T[k]) == 0) then retur n m;
        r = r * Size(T[k]);
        m = m + r;
        x[k] = Choose(Tk); 
        k = k + 1;
    }while(true)
}
*/