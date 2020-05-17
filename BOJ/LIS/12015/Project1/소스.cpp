#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e6 + 1;
int seg[4 * N], start = 1;
vector <pair<int, int>> arr;

bool cmp(pair<int, int> a, pair<int, int>b) {
	if (a.first == b.first) return a.second > b.second;
	return a.first < b.first;
}

int get_max(int L, int R, int node, int nodeleft, int noderight) {
	if (L > noderight || R < nodeleft) return 0;
	if (L <= nodeleft && noderight <= R) return seg[node];
	int mid = (nodeleft + noderight) >> 1;
	return max(get_max(L, R, 2 * node, nodeleft, mid), get_max(L, R, 2 * node + 1, mid + 1, noderight));
}

void update(int idx, int val) {
	seg[idx] = val;
	while (idx) {
		idx /= 2;
		seg[idx] = max(seg[2 * idx], seg[2 * idx + 1]);
	}
}

int main() {
	int n; cin >> n;
	while (n > start) start *= 2;
	int tmp;
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		arr.push_back({ tmp,i });
	}
	sort(arr.begin(), arr.end(), cmp);
	for (int i = 0; i < n; i++) {
		int idx = arr[i].second;
		int get_value = get_max(start, start + idx, 1, start, 2 * start - 1) + 1;
		update(start + idx, get_value);
	}
	cout << seg[1];
}


/*  lower_bound
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int n;
vector <int> arr;
vector <int> lis;

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int tmp; scanf("%d", &tmp);
		arr.push_back(tmp);
	}
	lis.push_back(0);
	for (int i = 0; i < n; i++) {
		if (lis.back() < arr[i]) lis.push_back(arr[i]);
		else {
			auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
			*it = arr[i];
		}
	}
	printf("%zd\n", lis.size() - 1);
}

*/