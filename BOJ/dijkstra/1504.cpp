#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#define node 801
using namespace std;
#define INF 300'000'000

vector <pair<int, int>> vc[node];

int dijkstra(int N, int s, int e) {
	int dist[node];
	bool visited[node];
	memset(dist, 0, sizeof(dist));
	memset(visited, 0, sizeof(visited));

	for (int i = 0; i <= N; i++) dist[i] = INF;
	dist[s] = 0;

	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,s });
	while (!pq.empty()) {
		int value = pq.top().first, now = pq.top().second;
		pq.pop();
		visited[now] = true;
		for (auto i = 0; i < vc[now].size(); i++) {
			int d = vc[now][i].first, next = vc[now][i].second;			
			if (!visited[next]) {
				if (dist[next] > d + value) {
					dist[next] = d + value;
					pq.push({ dist[next],next });
				}
			}
		}
	}
	return dist[e];
}


int main() {
	freopen("1504.txt", "r", stdin);
	int N, E;  scanf("%d %d", &N, &E);
	int a, b, c, s1, s2;
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &a, &b, &c);
		vc[a].push_back({ c,b });
		vc[b].push_back({ c,a });
	}
	scanf("%d %d", &s1, &s2);
	int ans1 = dijkstra(N, 1, s1) + dijkstra(N, s1, s2) + dijkstra(N, s2, N);
	int ans2 = dijkstra(N, 1, s2) + dijkstra(N, s2, s1) + dijkstra(N, s1, N);
	int ans = min(ans1, ans2);

	(ans >= INF) ? printf("-1\n") : printf("%d\n", ans);
}