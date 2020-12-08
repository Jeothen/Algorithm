#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 2'000'000'000
#pragma warning(disable:4996)
const int N = 524'288;

int seg[2 * N];
struct score {
	int x, y, z;
};
vector <score> vc;

void update(const int& idx, const int& val) {
	int index = N + idx;
	seg[index] = val;
	while (index) {
		index /= 2;
		seg[index] = min(seg[2 * index], seg[2 * index + 1]);
	}
}

int get_min(const int& L, const int& R, const int& node, const int& leftnode, const int& rightnode) {
	if (L > rightnode || R < leftnode) return INF;
	if (L <= leftnode && rightnode <= R) return seg[node];
	int mid = (leftnode + rightnode) >> 1;
	return min(get_min(L, R, 2 * node, leftnode, mid), get_min(L, R, 2 * node + 1, mid + 1, rightnode));
}

bool cmp(const score& a, const score& b) { return a.x < b.x; }


int main() {
	freopen("2336.txt", "r", stdin);
	int n; int ans = 0;
	scanf("%d", &n);
	vc.resize(n);
	int tmp;
	// 등수가 아니라 1등부터 학생의 번호
	for (int i = 0; i < 3; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &tmp);
			if (i == 0) vc[tmp-1].x = j;
			else if (i == 1) vc[tmp-1].y = j;
			else vc[tmp-1].z = j;
		}
	}
	sort(vc.begin(), vc.end(),cmp);
	for (int i = 0; i < n; i++) update(i, INF);
	// 점수가 아니라 등수...
	for (int i = 0; i < n; i++) {
		if (vc[i].z < get_min(0,vc[i].y-1, 1, 0, N - 1)) ans++;
		update(vc[i].y - 1, vc[i].z);
	}
	cout << ans << endl;
}