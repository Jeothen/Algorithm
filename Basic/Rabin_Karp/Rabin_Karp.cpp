#include <cstdio>
#include <vector>
#define MOD 1000000009


std::vector<int> rabin_karp(char* text, char* pattern){
    int res = 0;
    int lent, lenp;
    long long texthash = 0, patternhash = 0, power = 1;
    for (lent = 0; text[lent] != '\0'; lent++);
    for (lenp = 0; pattern[lenp] != '\0'; lenp++);
    
    // rabin - karp algorithm
    std::vector<int>vc;
    
    // calculate hash value
    for (int i = 0; i < lenp; i++)  
    {
        texthash = (texthash * 257 + text[i]) % MOD; //  up to pattern length, first text hash value
        patternhash = (patternhash * 257 + pattern[i]) % MOD;
        if (i != 0) power = (power * 257) % MOD; // power is length of pattern's Degree, m^(lenp-1)
    }

    for (int i = 0; i <= lent - lenp; i++) // already calculate first text hash
    {
        if (texthash == patternhash) {
            // text compare
            bool isdiff = false;
            for (int j=0; j<lenp;j++){
                if (pattern[j] != text[i+j]) {
                    isdiff = true; break;
                }
            }
            if (!isdiff) vc.push_back(i); // start index
        }
        // H[i+1] = m * (H[i] - t[i] * m^(n-1)) + t[i+lenp]
        texthash = (257 * (texthash - text[i] * power) + text[i + lenp]) % MOD;  
        if (texthash < 0) texthash += MOD;
    }
    return vc;
}
