#include <iostream>
#include <cmath>
using namespace std;

const int N = 10000;
bool chk[N + 1];

void make_selfnum() {
	for (int i = 1; i <= N; i++) {
		int tmp = i, sum = i;
		while (tmp) {
			sum += (tmp % 10);
			tmp /= 10;
		}
		chk[sum] = true;
 	}
}

int main() {
	make_selfnum();
	for (int i = 1; i <= N; i++) if (!chk[i]) printf("%d\n", i);
}