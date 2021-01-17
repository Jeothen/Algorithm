# Eulerian Path

* in the direct/ non-direct graph,  visit all edges exactly one time is eulerian path.
* if start-node and end-node is same, it's a eulerian circuit



* non-diredct graph
  * Eulerian path :  have 2 odd degree nodes
  * Eulerian circuit : Not have odd degree nodes 
* Direct graph 
  * Eulerian path : there's 2 node that one with 1 small indegree(start), and one with 1 small outdegree(end)
  * Eulerian circuit : all node's indegree and outdegree are same 



* If there is another edge while going through all nodes, the node is replaced with the set of connected nodes found by (dfs) recursively.
* write nodes that can no longer be visited through recursion, euler path can be created.

