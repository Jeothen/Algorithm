#include <iostream>
using namespace std;
#pragma warning(disable:4996)
const int N = 1e5 + 1;
typedef long long ll;

ll seg[4 * N];
int start = 1;

ll get_sum(int L, int R, int node, int leftnode, int rightnode) {
	if (L > rightnode || R < leftnode) return 0;
	if (L <= leftnode && rightnode <= R) return seg[node];
	int mid = (leftnode + rightnode) >> 1;
	return get_sum(L, R, 2 * node, leftnode, mid) + get_sum(L, R, 2 * node + 1, mid + 1, rightnode);
}

void update(int idx, int val) {
	int index = start + idx - 1;
	seg[index] = val;
	while (index) {
		index /= 2;
		seg[index] = seg[2 * index] + seg[2 * index + 1];
	}
}

int main() {
	freopen("1275.txt", "r", stdin);
	int n, q;
	scanf("%d %d", &n, &q);
	while (n > start) start *= 2;
	for (int i = 0; i < n; i++) scanf("%lld", &seg[start + i]);
	for (int i = start - 1; i > 0; i--) seg[i] = seg[2 * i] + seg[2 * i + 1];  // construct
	int x, y, a, b;
	for (int i = 0; i < q; i++) {
		scanf("%d %d %d %d", &x, &y, &a, &b);
		if (x > y) swap(x, y);
		printf("%lld\n",get_sum(start+x-1, start+y-1, 1, start, 2 * start - 1));
		update(a, b);
	}
}
