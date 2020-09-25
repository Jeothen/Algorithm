#include <iostream>
using namespace std;
#define node 10001

int parent[node];
int nodesize[node];  // ��������� �� �ʿ��� ���� �ƴ�����, �θ� ����� ������ ������ ������

int find(int u)
{
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

void unionn(int a, int b) {
	int pa = find(a);
	int pb = find(b);
	if (pa == pb) return;
	if (nodesize[pa] > nodesize[pb]) swap(pa, pb); 
	parent[pa] = pb;
	nodesize[pb]++;
	return;
}

int main() {
	for (int i = 0; i < node; i++) {
		parent[i] = i;
		nodesize[i] = 1;
	}

}