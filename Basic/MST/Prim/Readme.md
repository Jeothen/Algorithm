# Prim

* It is a representative algorithm of MST and operates based on node.
* The worst time complexity is O(n^2), which is the square of the number of nodes.  / n is nodecount
* e, edge count, is always smaller than n^2, so worst time complexity is O(elogn) when using priority queue.



* When implemented by priority queue, time complexity is O(eloge)
* kruskal applies the priority queue after saving all edges, but prim stores edges in the priority queue as nodes move.

