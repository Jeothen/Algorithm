#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define NODE 126
#define INF 2'100'000'000

int N, arr[NODE][NODE], dist[NODE][NODE];
bool visited[NODE][NODE];


bool iswall(int x, int y) {
	if (x < 0 || x >= N) return true;
	if (y < 0 || y >= N) return true;
	return false;
}

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

int dijkstra() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) dist[i][j] = INF;
	}
	dist[0][0] = arr[0][0];

	priority_queue <pair<int, int>, vector< pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,0 });
	while (!pq.empty()) {
		int x = pq.top().first, y = pq.top().second;
		pq.pop();
		visited[x][y] = true;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (!iswall(nx, ny)) {
				if (dist[x][y] + arr[nx][ny] < dist[nx][ny]) {
					dist[nx][ny] = dist[x][y] + arr[nx][ny];
					pq.push({ nx,ny });
				}
			}
		}
	}
	return dist[N - 1][N - 1];
}

int main() {
	freopen("4485.txt", "r", stdin);
	int idx = 1;
	while (1) {
		scanf("%d", &N); if (!N) break;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &arr[i][j]);
				visited[i][j] = 0;
			}
		}
		printf("Problem %d: %d\n", idx++, dijkstra());
	}
}