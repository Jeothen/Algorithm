#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int N = 1'000'000;
#pragma warning(disable:4996)

vector <int> vc;

bool sanguen(int val) {
	bool chk[500] = { false, };
	while (1) {
		int idx = 1000000, num = 0, tmp;
		while (idx) { // 분해 및 제곱 계산
			tmp = (val / idx);
			val -= tmp * idx;
			num += tmp * tmp;
			idx /= 10;
		}
		val = num;
		if (chk[val] == true) return false;
		chk[val] = true;
		if (val == 1) return true;
	}
}

bool isPrime[N + 1];

void make_prime(const int& n) {
	for (int i = 2; i <= static_cast<int>(sqrt(n)); i++) {
		if (isPrime[i]) continue;
		for (int j = i * i; j <= n; j += i) {
			isPrime[j] = true;
		}
	}
	for (int i = 2; i <= n; i++) if (!isPrime[i]) vc.push_back(i);
}

int main() {
	freopen("9421.txt", "r", stdin);
	int n; scanf("%d", &n);
	make_prime(n);
	int idx = 0;
	while (1) {
		if (n < vc[idx]) break;
		if (sanguen(vc[idx])) printf("%d\n", vc[idx]);
		idx++;
		if (vc.size() == idx) break;
	}

}

