#include <iostream>
#include <string>
#include <vector>

using namespace std;

int * getPi(string p) {
	int len_p = (int)p.size();
	int * pi = new int[len_p];
	pi[0] = 0;
	int j = 0;
	for (int i = 1; i < (int)p.size(); i++) {
		while (p[i] != p[j]) {
			if (j == 0) {
				pi[i] = j;
				break;
			}
			j = pi[j - 1];
		}
		if (p[i] == p[j])
			pi[i] = ++j;
	}
	return pi;
}

vector<int> kmp(string t, string p, int * pi) {
	vector<int> v;
	int j = 0, len_p = (int)p.size(), len_t = (int)t.size();
	for (int i = 0; i < len_t; i++) {
		while (t[i] != p[j]) {
			if (j == 0)
				break;
			j = pi[j - 1];
		}
		if (t[i] == p[j]) {
			j++;
			if (j == len_p) {
				v.push_back(i - len_p + 2);
				j = pi[j - 1];
			}
		}
	}
	return v;
}

int main(void) {

	string text;
	string pattern;
	vector<int> v;

	getline(cin, text);
	getline(cin, pattern);

	int * pi = getPi(pattern);

	v = kmp(text, pattern, pi);

	cout << (int)v.size() << endl;
	for (vector<int>::size_type i = 0; i < v.size(); i++)
		cout << v[i] << " ";

	return 0;
}