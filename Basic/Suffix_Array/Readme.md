# Suffix Array

* Sorts all suffies that exist in the string



* the ways implement suffix array, there's a two methods. Naive / Manber-Mayers Algorithm.
* Naive Algorithm's time complexity is O(N^2 logN), so It isn't effective to use.
* Manber-Mayers Algorithm's time complexity is O(NlogN), So when implement suffix array using Manber-Mayer Algorithm.



#### Manber-Mayers Algorithm

* When Sorting, Using Rank and apply radix sort concepts

* Ranked by continuously comparing the power of 2 values while looping
* Even if values differ only in values other than power of 2, the substr is different and thus classified by rank

---

##### Additional Implement

* using counting sort Instead of radix sort, Time complexity is O(Nlog^2(N) -> NlogN)
* There's a method implementing O(N)...