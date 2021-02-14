#include <stdio.h>
#include <string.h>

int *createGS(char *pattern, int M)
{
    int *gs = new int[M];
    int i;     // pattern index
    int j = 0; // partial pattern index

    // initialize gs array
    for (i = 0; i < M; ++i) gs[i] = M;  // length of pattern

    i = M - 1; // compare from last index
    while (i > 0)
    {
        if (j >= 0 && pattern[i + j] == pattern[j])
        {
            j--;
        }
        else
        {
            if (j < 0)
            {
                // case 1. partial good suffix matches prefix of pattern
                for (; i + j >= 0; --j)
                    gs[i + j] = i;
            }
            else
            {
                // case 2. good suffix matches somewhere in the pattern
                // set i to the shift length in gs[] element
                // whose index is the unmatched position
                gs[i + j] = i;
            }
            j = M - i;
            i--;
        }
    }

    return gs;
}

void searchBM(char *pattern, char *text)
{
    int N = strlen(text);
    int M = strlen(pattern);

    int *gs = createGS(pattern, M);

    int s = 0; // Shift of the pattern with respect to text
    int j = 0; // Index for pat[]

    while (s <= (N - M))
    {
        j = M - 1;

        while (j >= 0 && pattern[j] == text[s + j]) j--;
        
        if (j < 0)
        {
            printf("Pattern found at index %d \n", s);
            // Shift the pattern as the length of the maximum full suffix in pattern.
            s += gs[0];
        }
        else
        {
            // Shift the pattern so that the good suffix in text
            // aligns with the last occurrence of it in pattern.
            s += gs[j];
        }
    }

    delete gs;
}

// Driver program to test above function
int main()
{
    char txt[] = "AABAACAADAABAAABAA";
    char pat[] = "AABA";

    searchBM(pat, txt);
    return 0;
}
