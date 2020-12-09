#include <stdio.h>


int data[10];
int t1[10], t2[10];
int n;
int count1;

void repeat_permutation(int n, int q, int k) {
    if (k == q) { // k is fulfilled to q
        count1++;
        for (int i = 0; i < q; i++) {
            printf("%d ", t2[i]);
        }
        printf("\n");
		return;
    }
	for (int i = 0; i < n; i++) {
		t2[k] = data[i];
		repeat_permutation(n, q, k+1); // enable duplication
	}
}

bool visited[10];

int main() {
	n = 6;
	count1 = 0;
	for (int i = 0; i < n; i++) {
		data[i] = i + 1;
		t1[i] = 0;
		t2[i] = 0;
		visited[i] = false;
	}
	repeat_permutation(n, 3, 0);
	printf("%d\n", count1);

}
