#include <stdio.h>
#pragma warning(disable:4996)

#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))

char lists[17];
int n, cnt, arr[17][17], dp[17][1 << 16];
int visit(int cur, int visited) {
	// 0번부터 시작
	printf("1\n");
	for (int i = 0; i < n; i++) {
		printf("visited 1<< %d = %d\n", i, visited&(1 << i));
	}
	int &ret = dp[cur][visited];
	if (ret != -1) {
		return ret;
	}
	if (visited == (1 << n) - 1) {
		printf("arr[cur][0] = %d\n", arr[cur][0]);
		return arr[cur][0] ? arr[cur][0] : 0x7777fff;
	}
	ret = 0x8888fff;
	printf("cur = %d\n", cur);
	for (int i = 0; i < n; i++) {
		printf("avisited 1 <<%d = %d\n", i, visited & (1 << i));
		printf("i = %d\n", i);
		if (visited & (1 << i)) continue;
		printf("arr[%d][%d] = %d\n", cur, i, arr[cur][i]);
		if (arr[cur][i] == 0) continue;
		printf("2\n");
		printf("i = %d\n", i);
		ret = MIN(ret, visit(i, visited | (1 << i)) + arr[cur][i]);
		printf("ret = %d\n", ret);
	}
	printf("forend\n");
	return ret;
}


int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) scanf("%d", &arr[i][j]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 1 << 16; j++) dp[i][j] = -1;
	}
	printf("%d\n", visit(0, 1));
}