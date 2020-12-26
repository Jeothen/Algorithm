#include <iostream>
#include <string>
#include <vector>

using namespace std;
// create fail function
int * getPi(string pattern) {
	int len_pattern = (int)pattern.size();
	int * p = new int[len_pattern];
	p[0] = 0;
	int j = 0; // check index
	for (int i = 1; i < len_pattern; i++) {
		while (pattern[i] != pattern[j]) {
			if (j == 0) { // up to j == 0, not occured pattern[i] == pattern[j],  p[i] = 0
				p[i] = 0;
				break;
			}
			j = p[j - 1];  // It's same up to j-1
		}
		if (pattern[i] == pattern[j]) p[i] = ++j; // j += 1, and then p[i] += 1
	}
	return p;
}

vector<int> kmp(string text, string pattern) {
	int *p = getPi(pattern);
	vector<int> v;
	int j = 0, len_p = (int)pattern.size(), len_t = (int)text.size();
	for (int i = 0; i < len_t; i++) {
		while (text[i] != pattern[j]) {  // continuously find same value into fail function up to j == 0
			if (j == 0) break;
			j = p[j - 1];
		}
		if (text[i] == pattern[j]) {
			j++;
			if (j == len_p) { // j start from 0
				v.push_back(i - len_p + 2); // start index
				j = p[j - 1];  //  fail function
			}
		}
	}
	return v;
}