#include <iostream>
using namespace std;
#pragma warning(disable:4996)
#define N 200001

int seg[4 * N], loc[N];

int sum(int L, int R, int node, int leftnode, int rightnode) {
	if (L > rightnode || R < leftnode) return 0;
	if (L <= leftnode && rightnode <= R) return seg[node];
	int mid = (leftnode + rightnode) >> 1;
	return sum(L, R, 2 * node, leftnode, mid) + sum(L, R, 2 * node + 1, mid + 1, rightnode);
}

int te,n,m;

void update(int idx, int val) {
	seg[idx] = val;
	while (idx) {
		idx = idx / 2;
		seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
	}
}

int main() {
	freopen("3653.txt", "r", stdin);
	cin >> te;
	for (int tc = 1; tc <= te; tc++) {
		scanf("%d %d", &n, &m);
		memset(loc, 0, sizeof(loc));
		memset(seg, 0, sizeof(seg));
		int segsize = 1; while (segsize < n+m) segsize *= 2;
		for (int i = m; i < m + n; i++) {
			seg[segsize + i] = 1;  //segsize -> 0부터 m-1 공간
			update(segsize + i, 1);
		}
		for (int i = 1; i <= n; i++) loc[i] = m + i - 1; // m부터
		int cnt = m-1; int tmp;
		for (int i = 0; i < m; i++) {
			scanf("%d", &tmp);
			printf("%d ", sum(cnt+1, loc[tmp]-1, 1, 0, segsize-1));
			update(segsize + loc[tmp], 0);
			loc[tmp] = cnt; 
			cnt--;
			update(segsize + loc[tmp] ,1);
		}
		cout << endl;
	}
}