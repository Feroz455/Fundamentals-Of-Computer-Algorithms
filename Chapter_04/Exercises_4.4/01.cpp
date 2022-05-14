/*
page 226

Algorithm 4.4 The tree vertex splitting algorithm


//Determine and output the nodes to be split
//W() is the weighting function for the edges
Algorithm TVS(T, del)
{
    if(T != 0)
    {
        d[T] = 0;
        for each child v to T do
        {
            TVS(v,del);
            d[T] = max{d[T], d[v] + w(T,v)};
        }
        if((T is not the root) and (d[T] + w(perent(T), T) > del))
        {
            write (T);
            d[T] = 0;
        }

    }

}
01. For the tree of figure 4.3 solve the TVSP when (a) del == 4 and b) del = 5
*/
