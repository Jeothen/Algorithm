#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#pragma warning(disable:4996)
typedef long long ll;
#define MOD 1'000'000'007
#define segsize 262144

int n;
vector <ll> summary;
vector <int> cnt;

void update(int idx, int val) {
	summary[idx] += val;
	cnt[idx] ++;
	while (idx) {
		idx = idx >> 1;
		summary[idx] = summary[2 * idx] + summary[2 * idx + 1];
		cnt[idx] = cnt[2 * idx] + cnt[2 * idx + 1];
	}
}

ll sum_Query(int L, int R, int node, int leftnode, int rightnode) {
	if (L > rightnode || R < leftnode) return 0;
	if (L <= leftnode && rightnode <= R) return summary[node];
	int mid = (leftnode + rightnode) >> 1;
	return sum_Query(L, R, 2 * node, leftnode, mid) + sum_Query(L, R, 2 * node + 1, mid + 1, rightnode);
}

ll cnt_Query(int L, int R, int node, int leftnode, int rightnode) {
	if (L > rightnode || R < leftnode) return 0;
	if (L <= leftnode && rightnode <= R) return cnt[node];
	int mid = (leftnode + rightnode) >> 1;
	return cnt_Query(L, R, 2 * node, leftnode, mid) + cnt_Query(L, R, 2 * node + 1, mid + 1, rightnode);
}

int main() {
	freopen("1280.txt", "r", stdin);
	scanf("%d", &n);
	summary.resize(2 * segsize, 0); cnt.resize(2 * segsize, 0);
	int val;
	ll answer = 1;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			scanf("%d", &val); update(segsize + val, val);
		}
		else {
			ll L, R;
			scanf("%d", &val);
			L = val * cnt_Query(0, val, 1, 0, segsize) - sum_Query(0, val, 1, 0, segsize);
			R = sum_Query(val+1, 200000, 1, 0, segsize) - val * cnt_Query(val+1, 200000, 1, 0, segsize);
//			cout << L << " " << R << " " << answer<< endl;
			answer = (L + R) % MOD * answer % MOD;
			update(segsize + val, val);
		}
	}
	cout << answer << endl;
} 