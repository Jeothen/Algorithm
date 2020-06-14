#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;
const int N = 1'000'000;

bool isPrime[N+1];

void make_prime() {
	for (int i = 2; i <= 1000; i++) {
		if (!isPrime[i]) continue;
		for (int j = i * i; j <= N; j+= i) {
			isPrime[j] = false;
		}
	}
}

struct node{
	int x, y;
};

node ispossible(int val) {
	int tmp;
	for (int i = 3; i <= N; i++) {
		tmp = val - i;
		if (isPrime[tmp] && isPrime[i]) return { i,tmp };
	}
	return { 0,0 };
}

int main() {
	freopen("6588.txt", "r", stdin);
	int tmp; scanf("%d", &tmp);
	memset(isPrime, true, sizeof(isPrime));
	make_prime();
	while (tmp) {
		node ans = ispossible(tmp);
		if (ans.x != 0 && ans.y != 0) printf("%d = %d + %d\n", tmp, ans.x, ans.y);
		else printf("Goldbach's conjecture is wrong.\n");
		scanf("%d", &tmp);
	}
}