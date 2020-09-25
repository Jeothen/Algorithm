#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
#define comput 1001
int n, m;

priority_queue < tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>> > pq;
int parent[comput], siz[comput];
int answer, cnt;

int find(int a) {
	if (parent[a] == a) return a;
	return find(parent[a]);
}

void mst() {
	while (!pq.empty()) {
		int value = get<0>(pq.top()), start = get<1>(pq.top()), end = get<2>(pq.top());
		pq.pop();
		int p1 = find(start), p2 = find(end);
		if (p1 != p2) {
			answer += value;
			cnt++;
			if (cnt == n - 1) break;
			if (siz[p1] < siz[p2]) swap(p1, p2);
			siz[p1]++;
			parent[p2] = p1;
		}
	}
}

int main() {
	answer = 0;
	scanf("%d %d", &n, &m);
	int a, b, c;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		pq.push({ c,a,b }); // 가중치, 시작, 도착
	}
	for (int i = 1; i <= n; i++) siz[i] = 1;
	for (int i = 1; i <= n; i++) parent[i] = i;
	mst();
	printf("%d\n", answer);
}