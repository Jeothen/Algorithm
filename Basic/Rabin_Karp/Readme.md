

# Rabin Karp

* Rabin Karp is an algorithm that finds 1:1 matching based on hashing
* So, there are a lot of collision.  To reduce collision, Usually the MOD is set to very large prime number.
* There may still be collisions, so the existance of the string is checked through simple comparision only when hash value is same.



* Rabin Karp algorithm usually using `Rabin fingerprint algorithm`
  $$
  H[i] = t[i]*m^{n-1} + t[i+1]*m^{n-2} + ... + t[i+n-2]*m^{1}  + t[i+n-1]*m^0
  $$
  

* So, `Rabin fingerprint algorithm` transfered like belows



$H[i+1] = t[i+1]*m^{n-1} + t[i+2]*m^{n-2} + ... + t[i+n-1]*m^{1}  + t[i+n]*m^0 \\
        = (t[i]*m^n + t[i+1]*m^{n-1} + t[i+2]*m^{n-2} + ... + t[i+n-1]*m^{1} - t[i]*m^n) + t[i+n]*m^0 \\ = (t[i]*m^{n-1}+ t[i+1]*m^{n-2} +... + t[i+n-1]*m^{0} - t[i]*m^{n-1})*m + t[i+n]*m^{0} \\ = m*(H[i] - t[i]*m^{n-1}) + t[i+n]*m^{0}$



* So, best case, time complexity is O(N+M).
* But worst case such as "AAAAAAAA", "AAA" : time complexity is O(NM)