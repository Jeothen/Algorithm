# KMP (Knuth-Morris-Prett)

* KMP algorithm is implemented using prefix and suffix.

* fail function

  * common max length of prefix and suffix

  * below table is  `ababacabababbb` 's fail function

    | index   | 0    | 1    | 2    | 3    | 4    | 5             | 6    | 7    | 8    | 9    | 10   | 11               | 12           | 13   |
    | ------- | ---- | ---- | ---- | ---- | ---- | ------------- | ---- | ---- | ---- | ---- | ---- | ---------------- | ------------ | ---- |
    | pattern | a    | b    | a    | b    | a    | c             | a    | b    | a    | b    | a    | b                | b            | b    |
    | j       | 0    | 0    | 1    | 2    | 3    | p[2]->p[0] =0 | 1    | 2    | 3    | 4    | 5    | p[4]=3(same) + 1 | p[3]->p[1]=0 | 0    |
    | p[i]    | 0    | 0    | 1    | 2    | 3    | 0             | 1    | 2    | 3    | 4    | 5    | 3->4             | 0            | 0    |

  * If pattern[index] and pattern[j] are different, move to the previous fail function value until they are the same or 0

  * If pattern[index] and pattern[j] are the same, 1 is added to j, and then 1 is also added to the p[index].



* Example

  * Find `ababa`   in `abab  ababdabababa`
  * create fail function `ababa`
    * fail function p  = [0,0,1,2,3]  in `ababa `

  

  * index 4 is mismatch ->  match up to index 3,  so. p[3] = 2

    | a    | b    | a    | b    |       | a    | b    | a    | b    | a    | b    | a    | b    | d    |
    | ---- | ---- | ---- | ---- | ----- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
    | a    | b    | a    | b    | **a** |      |      |      |      |      |      |      |      |      |

  * Apply from index 2 to the point that did not match before -> match up to 1, so p[1] = 0

    | a    | b    | a    | b    |       | a    | b    | a    | b    | a    | b    | a    | b    | d    |
    | ---- | ---- | ---- | ---- | ----- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
    |      |      |      |      | **a** | b    | a    |      |      |      |      |      |      |      |

  * Apply from index 0 to the point that did not match before ->  not match, so index++

    | a    | b    | a    | b    |       | a    | b    | a    | b    | a    | b    | a    | b    | d    |
    | ---- | ---- | ---- | ---- | ----- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
    |      |      |      |      | **a** | b    | a    | b    | a    |      |      |      |      |      |

  * exactly match /  match up to index 4, so p[4] = 3

    | a    | b    | a    | b    |      | a    | b    | a    | b    | a    | b    | a    | b    | d    |
    | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
    |      |      |      |      |      | a    | b    | a    | b    | a    |      |      |      |      |

  * checked from index 3, exactly match / match up to index 4, so p[4] = 3 

    | a    | b    | a    | b    |      | a    | b    | a    | b    | a    | b    | a    | b    | d    |
    | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
    |      |      |      |      |      |      |      |      |      |      | b    | a    |      |      |

  * match up to index 3, so p[3] = 2

    | a    | b    | a    | b    |      | a    | b    | a    | b    | a    | b    | a    | b    | d    |
    | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
    |      |      |      |      |      |      |      |      |      |      |      |      | b    | a    |

  * checked from index 2, and pattern string is over the length of text

    | a    | b    | a    | b    |      | a    | b    | a    | b    | a    | b    | a    | b    | d    |      |      |
    | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
    |      |      |      |      |      |      |      |      |      |      |      |      |      | a    | b    | a    |



* So, Time complexity is O(N+M)

