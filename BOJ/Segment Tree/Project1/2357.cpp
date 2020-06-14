#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)
#define INF 2'000'000'001
const int N = 1e5 + 1;

typedef long long ll;
ll maximum[4 * N];
ll minimum[4 * N];
int siz;

void getsiz(int n) {
	siz = 1; while (n > siz) siz *= 2;
}

void init() {
	for (int i = siz - 1; i >= 0; i--) {
		maximum[i] = max(maximum[2 * i], maximum[2 * i + 1]);
		minimum[i] = min(minimum[2 * i], minimum[2 * i + 1]);
	}
}

ll getmax(int a, int b, int nodeidx, int leftnode, int rightnode) {
	if (a > rightnode || b < leftnode) return 0;
	if (a <= leftnode && rightnode <= b) return maximum[nodeidx];
	int mid = (leftnode + rightnode) >> 1;
	return max(getmax(a, b, 2 * nodeidx, leftnode, mid), getmax(a, b, 2 * nodeidx + 1, mid + 1, rightnode));

}

ll getmin(int a, int b, int nodeidx, int leftnode, int rightnode) {
	if (a > rightnode || leftnode > b) return INF;
	if (a <= leftnode && rightnode <=b ) return minimum[nodeidx];
	int mid = (leftnode + rightnode) >> 1;
	return min(getmin(a, b, 2 * nodeidx, leftnode, mid), getmin(a, b, 2 * nodeidx + 1, mid + 1, rightnode));
}

int main() {
	freopen("2357.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	getsiz(n);
	ll tmp;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &tmp);
		maximum[siz + i] = tmp; minimum[siz + i] = tmp;
	}
	init();
	int a,b ;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);		
		printf("%lld %lld\n", getmin(siz + a - 1, siz + b - 1, 1, siz, 2 * siz - 1),getmax(siz+a-1,siz+b-1,1,siz,2*siz-1));
	}
}