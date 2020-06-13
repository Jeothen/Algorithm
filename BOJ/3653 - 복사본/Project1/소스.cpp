#include <iostream>
#include <cstring>
using namespace std;
#pragma warning(disable:4996)
#define N 1000000
#define segsize 1048575
typedef long long ll;

ll seg[2 * segsize];

void update(ll val, ll cnt) {
	ll idx = val;
	seg[idx] += cnt;
	if (seg[idx] < 0) seg[idx] = 0;
	while (idx) {
		idx /= 2; seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
	}
}

ll get_query(ll val, ll node) {
	if (seg[2 * node] < val) {	
		if (node > segsize) {  // leaf
			update(node, -1);
			return node - segsize;
		}
		return get_query(val - seg[2 * node], 2 * node + 1);
	}
	else {
		if (node > segsize) {  // leaf
			update(node, -1);
			return node - segsize;
		}
		return get_query(val, 2 * node);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	int a,b,c,n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		if (a == 1) {
			scanf("%d", &b);
			printf("%lld\n", get_query(b, 1));
		}
		else {
			scanf("%d %d", &b, &c);
			update(segsize + b, c);
		}
	}
}