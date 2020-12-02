#include <stdio.h>
#include <malloc.h>
#pragma warning(disable:4996)

#define max 200001

int n, namecount;

typedef struct node {
	node* next;
	int index;
	char* name;
}node;

node arr[max];

int idx = 0;


int hashcode(char* str) {
	int hash = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		hash = (hash * 7 + 5 * str[i]) % max;
	}
	return hash;
}

node* h[max];

int get(char* name) {
	int hash = hashcode(name);
	node* curr = h[hash];
	while (curr) {
		int issame = 1;
		for (int i = 0; i < 21; i++) {
			if (name[i] != curr->name[i]) {
				issame = 0;
				break;
			}
		}
		if (issame) return curr->index;
		curr = curr->next;
	}
}

node* createnode(char* name, int index) {
	node* newnode = &arr[idx++];
	newnode->name = name;
	newnode->index = index;
	return newnode;
}

void put(char* name, int index) {
	int hash = hashcode(name);
	node* ne = createnode(name, index);
	if (!h[hash]) h[hash] = ne;
	else {
		ne->next = h[hash];
		h[hash] = ne;
	}
}

int iscontain(char* name) {
	int hash = hashcode(name);
	if (!h[hash]) {
		return 0;
	}
	else {
		node* curr = h[hash];
		while (curr) {
			int issame = 1;
			for (int i = 0; i < 21; i++) {
				if (name[i] != curr->name[i]) {
					issame = 0;
					break;
				}
			}
			if (issame) return 1;
			curr = curr->next;
		}
		return 0;
	}
}

int parent[max];
int size[max];

int find(int c) {
	if (parent[c] == c) return c;
	return parent[c] = find(parent[c]);
}

int unite(int a, int b) {
	int pa = find(a);
	int pb = find(b);

	if (pa != pb) {
		parent[pb] = pa;
		size[pa] += size[pb];

	}
	return size[pa];
}


int main() {
	int te, count;
	scanf("%d", &te);
	for (int tc = 1; tc <= te; tc++) {
		count = 0;
		scanf("%d", &n);
		for (int i = 0; i < max; i++) {
			parent[i] = i;
			size[i] = 1;
		}
		for (int i = 0; i < n; i++) {
			char* a = (char*)malloc(sizeof(char) * 21);
			char* b = (char*)malloc(sizeof(char) * 21);
			scanf("%s %s", a, b);
			if (iscontain(a) == 0)
				put(a, namecount++);
			if (iscontain(b) == 0)
				put(b, namecount++);
			count = unite(get(a), get(b));
			printf("%d\n", count);
		}
	}
}
