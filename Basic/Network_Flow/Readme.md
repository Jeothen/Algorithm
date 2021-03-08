# Network Flow

* There's a cost on the edge. not only the weights
* The Flow of each edges must not exceed the capacity of each edges
* Excepts source and target node, Every node has the same input and output flow
* If cost is negative value, It flows in the reverse way



## Maximum Flow Algorithm

* there's a many maximum flow algorithm



#### Ford-Fulkerson Algorithm

* If the flow is already flowing, reverse way flow is possible.

  * It doesn't actually applied, but it decreased by the reverse direction from the already flow

  

* Finding the augmenting path

* The path found must be a shortest path that has available capacity

  * Found by DFS (Ford-Fulkerson), time complexity is always O(V+E)
    * there's a two ways bottle-neck, Time complexity increases geometrically 

  * Found by BFS (**Edmonds-Kark Algorithm**)
    * Maximum Time complexity is O(V*E^2)

* Flow the smallest weight to all the edges that can go in the path.

  

