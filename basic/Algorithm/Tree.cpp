#include <stdio.h>
#include <malloc.h>
#pragma warning(disable:4996)

typedef struct node {
	int index;
	int data;
	node *parent;
	node *child;
	node *sibling;
}node;

int cnt;
int find(node *r) {
	if (!r->child) cnt += 1;
	if (r->child) find(r->child);
	if (r->sibling) find(r->sibling);
	return cnt;
}

int main() {
	freopen("input.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	int rootindex;
	node *tree = (node *)malloc(sizeof(node)*n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tree[i].data);
		tree[i].index = i;
		tree[i].child = NULL;
		tree[i].sibling = NULL;
	}
	for (int i = 0; i < n; i++) {
		if (tree[i].data != -1) {
			tree[i].parent = &tree[tree[i].data];
			if (!tree[i].parent->child) {
				tree[i].parent->child = &tree[i];
				tree[i].sibling = NULL;
			}
			else {
				node *temp = (node *)malloc(sizeof(node));
				temp = tree[i].parent->child;
				if (temp->sibling) {
					while (1) {
						if (temp->sibling == NULL) break;
						temp = temp->sibling;
					}
				}
				temp->sibling = &tree[i];
			}
		}
		else rootindex = i;
	}
	int delnum;
	scanf("%d", &delnum);
	int ans;
	if (tree[delnum].data == -1) ans = 0;
	else {
		for (int i = 0; i < n; i++) {
			if (tree[i].sibling == &tree[delnum]) {
				tree[i].sibling = NULL;
			}
		}
		if (tree[delnum].sibling) {
			tree[delnum].parent->child = tree[delnum].sibling;
		}
		int start = rootindex;
		ans = find(&tree[start]);
	}
	printf("%d", ans);
}