#pragma warning(disable:4996)
#include <iostream>
using namespace std;

typedef long long ll;
const int N = 1e6 + 1;
ll seg[4*N], siz;

void getsiz(int n) {  // siz : 2^n��° ����ؼ� ��� index���� �⺻ �迭�� ������ �� ����
	siz = 1; while (n > siz) siz *= 2;
}

void init() {  // �⺻�迭�κ��� ���� Ʈ�� ����  (index�� 1���� ����)
	for (ll i = siz-1; i > 0 ; i--) seg[i] = seg[2*i] + seg[2*i+1];
}

void update(ll idx, ll val) {
	seg[idx] = val;
	while (idx > 1) {
		idx /= 2;
		seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
	}
}

ll getsum(ll L, ll R, ll nodeidx, ll nodeleft, ll noderight) {
	if (L > noderight || R < nodeleft) return 0;
	if (L <= nodeleft && R >= noderight) return seg[nodeidx];
	ll mid = (nodeleft + noderight ) >> 1 ;
	return getsum(L, R, nodeidx * 2, nodeleft, mid) + getsum(L, R, nodeidx * 2 + 1, mid + 1, noderight);
}

int main() {
	freopen("input.txt", "r", stdin);
	int n, m, k;
	cin >> n >> m >> k;
	getsiz(n);
	for (int i = 0; i < n; i++) scanf("%lld", &seg[siz + i]);  // siz���� siz+n-1���� ���
	init();
	ll a, b, c;
	for (int i = 0; i < m + k; i++) {
		scanf("%lld %lld %lld", &a, &b, &c);
		if (a == 1) update(siz+b-1, c);  // b��° ���� c�� ����
		else printf("%lld\n", getsum(siz+b-1, siz+c-1, 1, siz, 2*siz-1));  // b��°���� c��° 
		// mid���� 2^n�� �߰��� �Ǿ���ϱ� ������ ������ siz���� 2*siz-1���� ����ش�.

	}
}