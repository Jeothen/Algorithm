#include <stdio.h>
#include <string.h>

#define NUM_OF_CHARS 256

int max(int a, int b) { return (a > b) ? a : b; }

// The preprocessing function for Boyer Moore's bad character heuristic
int *createBC(char *pat, int M)
{
    int *bc = new int[NUM_OF_CHARS];
    for (int i = 0; i < NUM_OF_CHARS; ++i) bc[i] = -1;

    // Save the last index where the character appeared
    for (int i = 0; i < M - 1; ++i)
    {
        bc[(int)pat[i]] = i;
    }
    for (int i = 0; i < M; i++)
        printf("%d ", bc[int(pat[i])]);
    printf("\n");
    return bc;
}

void searchBM(char *pat, char *txt)
{
    int N = strlen(txt);
    int M = strlen(pat);
    int *bc = createBC(pat, M);

    int s = 0; // Shift of the pattern with respect to text (start)
    int j = 0; // Index for pat[]

    while (s <= (N - M))
    {
        j = M - 1; // from last character

        while (j >= 0 && pat[j] == txt[s + j]) j--;

        if (j < 0) 
        {
            printf("Pattern found at index %d \n", s);
            s += (s + M < N) ? M - bc[txt[s + M]] : 1;
        }
        else
        {
            s += max(1, j - bc[txt[s + j]]);
        }
    }
    delete bc;
}

int main()
{
    char txt[] = "AABACAADAABAAABAC";
    char pat[] = "AABAC";

    searchBM(pat, txt);

    return 0;
}
