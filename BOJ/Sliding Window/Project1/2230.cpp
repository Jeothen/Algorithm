#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> vc;

int main() {
	freopen("2230.txt", "r", stdin);
	int val, n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &val); vc.push_back(val);
	}
	sort(vc.begin(), vc.end());
	int l = 0, r = 0;
	int minimum = 2'000'000'001;
	while (r < vc.size() && l < vc.size()) {
		if (vc[r] - vc[l] < m) r++;
		else {
			minimum = min(minimum, vc[r] - vc[l]);
			l++; // cors
		}
	}
	printf("%d\n", minimum);
}