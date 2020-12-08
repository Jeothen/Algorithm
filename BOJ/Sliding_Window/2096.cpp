#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	freopen("2096.txt", "r", stdin);
	int n; scanf("%d", &n);
	int a1, b1, c1, a2, b2, c2; // min, max;
	int ta1, tb1, tc1, ta2, tb2, tc2;
	int a, b, c;	
	scanf("%d %d %d", &a1, &b1, &c1);
	a2 = a1, b2 = b1, c2 = c1;
	for (int i = 0; i < n-1; i++) {
		scanf("%d %d %d", &a, &b, &c);
		ta1 = min(a + a1, a + b1);
		tb1 = min(min(b + a1, b + b1), b + c1);
		tc1 = min(c + b1, c + c1);
		ta2 = max(a + a2, a + b2);
		tb2 = max(max(b + a2, b + b2), b + c2);
		tc2 = max(c + b2, c + c2);
		a1 = ta1, b1 = tb1, c1 = tc1, a2 = ta2, b2 = tb2, c2 = tc2;
	}
	printf("%d %d\n", max(max(a2, b2), c2), min(min(a1, b1), c1));
}