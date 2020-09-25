#include <stdio.h>


int data[10];
int t[10];
int n;
int count;

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void recursive_permutation(int n, int k, int q) {
	if (k == 0) {
		count++;
		for (int i = 0; i < q; i++) {
			printf("%d ", t[i]);
		}
		printf("\n");
	}
	else {
		for (int i = n - 1; i >= 0; i--) {
			swap(&data[i], &data[n - 1]);
			t[k - 1] = data[n - 1];
			recursive_permutation(n, k - 1, q);
			swap(&data[i], &data[n - 1]);
		}
	}
}


int main() {
	n = 5;
	count = 0;
	for (int i = 0; i < n; i++) {
		data[i] = i + 1;
		t[i] = 0;
	}
	recursive_permutation(n, 3, 3);
	printf("%d\n", count);
}