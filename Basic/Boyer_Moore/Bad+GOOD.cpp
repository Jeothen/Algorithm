#include <stdio.h>
#include <string.h>

#define NUM_OF_CHARS 256

int max(int a, int b) { return (a > b) ? a : b; }

int *createBC(char *pat, int M)
{
    int *bc = new int[NUM_OF_CHARS];
    for (int i = 0; i < NUM_OF_CHARS; ++i)
        bc[i] = -1;
    for (int i = 0; i < M - 1; ++i)
        bc[(int)pat[i]] = i;
    return bc;
}

int *createGS(char *pat, int M)
{
    int *gs = new int[M];
    int i, j = 0; 

    for (i = 0; i < M; ++i) gs[i] = M;

    i = M - 1;
    while (i > 0)
    {
        if (j >= 0 && pat[i + j] == pat[j]) j--;
        else
        {
            if (j < 0)
            {
                for (; i + j >= 0; --j)
                    gs[i + j] = i;
            }
            else
            {
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
    int *bc = createBC(pat, M);
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
            // Shift the pattern as max of bad character and good suffix.
            // So, bad character or good suffix in text aligns with the last
            // occurrence of it in pattern.
            s += max(j - bc[txt[s + j]], gs[j]);  // Bad Character & Good Suffix
        }
    }

    delete bc;
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
