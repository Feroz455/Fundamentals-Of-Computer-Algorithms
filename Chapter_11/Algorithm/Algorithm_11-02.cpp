/*
Page 517
Algorithm 11.2 Nondeterministic sorting

Algorithm NSort(A,n)
//Sort n positive intergers
{
    for i = 1 to n do
    B[i] = 0; // Initialize B[]
    for(i = 1; to n do)
    {
        j = Choice(1,n);
        if(B[j] != 0)
        Failure();
        B[j] = A[i];
    }
    for i = 1 to n - 1 do // Verify order
    if(B[i] > B[i+1])
    Failure();
    write(B[1:n]);
    Success();
}
*/