#include <iostream>
#include <algorithm>
using namespace std;

struct p {
	int x, y;
};

int ccw(p a, p b, p c) {
	int s = (c.y - a.y)*(b.x - a.x) - (b.y - a.y)*(c.x - a.x);
	if (s < 0) return -1; // cw
	if (s == 0) return 0;  // paraller
	return 1; // ccw
}

bool isintersect(p a, p b, p c, p d) {
	if (ccw(a, b, d) == ccw(a, b, c)) return false;
	if (ccw(c, d, a) == ccw(c, d, b)) return false;
	return true;
}

bool chkdot(p p1, p p2, p r) {
	if ((p2.y - p1.y)*(r.x - p1.x) == (r.y - p1.y)*(p2.x - p1.x)) return true;
	return false;
}

int main() {
	freopen("10255.txt", "r", stdin);
	p p1, p2, r1, r2;
	int te; scanf("%d", &te); while (te--) {
		scanf("%d %d %d %d", &r1.x, &r1.y, &r2.x, &r2.y);
		scanf("%d %d %d %d", &p1.x, &p1.y, &p2.x, &p2.y);
		bool chk = false;
		if (p1.y == p2.y) { // x 평행
			chk = true;
			if (p1.x > p2.x) swap(p1.x, p2.x);
			if (p1.y == r1.y || p1.y == r2.y) {
				if (p2.x == r1.x || p1.x == r2.x) printf("1\n");
				else if ((r1.x <= p1.x && p1.x < r2.x) || (r1.x < p2.x && p2.x <= r2.x)) printf("4\n");
				else if ((p1.x <= r1.x && r2.x <= p2.x)) printf("4\n");
				else printf("0\n");
			}
			else if (r1.y < p1.y && p1.y < r2.y) {
				if (p1.x <= r1.x && r2.x <= p2.x) printf("2\n");
				else if (r1.x < p1.x && p2.x < r2.x) printf("0\n");
				else if (r1.x > p2.x || r2.x < p1.x) printf("0\n");
				else printf("1\n");
			}
			else printf("0\n");
		}
		else if (p1.x == p2.x) { // y축 평행
			if (p1.y > p2.y) swap(p1.y, p2.y);
			if (p1.x == r1.x || p1.x == r2.x) {
				if (p2.y == r1.y || p1.y == r2.y) printf("1\n");
				else if ((r1.y <= p1.y && p1.y < r2.y) || (r1.y < p2.y && p2.y <= r2.y)) printf("4\n");
				else if ((p1.y <= r1.y && r2.y <= p2.y)) printf("4\n");
				else printf("0\n");
			}
			else if (r1.x < p1.x && p1.x < r2.x) {
				if (p1.y <= r1.y && r2.y <= p2.y) printf("2\n");
				else if (r1.y < p1.y && p2.y < r2.y) printf("0\n");
				else if (r1.y > p2.y || r2.y < p1.y) printf("0\n");
				else printf("1\n");
			}
			else printf("0\n");
		}
		else {
			int cnt = 0;
			if (isintersect(p1, p2, r1, { r1.x,r2.y })) { // 이미 범위를 포함함
				if (!chkdot(p1, p2, r1)) cnt++;
			}
			if (isintersect(p1, p2, r1, { r2.x,r1.y })) {
				if (!chkdot(p1, p2, { r2.x, r1.y })) cnt++;
			}
			if (isintersect(p1, p2, { r1.x,r2.y }, r2)) {
				if (!chkdot(p1, p2, { r1.x,r2.y })) cnt++;
			}
			if (isintersect(p1, p2,{ r2.x,r1.y }, r2)) {
				if (!chkdot(p1, p2, r2)) cnt++;
			}
			printf("%d\n", cnt);
		}
	}
}