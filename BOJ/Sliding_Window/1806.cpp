#include <iostream>
#include <vector>
using namespace std;

vector <int> vc;

int main() {
	freopen("1806.txt", "r", stdin);
	int n, m; scanf("%d %d", &n, &m);
	bool chk = false;
	int val;
	int l = 0, r = 0, sum = 0, min = 100001;
	for (int i = 0; i < n; i++) {
		scanf("%d", &val); vc.push_back(val);
	}
	while (r <= vc.size()) {
		if (sum < m) {
			if (r == vc.size()) break;
			sum += vc[r++];
		}
		else {
			min = (min > r - l) ? r - l : min;
			sum -= vc[l++];
		}
	}
	if (min == 100001) printf("0\n");
	else printf("%d\n", min);
}