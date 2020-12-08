#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
#define node 1001
#define INF 100'000'000

vector <pair<int, int>> vc[node];
int N;

int dijkstra(int start, int end) {
	int dist[node] = { 0, };
	bool visited[node] = { 0, };
	
	for (int i = 1; i <= N; i++) dist[i] = INF; dist[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });
	while (!pq.empty()) {
		int time = -pq.top().first, now = pq.top().second;
		pq.pop();
		visited[now] = true;
		if (visited[end]) break;
		for (auto i = 0; i < vc[now].size(); i++) {
			int next = vc[now][i].second, st = vc[now][i].first;
			if (!visited[next]) {
				if (time + st < dist[next]) {
					dist[next] = time + st;
					pq.push({ -dist[next],next });
				}
			}
		}
	}
	return dist[end];

}

int main() {
	freopen("1238.txt", "r", stdin);
	int s, e, t, M, X; scanf("%d %d %d", &N, &M, &X);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &s, &e, &t);
		vc[s].push_back({ t,e });
	}
	int maximum = 0;
	for (int i = 1; i <= N; i++) {
		int tmp = dijkstra(i,X) + dijkstra(X,i);
		maximum = (maximum < tmp) ? tmp : maximum;
	}
	printf("%d\n", maximum);
}