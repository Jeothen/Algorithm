#include <stdio.h>


int data[10];
int t[10];
int n;
int count;

void combination(int n, int k, int q) {
	if (k == 0) {
		count++;
		for (int i = 0; i < q; i++)
			printf("%d ", t[i]);
		printf("\n");
	}
	else if (n < k) return;
	else {
		t[k - 1] = data[n - 1];
		combination(n - 1, k - 1, q);
		combination(n - 1, k, q);
	}
}


int main() {
	n = 10;
	count = 0;
	for (int i = 0; i < n; i++) {
		data[i] = i + 1;
	}
	combination(n, 2, 2);
	printf("%d\n", count);
}