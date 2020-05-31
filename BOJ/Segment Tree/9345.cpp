#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#pragma warning(disable:4996)
#define N 100001
#define INF 2000000001

int max_seg[4 * N], min_seg[4*N];

void max_update(int idx, int val) {
	max_seg[idx] = val;
	while (idx) {
		idx /= 2;
		max_seg[idx] = max(max_seg[2 * idx], max_seg[2 * idx + 1]);
	}
}

void min_update(int idx, int val) {
	min_seg[idx] = val;
	while (idx) {
		idx /= 2;
		min_seg[idx] = min(min_seg[2 * idx], min_seg[2 * idx + 1]);
	}
}

int max_query(int L, int R, int node, int leftnode, int rightnode) {
	if (L > rightnode || R < leftnode) return 0;
	if (L <= leftnode && rightnode <= R) return max_seg[node];
	int mid = (leftnode + rightnode) >> 1;
	return max(max_query(L, R, 2 * node, leftnode, mid), max_query(L, R, 2 * node + 1, mid + 1, rightnode));
}

int min_query(int L, int R, int node, int leftnode, int rightnode) {
	if (L > rightnode || R < leftnode) return INF;
	if (L <= leftnode && rightnode <= R) return min_seg[node];
	int mid = (leftnode + rightnode) >> 1;
	return min(min_query(L, R, 2 * node, leftnode, mid), min_query(L, R, 2 * node + 1, mid + 1, rightnode));
}

int main() {
	freopen("input.txt", "r", stdin);
	int te, n,k, q, a, b;
	cin >> te;
	for (int tc = 1; tc <= te; tc++) {
		scanf("%d %d", &n, &k);
		int segsize = 1; while (segsize < n) segsize *= 2;
		for (int i = 0; i < n; i++) {
			max_update(segsize + i, i);
			min_update(segsize + i, i);
		}
		for (int i = n+1; i <= segsize; i++) min_update(segsize + i - 1, INF);
		
		
		for (int i = 0; i < k; i++) {
			scanf("%d %d %d", &q, &a, &b);
			if (q == 1) { // check if continuous number
				if (a == min_query(a, b, 1, 0, segsize-1) && b == max_query(a, b, 1, 0, segsize-1)) printf("YES\n");
				else printf("NO\n");
			}
			else {
				swap(min_seg[segsize + a], min_seg[segsize + b]); swap(max_seg[segsize + a], max_seg[segsize + b]);
				min_update(segsize + a, min_seg[segsize + a]); max_update(segsize + a, max_seg[segsize + a]);
				min_update(segsize + b, min_seg[segsize + b]); max_update(segsize + b, max_seg[segsize + b]);
			}
		}
		memset(max_seg, 0, sizeof(int) * 2 * segsize);
		memset(min_seg, 0, sizeof(int) * 2 * segsize);
	}
}