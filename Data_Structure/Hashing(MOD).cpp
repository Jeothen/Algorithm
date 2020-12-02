#include <stdio.h>

#define MOD 1000000009
char text[500001];
char pattern[100001];

int main() {
	int te;
	scanf("%d", &te);
	for (int tc = 1; tc <= te; tc++) {
		scanf("%s", &text);
		scanf("%s", &pattern);
		int answer = 0;
		int lena, lenb;
		long long texthash = 0, patternhash = 0, power = 1;
		for (lena = 0; text[lena] != '\0'; lena++);
		for (lenb = 0; pattern[lenb] != '\0'; lenb++);
		for (int i = 0; i < lenb; i++) {
			texthash = (texthash * 257 + text[i]) % MOD;
			patternhash = (patternhash * 257 + pattern[i]) % MOD;
			if (i != 0) power = (power * 257) % MOD;
		}
		for (int i = 0; i <= lena - lenb; i++) {
			if (texthash == patternhash) answer += 1;
			texthash = (257 * (texthash - text[i] * power) + text[i + lenb]) % MOD;
			if (texthash < 0) texthash += MOD;
		}
		printf("#%d %d\n", tc, answer);
	}
	return 0;
}