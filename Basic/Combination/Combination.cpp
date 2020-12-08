#include <iostream>
using namespace std;

int data[10];
int t1[10];
int t2[10];
int n;
int count1, count2;

void combination(int n, int k, int q) { // q is just display count number
	if (k == 0) {
		count1++;
		for (int i = 0; i < q; i++) 
			printf("%d ", t1[i]);
		printf("\n");
	}
	else if (n < k) return;
	else {
		t1[k - 1] = data[n - 1]; 
		combination(n - 1, k - 1, q);
		combination(n - 1, k, q);
	}
}

void recursive_combination(int n, int k, int q) {
    if (k == 0) {
        count2++;
        for (int i = 0; i < q; i++) 
            printf("%d ", t2[i]);
        printf("\n");
    }
    else if (n == 0) return;
    else {
        t2[k - 1] = data[n - 1];
        recursive_combination(n, k - 1, q);
        recursive_combination(n - 1, k, q);
    }
}


int main() {
	n = 5;
	count1 = 0;
	for (int i = 0; i < n; i++) {
		data[i] = i + 1;
	}
    // nC2
	combination(n, 3, 3);
	printf("%d\n", count1);
    
    // nHr
    recursive_combination(n, 2, 2);
    printf("%d\n", count2);
}
