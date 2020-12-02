#include <stdio.h>


int data[10];
int t[10];
int n;
int count;

void powerset(int n, int k) {
	if (n == k) {
		count++;
		for (int i = 0; i < n; i++) {
			if (t[i] == 1) {
				printf("%d ", data[i]);
			}
		}
		printf("\n");
	}
	else {
		t[k] = 1;
		powerset(n, k + 1);
		t[k] = 0;
		powerset(n, k + 1);
	}
}


int main() {
	n = 10;
	count = 0;
	for (int i = 0; i < n; i++) {
		data[i] = i + 1;
		t[i] = 0;
	}
	powerset(n, 0);
	printf("%d\n", count);
}