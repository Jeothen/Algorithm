# Dijkstra

* Algorithm that can calculate the shortest distance from source node to target node
* The time complexity is O((V+E)logV).  -  priority queue performed with pibonachi heap.
  * For each node, O(VlogV) is needed to find the node with the shortest distance calculated from the stating point among unvisited nodes
  * For each node, O(ElogV) is needed when updating the shortest distance of neighboring nodes.



* It cannot be used if there is a negative value.

