// BOJ 11657

#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
#define node 501
const int INF = 1234567890;
typedef pair<int, int> P;
vector <P> vc[node];
int dist[501],n,m;
bool cycle;

void bellman_ford() {
	for (int i = 1; i<= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (auto &p : vc[j]) {
				int next = p.first, d = p.second;
				if (dist[j] != INF && dist[next] > dist[j] + d) {
					dist[next] = dist[j] + d;
					if (i == n) cycle = true;
				}
			}
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	int a, b, c;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		vc[a].push_back({ b,c });
	}
	fill(dist, dist + n+1, INF);
	dist[1] = 0;
	cycle = false;
	bellman_ford();
	if (cycle) {
		cout << -1;
	}
	else {
		for (int i = 2; i <= n; i++) {
			printf("%d\n", dist[i] != INF ? dist[i] : -1);
		}
	}
}