# Counting Sort

* Set the size of the array as much as the maximum value or more
* It is used non-negative values when integer array
* It is composed of non-negative values, and registers the number of values by creating an array called counting.
* By applying presum to the counting array, knowing the start index of each value in the sorted array.
* Iterate the initially composed array by deducted the counting value by 1. 
  * continuosly update index



* Time complexity is O(N), which is register counting array and sort output array. 
* Time complexity is O(K), which is applied presum counting array.
* So, the summary Time complexity is O(N+K)
* Useful when the maximum value of the array is small

