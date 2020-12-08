#include <iostream>
#include <vector>
using namespace std;
const int N = 3001;

struct node {
	int sx, sy, ex, ey;
};


vector <node> vc;
int p[N];
int groupcnt, maxcnt;

int find(int a) {
	if (p[a] < 0) return a;
	return find(p[a]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	groupcnt--;
	p[a] += p[b];
	p[b] = a;
}

int ccw(pair<int,int> a, pair<int,int> b, pair<int,int> c) {
	int ro = (c.first - a.first)*(b.second - a.second) - (b.first - a.first) * (c.second - a.second);
	if (ro > 0) return 1;
	if (ro < 0) return -1;
	return 0;
}

bool intersect(pair<int,int> a, pair<int,int> b, pair<int,int> c, pair<int,int> d) {
	int r1 = ccw(a, b, d) * ccw(a, b, c);
	int r2 = ccw(c, d, a) * ccw(c, d, b);
	if (r1 == 0 && r2 == 0) { // one line
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		return c <= b && a <= d;
	}
	return r1 <= 0 && r2 <= 0; // cross
}

int main() {
	freopen("2162.txt", "r", stdin);
	int n;  scanf("%d", &n);
	vc.resize(n+1);
	groupcnt = n, maxcnt = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d %d", &vc[i].sx, &vc[i].sy, &vc[i].ex, &vc[i].ey);
		p[i] = -1;
	}
	for (int i = 1; i <= n-1; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (intersect({ vc[i].sx,vc[i].sy }, { vc[i].ex,vc[i].ey }, { vc[j].sx,vc[j].sy }, { vc[j].ex,vc[j].ey })) {
				merge(i,j);
			}
		}
	}
	for (int i = 1; i <= n; i++) if (maxcnt > p[i]) maxcnt = p[i];
	printf("%d\n%d\n", groupcnt, maxcnt*-1);
}