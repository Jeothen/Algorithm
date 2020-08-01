#include <iostream>
#include <queue>
#include <vector>
#define INF 2'100'000'000
#define node 20001
using namespace std;

vector<pair<int, int>> vc[node];
int dist[node];
bool visited[node];

int main() {
	freopen("1753.txt", "r", stdin);
	int V, E; scanf("%d %d", &V, &E);
	int e, u, v, w; scanf("%d", &e);
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &u, &v, &w);
		vc[u].push_back({ w,v }); // value, idx
	}
	for (int i = 1; i <= V; i++) dist[i] = INF;  dist[e] = 0;
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // value, idx
	pq.push({ 0,e });
	while (!pq.empty()) {
		int oval = pq.top().first, now = pq.top().second;
		visited[now] = true;
		pq.pop();
		for (auto i = 0; i < vc[now].size(); i++) {
			int d = vc[now][i].first, next = vc[now][i].second;
			if (!visited[next]) {
				if (dist[next] > oval + d) {
					dist[next] = oval + d;
					pq.push({ dist[next], next });
				}
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		(dist[i] != INF) ? printf("%d\n", dist[i]) : printf("INF\n");
	}
}