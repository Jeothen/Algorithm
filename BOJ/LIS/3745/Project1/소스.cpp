#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#pragma warning(disable:4996)
int const N = 1e5 + 1;

bool cmp(pair<int, int > a, pair<int, int> b) {
	if (a.first == b.first) return a.second > b.second;
	return a.first < b.first;
}

vector <int> seg;

int get_max(int L, int R, int node, int leftnode, int rightnode) {
	if (L > rightnode || leftnode > R) return 0;
	if (L <= leftnode && rightnode <= R) return seg[node];
	int mid = (leftnode + rightnode) >> 1;
	return max(get_max(L, R, 2 * node, leftnode, mid), get_max(L, R, 2 * node + 1, mid + 1, rightnode));
}

void update(int idx, int val) {
	seg[idx] = val;
	while (idx) {
		idx /= 2;
		seg[idx] = max(seg[2 * idx], seg[2 * idx + 1]);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	int n;
	while (scanf("%d", &n) != EOF) {
		int start = 1; while (n > start) start *= 2;
		vector <pair<int,int>> arr(n);
		int tmp;
		for (int i = 0; i < n; i++) {
			scanf("%d", &tmp); arr[i] = { tmp,i };
		}
		sort(arr.begin(), arr.end(), cmp);
		seg.assign(2 * start + n, 0);
		for (int i = 0; i < n; i++) {
			int idx = arr[i].second; // index
			int maximum = get_max(start, start + idx, 1, start, 2 * start - 1) + 1;
			update(start+idx, maximum);
		}
		printf("%d\n", seg[1]);
	}
}