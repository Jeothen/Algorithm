# Quick Sort

* sort of divide and conquer algorithm.
* After setting the value of the middle position to pivot, index moves from left to greater than pivot. 
* After that, index moves from right to less than pivot.
* Then  `array[right] < pivot < arr[left]` is established, so change the positions of left and right.

* If the moving right is greater than the initial start point, qsort cannot be applied to the values in between, so recursion is performed again.

* Like that, If the moving left is smaller than the initil end point, qsort can not be applied to the values in between, so recursin is performed again.