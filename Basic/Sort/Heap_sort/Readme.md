# Heap Sort

* It implements the max heap and min heap and continuously updates the maximum or minimum.
* Sorted array can be obtained by subtracting one by one from the  heap and inserting, applied by heapify, it into the index.
* Since it is inserted as a tree, the time complexity when inserting one node is O(logN). When Inserted N data, the total time complexity is O(NlogN).  
* Inserting is O(NlogN) and deleteing is O(NlogN)  -> O(NlongN) + O(NlogN) = O(NlogN)
* Inserting is down to top / deleteing is top to down
* So, When continuously updated (inserting) node, this process should be applied.



* using heapify(continuously maintain heap) instead of inserting
* start from parents of leaf node (n/2) to root node, applying build heap(heapify)
* time complexity is O(N)
  * edge counting to leaf node * counting of node
  * leaf node counting is n/2,  and edge counting to leaf node is 0
  * parents : n /4 , 1
  * parents : n/8, 2
  * parents : n/16, 3
  * ...
  * summary = 0 * (n/2) + 1 * (n/4) + 2* (n/8) + ... =  N* (1/4 + 2/8 + 3/16 + 4/32 + 5/64 ...)  ~= O(N)

* At the start point, node is setting and not updated, using upper process.

* So, heap sort is applied by heapify, time complexity is O(N) + O(NlogN) = O(NlogN)

