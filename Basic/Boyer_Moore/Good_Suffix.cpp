#include <stdio.h>
#include <string.h>

// The preprocessing function for Boyer Moore's good suffix heuristic
int *createGS(char *pat, int M)
{
    int *gs = new int[M];
    int i;     // index for pattern suffix
    int j = 0; // index for partial pattern suffix

    // initialize gs array
    for (i = 0; i < M; ++i)
        gs[i] = M;

    i = M - 1;
    while (i > 0)
    {
        if (j >= 0 && pat[i + j] == pat[j])
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

void searchBM(char *pat, char *txt)
{
    int N = strlen(txt);
    int M = strlen(pat);
    int *gs = createGS(pat, M);
    int s = 0; // Shift of the pattern with respect to text
    int j = 0; // Index for pat[]

    while (s <= (N - M))
    {
        j = M - 1;

        // Keep reducing index j of pattern while characters of
        // pattern and text are matching at this shift s
        while (j >= 0 && pat[j] == txt[s + j])
            j--;

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
