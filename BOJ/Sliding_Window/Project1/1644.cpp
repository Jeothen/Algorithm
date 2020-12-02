#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int N = 4000000;

bool IsPrime[N];

void make_prime(const int& n) {
	for (int i = 2; i <= sqrt(n) + 1; i++) {
		if (IsPrime[i]) continue;
		for (int j = i * i; j <= n; j+=i) {
			IsPrime[j] = true;
		}
	}
}

vector <int> prime;

int main() {
	freopen("1644.txt", "r", stdin);
	int n; scanf("%d", &n);
	make_prime(n);
	int sum = 0, ans = 0;
	int start= 0, end = 0;
	for (int i = 2; i <= n; i++) {
		if (!IsPrime[i]) prime.push_back(i);
	}
	while (start <= end) {
		if (sum == n) ans++;
		if (sum >= n) sum -= prime[start++];
		else if (end == prime.size()) break;
		else sum += prime[end++];
	}
	cout << ans << endl;
}

