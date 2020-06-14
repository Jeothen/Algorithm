#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#pragma warning(disable:4996)
using namespace std;
const int N = 1300000;

bool isPrime[N+1];
short int chk[N + 1];
short int ans[N + 1];

void eratosthenes() {
	int sq_idx = static_cast<int>(sqrt(N));
	for (int i = 4; i <= N; i += 2) isPrime[i] = false; // 2의 배수 미리 처리
	for (int i = 2; i <= sq_idx; i++) {
		if (!isPrime[i]) continue;
		for (int j = i * i; j <= N; j += 2*i) {
			isPrime[j] = false;
		}
	}
}

void set_chk() {
	int preidx = 3; chk[2] = 0;
	for (int i = 3; i <= N; i++) {
		if (isPrime[i]) {
			chk[preidx] = i - preidx;
			preidx = i;
		}
	}
	int value = 0;
	for (int i = 3; i <= N; i++) {
		if (chk[i]) value = chk[i];
		else ans[i] = value;
	}
}

int main() {
	freopen("3896.txt", "r", stdin);
	int val, n; scanf("%d", &n);
	memset(isPrime, true, sizeof(isPrime));
	memset(chk, 0, sizeof(chk));
	memset(ans, 0, sizeof(ans));
	eratosthenes();
	set_chk();
	for (int i = 0; i < n; i++) {
		scanf("%d", &val);
		printf("%d\n", ans[val]);
	}
}