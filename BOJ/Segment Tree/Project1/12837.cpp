#include <iostream>
using namespace std;
#pragma warning(disable:4996)

const int N = 1000000;
typedef long long ll;
ll seg[4 * N];
int start = 1;

void update(int idx, int val) {
	seg[idx] += val;	
	while (idx > 1) {
		idx /= 2;
		seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
	}
}

ll get_sum(int left, int right, int node, int nodeleft, int noderight) {
	if (noderight < left || nodeleft > right) return 0;
	if (left <= nodeleft && noderight <= right) return seg[node];
	int mid = (nodeleft + noderight) >> 1;
	return get_sum(left, right, 2 * node, nodeleft, mid) + get_sum(left, right, 2 * node + 1, mid + 1, noderight);
}

int main() {
	freopen("12837.txt", "r", stdin);
	int n, q;
	scanf("%d %d", &n, &q);
	while (n > start) start *= 2;
	int a, p, x;
	for (int i = 0; i < q; i++) {
		scanf("%d %d %d", &a, &p, &x);
		if (a == 1) update(start+p-1, x);
		else printf("%lld\n", get_sum(start+p-1, start+x-1,1, start, 2 * start - 1));
	}
}