#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define node 1001
#define INF 2'100'000'000

vector <pair<int, int>> vc[node]; // value, idx
bool visited[node];
int dist[node];

int main() {
	freopen("1916.txt", "r", stdin);
	int N, M; scanf("%d %d", &N, &M);
	int s, e, v;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &s, &e, &v);
		vc[s].push_back({ v,e });
	}
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	int start, end;
	scanf("%d %d", &start, &end);
	pq.push({ 0,start });
	for (int i = 1; i <= N; i++) dist[i] = INF;
	dist[start] = 0;
	while (!pq.empty()) {
		int val = pq.top().first, now = pq.top().second;
		pq.pop();
		visited[now] = true;
		for (auto i = 0; i < vc[now].size(); i++) {
			int d = vc[now][i].first, next = vc[now][i].second;
			if (!visited[next]) {
				if (dist[next] > val + d) {
					dist[next] = val + d;
					pq.push({ dist[next],next });
				}
			}
		}
	}
	printf("%d\n" ,dist[end]);
}