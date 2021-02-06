#include <stdio.h>
#include <string.h>

#define NUM_OF_CHARS 256

int max(int a, int b) { return (a > b) ? a : b; }

// The preprocessing function for Boyer Moore's bad character heuristic
int *createBC(char *pat, int M)
{
    int *bc = new int[NUM_OF_CHARS];

    // Initialize all occurrences as -1
    for (int i = 0; i < NUM_OF_CHARS; ++i)
        bc[i] = -1;

    // Fill the actual value of last occurrence of a character
    for (int i = 0; i < M - 1; ++i)
        bc[(int)pat[i]] = i;

    return bc;
}

void searchBM(char *pat, char *txt)
{
    int N = strlen(txt);
    int M = strlen(pat);
    int *bc = createBC(pat, M);
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
            // Shift the pattern so that the next character in text
            // aligns with the last occurrence of it in pattern.
            s += (s + M < N) ? M - bc[txt[s + M]] : 1;
        }
        else
        {
            s += max(1, j - bc[txt[s + j]]);
        }
    }

    delete bc;
}

// Driver program to test above function
int main()
{
    char txt[] = "AABAACAADAABAAABAA";
    char pat[] = "AABA";

    searchBM(pat, txt);

    return 0;
}
