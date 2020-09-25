#include <stdio.h>
#pragma warning(disable:4996)

// pq를 쓰고 edge node로 시간 복잡도를 kruskal만큼 줄일 수 있다

int graph[1001][1001];
int dist[1001];

int main() {
	freopen("input.txt", "r", stdin);
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);
	int a, b, c;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			graph[i][j] = 1000000;
			if (i == j) graph[i][j] = 0;
		}
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		graph[a][b] = graph[b][a] = c;
	}

	int start = 1;
	int dist[1001];
	int value = 0;
	for (int i = 1; i <= n; i++) dist[i] = graph[1][i];
	dist[1] = -1;
	int minindex = 1;
	for (int i = 1; i < n; i++) {
		int minimum = 10002;
		for (int j = 1; j <= n; j++) {
			if (dist[j] != -1) {
				if (minimum > dist[j]) {
					minimum = dist[j];
					minindex = j;
				}
			}
		}
		value += minimum;
		dist[minindex] = -1;
		for (int j = 1; j <= n; j++) {
			if (dist[j] > graph[minindex][j]) dist[j] = graph[minindex][j];
		}
	}
	printf("%d\n", value);
	return 0;
}