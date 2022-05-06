/*
Page 177
Algorithm 3.17  A randomized algorithm for sorting

//Sort the elements a[1:n]
Algorithm RSort(a,n)
{
    //Randomly sample s elements from a[1:n];
    Sort this sample;
    Partition the input using sorted samples as partition keys
    Sort each part separately
}
*/