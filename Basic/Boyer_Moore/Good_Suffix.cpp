#include <stdio.h>
#include <string.h>

// unmatched minimum index
int *createGS(char *pattern, int M)
{
    int *gs = new int[M];
    int i;     // pattern index
    int j = 0; // shift pattern index

    for (i = 0; i < M; ++i) gs[i] = M;  // length of pattern
    i = M - 1; // compare from last index

    while (i > 0)
    {
        if (j >= 0 && pattern[i + j] == pattern[j]) // matching
        {
            j--;
        }
        else
        {
            if (j < 0) 
            {
                // suffix matches prefix of pattern
                for (; i + j >= 0; --j){
                    gs[i + j] = i;
                }
            }
            else
            {
                // shift index i that is the unmatched position
                gs[i + j] = i;
            }
            j = M - i;
            i--;
        }
        for (int z = 0; z < M; z++)
            printf("%d ", gs[z]);
        printf("\n");
    }
    for (int z=0; z < M ; z++) printf("%d ",gs[z]);
    printf("\n");
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
    char pat[] = "ABCDAB";
    printf("%s\n",pat);
    searchBM(pat, txt);

    return 0;
}
