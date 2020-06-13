#include <iostream>
using namespace std;
const int N = 1'048'576;
#pragma warning(disable:4996)

int seg[2*N];

void update(const int& idx, const int& cnt) {
	int index = N + idx;
	seg[index] += cnt;
	if (seg[index] < 0) seg[index] = 0;
	while (index) {
		index /= 2;
		seg[index] = seg[2*index] + seg[2 * index + 1];
	}
}

int get_flavor(const int& val, const int& node) { // 1°³
	if (N <= node && node < 2 * N) return node-N+1;
	if (seg[2 * node] < val) return get_flavor(val - seg[2 * node], 2 * node + 1);
	else return get_flavor(val, 2 * node);
}


int main() {
	freopen("input.txt", "r", stdin);
	int n, a, b, c;	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		if (a == 1) { // »çÅÁÀ» ²¨³»´Â °æ¿ì
			scanf("%d", &b); // »çÅÁ ¼øÀ§
			int ans = get_flavor(b, 1);
			printf("%d\n",ans);
			update(ans-1, -1);
		}
		else { // »çÅÁÀ» ³Ö´Â °æ¿ì
			scanf("%d %d", &b, &c); // ¸À, °¹¼ö
			update(b - 1, c);
		}
	}
}#include <iostream>
using namespace std;
const int N = 1'048'576;
#pragma warning(disable:4996)

int seg[2*N];

void update(const int& idx, const int& cnt) {
	int index = N + idx;
	seg[index] += cnt;
	if (seg[index] < 0) seg[index] = 0;
	while (index) {
		index /= 2;
		seg[index] = seg[2*index] + seg[2 * index + 1];
	}
}

int get_flavor(const int& val, const int& node) { // 1°³
	if (N <= node && node < 2 * N) return node-N+1;
	if (seg[2 * node] < val) return get_flavor(val - seg[2 * node], 2 * node + 1);
	else return get_flavor(val, 2 * node);
}


int main() {
	freopen("input.txt", "r", stdin);
	int n, a, b, c;	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		if (a == 1) { // »çÅÁÀ» ²¨³»´Â °æ¿ì
			scanf("%d", &b); // »çÅÁ ¼øÀ§
			int ans = get_flavor(b, 1);
			printf("%d\n",ans);
			update(ans-1, -1);
		}
		else { // »çÅÁÀ» ³Ö´Â °æ¿ì
			scanf("%d %d", &b, &c); // ¸À, °¹¼ö
			update(b - 1, c);
		}
	}
}