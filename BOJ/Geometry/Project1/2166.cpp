#include <stdio.h>
using namespace std;
typedef long long ll;

struct node {
	ll x; ll y;
};

int main() {
	freopen("2166.txt", "r", stdin);
	int n; scanf("%d", &n);
	ll x0,y0, x1, y1,x2,y2;
	scanf("%lld %lld", &x1, &y1);
	x0 = x1; y0 = y1;
	double answer = 0;
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &x2, &y2);
		answer += (x1*y2 - x2 * y1);
		x1 = x2; y1 = y2;
	}
	answer += (x2*y0 - y2 * x0);
	if (answer < 0) answer *= -1;  answer /= 2.0;
	printf("%.1lf", answer);
}