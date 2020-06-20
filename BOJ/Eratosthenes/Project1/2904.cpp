#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#pragma warning(disable:4996)
const int N = 1'000'001;

short int isPrime[N];
vector <int> primes;

void make_prime() {
	for (int i = 2; i <= 1000; i++) {
		if (isPrime[i]) continue;
		for (int j = i * i; j <= N; j+= i) isPrime[j] = 1;
	}
	for (int i = 2; i <= N; i++) { // 소수 update
		if (isPrime[i] == 0) primes.push_back(i);
	}
	memset(isPrime, 0, sizeof(isPrime));
}

struct node {
	int val;
	int cnt;
};

vector <node> vc[101];

void get_prime(const int& index, int tmp) {
	int idx = 0, cnt = 0;
	while (tmp != 1) {
		cnt = 0;
		while (tmp % primes[idx] == 0) {
			tmp /= primes[idx];
			cnt++;
		}
		if (cnt) {
			vc[index].push_back({ primes[idx],cnt });
			isPrime[primes[idx]] += cnt;
		}
		idx++;
	}
}

int main() {
	freopen("2904.txt", "r", stdin);
	int tmp, n; scanf("%d", &n);
	make_prime();
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		get_prime(i,tmp);
	}
	// 소인수분해 된 것의 합을 계산  - 합이 n 이상인 경우 등록
	vector <node> dividelist;
	for (int i = 2; i <= N; i++) if (isPrime[i] / n >= 1) dividelist.push_back({ i, isPrime[i]/n });

	int ansval = 1;
	int anscnt = 0;
	for (int i = 0; i < dividelist.size(); i++) {
		int iter = dividelist[i].cnt;
		while (iter--) ansval *= dividelist[i].val;
		for (int j = 0; j < n; j++) {
			bool chk = false;
			for (int k = 0; k < vc[j].size(); k++) {
				if (vc[j][k].val == dividelist[i].val) {
					chk = true; // 인수가 있는 경우
					if (dividelist[i].cnt > vc[j][k].cnt) { // 넣을때만 계산
						int diff = dividelist[i].cnt - vc[j][k].cnt;
						anscnt += diff;
						break;
					}
				}
			}
			if (!chk) anscnt += dividelist[i].cnt; // 인수가 없는 경우
		}
	}
	cout << ansval << " " << anscnt << endl;
	
}