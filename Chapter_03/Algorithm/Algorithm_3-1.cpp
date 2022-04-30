/*
Page 138

Algorithm 3.1  control abstruction for devide and conquer 

Algorithm DAndC(P)
{
    if Small(P) then return S(P)
    else 
    {
        divide P into smaller instances P1, P2, ..... Pk, k > 1 
        Apply DAndC to each of these subproblems;
        return Combine(DAndC(P1), DAndC(P2) ,.....DAndC(Pk));
    }
}
*/