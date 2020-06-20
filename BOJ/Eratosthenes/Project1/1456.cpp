#include <iostream>
#include <cmath>
using namespace std;
const int N = 10'000'000;
#pragma warning(disable:4996)

bool ischk[N + 1];

void make_prime(const int& n) {
	for (int i = 2; i <= static_cast<int>(sqrt(n)); i++) {
		if (ischk[i]) continue;
		for (int j = i * i; j <= n; j += i) ischk[j] = true;
	}
}

long long answer;

void get_ans(const int& n, long long a, long long b) {
	for (long long i = 2; i <= n; i++) {
		if (!ischk[i]) { // 소수일 때
			long long tmp = i * i;
			while (tmp <= b) {
				if (tmp >= a) answer++;
				tmp *= i;
				if (tmp % i) break; // 똥값인 경우 ERROR...
			}
		}
	}
}

int main() {
	freopen("1456.txt", "r", stdin);
	long long a, b; scanf("%lld %lld", &a, &b);
	answer = 0;
	int root = static_cast<int>(sqrt(b)); root++;
	make_prime(root);
	get_ans(root, a, b);
	printf("%lld\n", answer);
}