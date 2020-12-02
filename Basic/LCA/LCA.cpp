#include <vector>
#include <iostream>
#define MAX 18 // 2^17 > 100000 (안전하게 +  1)
#define N 100001
using namespace std;

int n, m, d;
int depth[N];
int parent[N][MAX];

vector <int> vc[N];

void dfs(int now, int cnt) {
	depth[now] = cnt++;
	// now의 2^i번째 조상 = (now의 2^(i-1)번째 조상의 2^(i-1)번째의 조상
	for (int i = 1; i <= d; i++) {
		parent[now][i] = parent[parent[now][i - 1]][i - 1];
	}
	for (int i = 0; i < vc[now].size(); i++) {
		int next = vc[now][i];
		if (!depth[next]) {
			parent[next][0] = now;
			dfs(next, cnt);
		}
	}
}

int main() {
	scanf("%d", &n);
	for (d = 1; (1 << d) <= n; d++); // 최대깊이
	for (int i = 1; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		// 양방향 그래프
		vc[a].push_back(b);
		vc[b].push_back(a);
	}
	dfs(1, 1);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (depth[a] < depth[b]) swap(a, b); // 기준을 잡음(여기서는 a가 더 깊은 위치)
		// 깊이를 같게 맞춤
		for (int j = d; j >= 0; j--) { // 최대깊이 d부터 0까지
			if (depth[b] <= depth[parent[a][j]]) { // 깊이가 같으면 한칸 올려서 끝
				a = parent[a][j]; // a가 더 깊은 위치에 있으므로 하나씩 올라감
			}
		}
		if (a == b) {
			printf("%d\n", a);
			continue;
		}
		for (int j = d; j >= 0; j--) {
			if (parent[a][j] != parent[b][j]) {
				a = parent[a][j];
				b = parent[b][j];
			}
		}
		a = parent[a][0];
		printf("%d\n", a);
	}
}