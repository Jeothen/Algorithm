#include <iostream>
#pragma warning(disable:4996)
#include <algorithm>
using namespace std;


int BinarySearch(int *A, int num, int l, int r) {

	int R = r;
	int L = l;
	while (L <= R) {
		int mid = (R + L) / 2;
		if (A[mid] == num) return 1;
		if (num < A[mid]) R = mid - 1;
		else L = mid + 1;
	}
	return 0;
}

int main() {
	int n;
	scanf("%d", &n);
	int A[100001] = {};
	for (int i = 0; i < n; i++) scanf("%d", &A[i]);
	int m;
	sort(A, A + n);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int temp;
		scanf("%d", &temp);
		printf("%d\n", BinarySearch(A, temp, 0, n));
	}
	return 0;
}