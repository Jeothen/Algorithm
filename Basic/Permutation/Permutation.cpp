#include <stdio.h>


int data[10];
int t1[10], t2[10];
int n;
int count1, count2;

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void permutation(int n, int k, int q) {  // q is just number of print count
	if (k == 0) {
		count1++;
		for (int i = 0; i < q; i++) {
			printf("%d ", t1[i]);
		}
		printf("\n");
	}
	else {
		for (int i = n - 1; i >= 0; i--) {
			swap(&data[i], &data[n - 1]);  // order swap
			t1[k - 1] = data[n - 1];      // value
			permutation(n - 1, k - 1, q);  // recursion
			swap(&data[i], &data[n - 1]);  // recover
		}
	}
}


void recursive_permutation(int n, int k, int q) {
    if (k == 0) {
        count2++;
        for (int i = 0; i < q; i++) {
            printf("%d ", t2[i]);
        }
        printf("\n");
    }
    else {
        for (int i = n - 1; i >= 0; i--) {
            swap(&data[i], &data[n - 1]);
            t2[k - 1] = data[n - 1];
            recursive_permutation(n, k - 1, q); // enable duplication
            swap(&data[i], &data[n - 1]);
        }
    }
}



int main() {
	n = 5;
	count1 = 0, count2 = 0;
	for (int i = 0; i < n; i++) {
		data[i] = i + 1;
		t1[i] = 0;
	}
	permutation(n, 3, 3);
	printf("%d\n", count1);

	for (int i = 0; i < n; i++)
	{
		data[i] = i + 1;
		t2[i] = 0;
	}
	recursive_permutation(n, 3, 3);
    printf("%d\n", count2);
}
