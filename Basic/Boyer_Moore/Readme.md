# Boyer Moore



* In the Boyer Moore, there's two approach

  * ##### Bad Character Heuristic

    * In many case, mismatch occurs at the end of the string, so it moves from right to left
    * Skip points that cannot be compared and move to the next index to be compared

  * ##### Good Suffix Heuristic

    * Implement suffix array, and apply this to the index shift

* When using Boyer Moore Algorithm, Consider both methods and apply effective way



#### Preprocess

* Bad Character preprocessing time complexity is O(M)
* Suffix Array of Good Suffix time complexity is O(MlogM)

#### Boyer Moore

* best case, time complexity is O(N/M), random average time complexity is O(N), but worst case, time complexity is O(NM).





# Boyer Moore Hospool

* It shows the same performance as the Boyer Moore Algorithm, but its implementation is very simple.



* ##### Create Bad Match Table (bad character)

  * First, fill all the values in the bad match table with the length of pattern.

  * After that, While looping, Change the value to `pattern_length-index-1`

  * The previous value is replaced with the next smaller value and changed to the minimum value.

  * The last character is omitted in the loop process (because 0 is displayed)

    * So, If last character occured previous, table value is that.
    * However, If it does not appear, the value is assigned as the length of pattern

  * Time complexity of preprocess is O(M), length of pattern

    

* ##### Hospool Algorithm

  * Iterator from index 0 to the same as `length of text - length of pattern`
  * Specify the index of pattern and text to the right of the string
  * Moves from the right to next, compares one by one, and moves the pattern index by the value of `Bad Match Table` of the text at the wrong point



* best case, time complexity is O(N/M), random average time complexity is O(N), but worst case, time complexity is O(NM).