#include <iostream>
#include <cstring>
#include <cmath>
#pragma warning(disable:4996)
#define segsize 262144-1

const int N = 123456;
using namespace std;

int seg[2 * segsize];
bool notPrime[2 * N+1];

void make_eratosthenes() {
	int sq = static_cast<int>(sqrt(2 * N));
	for (int i = 2; i <= sq; i++) {
		if (!notPrime[i]) continue;
		for (int j = i * i; j <= 2*N; j+= i) {
			notPrime[j] = false;
		}
	}
}

void init() {
	memset(notPrime, true, sizeof(notPrime));
	make_eratosthenes();
}

void update(const int& idx, const int& val) {
	int index = segsize + idx;
	seg[index] = val;
	while (index) {
		index /= 2;
		seg[index] = seg[2 * index] + seg[2 * index + 1];
	}
}

int sum_query(const int& L, const int& R, const int& node, const int& leftnode, const int& rightnode) {
	if (L > rightnode || R < leftnode) return 0;
	if (L <= leftnode && rightnode <= R) return seg[node];
	int mid = (leftnode + rightnode) >> 1;
	return sum_query(L, R, 2 * node, leftnode, mid) + sum_query(L, R, 2 * node + 1, mid + 1, rightnode);
}

int main() {
	freopen("4948.txt", "r", stdin);
	init();
	for (int i = 1; i <= 2 * N; i++) update(i, notPrime[i]);
	int tmp; scanf("%d", &tmp);
	while (tmp) {
		printf("%d\n", sum_query(tmp+1, 2 * tmp, 1, 1, segsize));
		scanf("%d", &tmp);
	}
}
