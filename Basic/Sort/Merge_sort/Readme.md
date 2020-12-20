# Merge Sort

* It is sort of divided and conquer algorithm.
* Divide continues until the size of the array is 1 through recursion.
* The size of the array starts from 1, and a new array is formed in two directions based on mid.
  * It is composed of two pieces, and each piece is sorted, so left and right ++ form a new sort piece.

* DIvide time complexity is O(logN), Conquer time complexity is O(logN), and rearrange time complexity is O(N)
* So, Summary Time complexity is O(NlogN).
  * Best case, Worst case is same as O(NlogN)