
// Àç±Í

struct Trie {
	Trie* next[27];
	int cnt;

	Trie() {
		cnt = 0;
		for (int i = 0; i < 27; i++)
			next[i] = nullptr;
	}
	~Trie() {
		for (int i = 0; i < 27; i++) if (next[i]) delete next[i];
	}

	void insert(const char* key) {
		if (*key == '\0') return;

		int curr = *key - 'a';
		if (!next[curr]) next[curr] = new Trie();
		next[curr]->cnt++;
		next[curr]->insert(key + 1);
	}

	int check(const char* key, int chk, int press) {
		if (*key == '\0') return press;

		int curr = *key - 'a';
		if (chk != next[curr]->cnt)
			return next[curr]->check(key + 1, next[curr]->cnt, press + 1);
		else
			return next[curr]->check(key + 1, chk, press);
	}
};


// ¹Ýº¹¹®

#include <stdio.h>
#pragma warning(disable:4996)
#define MAX_E 1000000
struct Trie {
	Trie* next[127];
	int index;
	int count;

	Trie() {
		index = -1;
		count = 0;
		for (int i = 0; i < 127; i++)
			next[i] = 0;
	}
	~Trie() {
		for (int i = 0; i < 127; i++) if (next[i]) delete next[i];
	}
};

void insert(Trie* root, char key[], int inde) {
	Trie* node = root;
	int length;
	for (length = 0; key[length] != '\0'; length++);
	for (int i = 0; i < length; i++) {
		if (key[i] == ' ') continue;
		char ind = key[i];
		if (!node->next[ind]) {
			node->next[ind] = new Trie();
		}
		node = node->next[ind];
	}
	node->index = inde;
	node->count += 1;
}

