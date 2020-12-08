#include <stdio.h>


int cross(const int& x1, const int& y1, const int& x2, const int& y2) {
	return x1 * y2 - x2 * y1;
}

int main() {
	freopen("11758.txt", "r", stdin);
	int x1, y1, x2, y2, x3, y3;
	scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
	int ans = cross(x2 - x1, y2 - y1, x3 - x1, y3 - y1);
	if (ans > 0) printf("%d",1);
	else if (ans < 0) printf("%d",-1);
	else printf("0");
}