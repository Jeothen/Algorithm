# Bellman Ford



* It is one of the algorithms to find the single source shortest distance.
* It takes longer than Dijkstra in terms of time complexity, but it can also be calculated with negative weights.



* In the process of finding a path, dist can be updated at max n-1 times (the number of nodes).
  * Since the order of update is changed according to the order of node visits, the update can be completed by going through the n-1 loop except for the first node.
* However, if an update occurs on the n times as well, there is a negative cycle.



* So, Time complexity is O(VE)    V : nodecount / E : edgecount





* Below example is 3 nodecount and need 2 loop (maximum loop : nodecount-1)

![bellman_ford](./bellman_ford.JPG)