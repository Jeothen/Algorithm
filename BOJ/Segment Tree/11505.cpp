#include <iostream>
using namespace std;
#pragma warning(disable:4996)
#define MOD 1000000007

int const N = 1e6 + 1;
int siz;
typedef long long ll;
ll seg[4 * N + 1];

void getsiz(int n) {
	siz = 1; while (n > siz) siz *= 2;
}

void init() {
	for (int i = siz - 1; i > 0; i--) seg[i] = (seg[2 * i] * seg[2 * i + 1]) % MOD;
}

void update(ll idx, ll val) {
	seg[idx] = val;
	while (idx > 0) {
		idx /= 2;
		seg[idx] = (seg[idx * 2] * seg[idx * 2 + 1]) % MOD;
	}
}

ll getsum(ll L, ll R, int nodeidx, int leftnode, int rightnode) {
	if (L > rightnode || R < leftnode) return 1;
	if (L <= leftnode && rightnode <= R) return seg[nodeidx];
	int mid = (leftnode + rightnode) >> 1;	
	ll lvalue = getsum(L, R, 2 * nodeidx, leftnode, mid) % MOD;
	ll rvalue = getsum(L, R, 2 * nodeidx + 1, mid + 1, rightnode) % MOD;
	return lvalue * rvalue % MOD;
}

int main() {
	freopen("input.txt", "r", stdin);
	int n, m, k;
	cin >> n >> m >> k;
	getsiz(n);
	for (int i = 0; i < n; i++) scanf("%lld", &seg[siz + i]);
	init();
	ll a, b, c;
	for (int i = 0; i < m + k; i++) {
		scanf("%lld %lld %lld", &a, &b, &c);
		if (a == 1) {
			update(siz+b-1, c);
		}
		else {
			if (b >=1 && c <= n) printf("%lld\n", getsum(siz+b-1, siz+c-1, 1, siz, 2*siz-1));
			else printf("0\n");
		}
	}
}