#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> pq;

int main() {
	freopen("2075.txt", "r", stdin);
	int val, n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &val);
			if (pq.size() < n) pq.push(-val);
			if (val > -pq.top()) {
				pq.pop(); pq.push(-val);
			}
		}
	}
	printf("%d\n", -pq.top());
}