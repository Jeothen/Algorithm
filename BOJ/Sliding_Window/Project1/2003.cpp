#include <cstdio>
const int N = 10001;

int arr[N];

int main() {
	freopen("2003.txt", "r", stdin);
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	int cnt = 0, sum = 0, low = 0, hi = 0;
	while (hi <= n) { // point
		if (sum >= m) sum -= arr[low++];
		else sum += arr[hi++];
		if (sum == m) cnt++;
	}
	printf("%d\n", cnt);
}