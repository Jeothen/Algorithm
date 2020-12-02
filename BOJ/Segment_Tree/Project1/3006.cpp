#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int n, start = 1;

vector <pair<int, int>> vc;
vector<int> seg;

void update(int idx, int val) {
	seg[idx] = val;
	while (idx) {
		idx = idx >> 1;  
		seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
	}
}

int get_sum(int L, int R, int node, int leftnode, int rightnode) {
	if (R < leftnode || L > rightnode) return 0;
	if (L <= leftnode && rightnode <= R) return seg[node];
	int mid = (leftnode + rightnode) >> 1;
	return get_sum(L, R, 2 * node, leftnode, mid) + get_sum(L, R, 2 * node + 1, mid + 1, rightnode);
}

int main() {
	freopen("3006.txt", "r", stdin);
	scanf("%d", &n);	
	while (n > start) start = start << 1;
	seg.resize(2 * start);
	for (int i = 0, tmp; i < n; i++) {	
		scanf("%d", &tmp); 
		vc.push_back({ tmp-1,i });
	}
	sort(vc.begin(), vc.end());
	for (int i = 0; i < n; i++) {
		seg[i + start] = 1;
		update(start+i, 1);
	}
	for (int i = 0; i < n; i++) {
		if (i % 2) {
			printf("%d\n", get_sum(vc[n-(i/2)-1].second, n-1, 1, 0, start-1)-1);
			update(start+vc[n-(i/2)-1].second, 0);
		}
		else {
			printf("%d\n",get_sum(0, vc[(i/2)].second, 1, 0, start-1) -1);
			update(start+vc[(i / 2)].second, 0);
		}
	}
}