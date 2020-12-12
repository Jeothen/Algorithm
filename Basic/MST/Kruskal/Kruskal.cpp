#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define nodecount 1001
int n, m;

struct node {
	int s, e, val;
};
vector <node> vc[nodecount];
priority_queue<node,vector<node>,greater<node>> pq;

int parent[nodecount];
int start, cnt, edgecount;

int find(int a) {
	if (parent[a] == a) return a;
	return find(parent[a]);
}

int kruskal() {

	for (int i=0; i<edgecount; i++) {
		node e;
		pq.push(e);
	}

	int ret = 0;
	while (!pq.empty()) {
		int value = pq.top().val, src = pq.top().s, tgt = pq.top().e;
		pq.pop();
		int p1 = find(src), p2 = find(tgt);
		if (p1 != p2) {
			// union
			ret += value;
			cnt++;
			parent[p1] = p2;
		}
		if (cnt == n) {
			cout << "cycle" << endl;
			return -1;
		}
	}
	if (cnt != nodecount-1) {
		cout << "all node not connected" << endl;
		return -2;
	}
	return ret;
}