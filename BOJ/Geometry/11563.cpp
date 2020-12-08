#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double min(double a, double b) { if (a > b) return b; else return a; }

struct node {
	double xs, ys, xe, ye;
};
vector <node> vc;

double dist(const double& x, const double& y) {
	return sqrt(pow(x, 2) + pow(y, 2));
}

double dot(const double& x1, const double& y1, const double& x2, const double& y2) {
	return x1 * x2 + y1 * y2;
}

double cross(const double& x1, const double& y1, const double& x2, const double& y2) {
	return abs(x1 * y2 - y1 * x2);
}

double H(const double& x, const double& y, const node& val) {
	double dot1 = dot(x - val.xs, y - val.ys, val.xe - val.xs, val.ye - val.ys);
	double dot2 = dot(x - val.xe, y - val.ye, val.xs - val.xe, val.ys - val.ye);
	if (dot1 * dot2 > 0) return cross(x - val.xs, y - val.ys, val.xe - val.xs, val.ye - val.ys) / dist(val.xe - val.xs, val.ye - val.ys);
	return 0;
}

double mindist(const int& idx, const node& val) {
	// 꼭지점 간 거리
	double tmpminimum = dist(vc[idx].xs - val.xs,vc[idx].ys-val.ys);
	tmpminimum = min(tmpminimum, dist(vc[idx].xs - val.xe, vc[idx].ys - val.ye));
	tmpminimum = min(tmpminimum, dist(vc[idx].xe - val.xs, vc[idx].ye - val.ys));
	tmpminimum = min(tmpminimum, dist(vc[idx].xe - val.xe, vc[idx].ye - val.ye));
	// 수선의 발
	if (H(vc[idx].xs, vc[idx].ys, val)) tmpminimum = min(tmpminimum, H(vc[idx].xs, vc[idx].ys, val));
	if (H(vc[idx].xe, vc[idx].ye, val)) tmpminimum = min(tmpminimum, H(vc[idx].xe, vc[idx].ye, val));
	if (H(val.xs, val.ys, vc[idx])) tmpminimum = min(tmpminimum, H(val.xs, val.ys, vc[idx]));
	if (H(val.xe, val.ye, vc[idx])) tmpminimum = min(tmpminimum, H(val.xe, val.ye, vc[idx]));
	return tmpminimum;
}

int main() {
	freopen("11563.txt", "r", stdin);
	int n, m; scanf("%d %d", &n, &m);
	node tmp;
	for (int i = 0; i < n; i++) {
		scanf("%lf %lf %lf %lf", &tmp.xs, &tmp.ys, &tmp.xe, &tmp.ye);
		vc.push_back(tmp);
	}
	double minimum = 0x8777f;
	for (int i = 0; i < m; i++) {
		scanf("%lf %lf %lf %lf", &tmp.xs, &tmp.ys, &tmp.xe, &tmp.ye);
		for (int j = 0; j < n; j++) {
			minimum = min(minimum, mindist(j, tmp));
		}
	}
	printf("%.16lf", minimum);
}