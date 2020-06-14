#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
#pragma warning(disable:4996)

const int N = 1000;
bool isPrime[N+1];

void make_eratosthenes() {
	// 2의 배수 우선 체크 - 홀수 + 홀수*2 만 검사
	for (int i = 4; i <= N; i += 2) isPrime[i] = false;
	int sq = sqrt(N);
	for (int i = 2; i <= sq; i++) {	
		if (!isPrime[i]) continue;
		for (int j = i * i; j <= N; j += i*2) {
			isPrime[j] = false;
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	memset(isPrime, true, sizeof(isPrime));
	
	isPrime[1] = false;
	make_eratosthenes();
	int res = 0;
	int n, val; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &val);
		if (isPrime[val]) res++;
	}
	cout << res << endl;
}