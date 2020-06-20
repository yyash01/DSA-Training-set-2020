This problem task is about the breadth first search(BFS) algorithm.

We create an adjacency list to store the graph.

This task also required us to implement two functions-
getLink2newestNeighbour and
getLink2earlierNeighbour

We can implement these functions easily by just one statement.

For getLink2newestNeighbour
we return town->edges 
because the newest neighbour which has joined the adjacency list is at edges.

For getLink2earlierNeighbour
we return nextRoadOutofHere(town,ROAD)
this will return the next road after the road "ROAD" .

And the implementation of BFS can be done as-

We make a visited array so as to check whether we have 
visited that town or not.
Initially visited is initialised as zero for all the towns.
As we visit a town we mark visisted as 1 for that town.
then we mark visited=1 for the origin(source) town.

We use queue data structure for BFS implementation.
We first insert the index of origin town in queue.
And we iterate the following loop till the array becomes empty-

The loop-
	first remove element(town) from queue
	take all the links of that town and insert it in queue 
	(if that is not visited i.e. visited=0) and also 
	make visited=1 as we visit a town

As the itreration of the above loop is over we have reached at every town present.
Hence , BFS done.

Done.