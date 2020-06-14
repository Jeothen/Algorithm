#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#pragma warning(disable:4996)
const int N = 100001;
int arr[N];

int main() {
	freopen("1365.txt", "r", stdin);
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	vector <int> lis; lis.push_back(-1);
	for (int i = 0; i < n; i++) {
		if (lis.back() < arr[i]) lis.push_back(arr[i]);
		else {
			int it = lower_bound(lis.begin(), lis.end(),arr[i])-lis.begin();
			lis[it] = arr[i];
		}
	}
	printf("%zd\n",n-lis.size()+1);
}

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

vector <int> seg;
vector <pair<int, int>> arr;

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
		seg[idx] = max(seg[2 * idx],seg[2 * idx + 1]);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	int n; scanf("%d", &n);
	int tmp;
	int start = 1; while (n > start) start *= 2;
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		arr.push_back({ tmp,i });
	}
	sort(arr.begin(), arr.end());
	seg.resize(2 * start);
	for (int i = 0; i < n; i++) {
		int idx = arr[i].second;
		int maximum = get_max(start, start + idx, 1, start, 2 * start - 1) + 1;
		update(start+idx, maximum);
	}
	cout << n - seg[1] << endl;
}

*/