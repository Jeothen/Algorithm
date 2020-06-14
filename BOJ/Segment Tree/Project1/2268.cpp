#include <iostream>
using namespace std;
const int N = 1e6 + 1;
typedef long long ll;
#pragma warning(disable:4996)

ll seg[4 * N];
int start = 1;

void modify(int idx, int val) {
	seg[idx] = val;
	while (idx) {
		idx /= 2;
		seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
	}
}

ll get_sum(int L, int R, int node, int leftnode, int rightnode) {
	if (L > rightnode || R < leftnode) return 0;
	if (L <= leftnode && rightnode <= R) return seg[node];
	int mid = (leftnode + rightnode) >> 1;
	return get_sum(L, R, 2 * node, leftnode, mid) + get_sum(L, R, 2 * node + 1, mid + 1, rightnode);
}

int main() {
	freopen("2268.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	while (n > start) start *= 2;
	int a, b, c;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (a) modify(start+b-1, c);
		else {
			if (b > c) swap(b, c);
			printf("%lld\n", get_sum(start + b - 1, start + c - 1, 1, start, 2 * start - 1));
		}
	}
}