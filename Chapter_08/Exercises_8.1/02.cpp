/*
Algorithm BB_FIFO()
// T is the state space tree and n is the node in tree T

if T is answer node then
  u ← min(cost[T], upperBound(T) + E)
  print (T)
  return
end
E ← T
while (true)
  for each child x of T do
    if x is answer node then
      print “Display path from x to root”
      return
    end
    ENQUEUE(x) // Insert new node at the end of QUEUE
    x.parent ← E	// π[x] indicates parent of x
    if x is answer node AND cost(x) < upperBound then
      u ← min(cost[T], ub(T) + E)
    end
  end
  if no more live nodes then
    print “No live node exists”
    print “Minimum cost :”, ub
    return n
  end
  E ← DEQUEUE()     // Remove front node from the QUEUE
end
}
*/