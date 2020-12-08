#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#pragma warning(disable:4996)

int main() {
	freopen("2960.txt", "r", stdin);
	int n, k;
	cin >> n >> k;
	vector <bool> isPrime(n+1, true);
	int answer = 0;
	for (int i = 2; i <= n; i++) {
		if (!isPrime[i]) continue;
		k--;
		if (k == 0) { answer = i; break; }
		for (int j = i*i; j <= n; j += i) {
			if (isPrime[j]) {
				isPrime[j] = false;
				k--;
				if (k == 0) { answer = j; break;}
			}
		}
		if (k < 0)break;
	}
	cout << answer << endl;
}