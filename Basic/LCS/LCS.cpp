#include <iostream>
#include <string>
using namespace std;
#pragma warning(disable:4996)
#define max 5001
string a, b;
int table[max][max];

int main() {
	freopen("input.txt", "r", stdin);
	cin >> a;
	cin >> b;
	a = '0' + a;
	b = '0' + b;
	int len1, len2;
	len1 = a.length();
	len2 = b.length();
	for (int i = 0; i < len1; i++) {
		table[0][i] = 0;
	}
	int lcslen = 0;
	for (int i = 1; i < len2; i++) {
		table[i][0] = 0;
		int maxi = 0;
		for (int j = 1; j < len1; j++) {
			if (b[i] == a[j]) {
				maxi = table[i - 1][j - 1] + 1;
				table[i][j] = maxi;
			}
			else {
				if (table[i][j - 1] > table[i - 1][j])
					table[i][j] = table[i][j - 1];
				else
					table[i][j] = table[i - 1][j];
			}
		}
		lcslen = lcslen < maxi ? maxi : lcslen;
	}
	string LCS = "";
	int tmp = 1;
	for (int i = 1; i < len1; i++) {
		for (int j = tmp; j < len2; j++) {
			if (table[i][j] == tmp &&  table[i - 1][j] == tmp-1  && table[i][j - 1] == tmp-1 && table[i - 1][j - 1] == tmp-1) {
				LCS += a[i];
				tmp++;
				break;
			}
		}
	}
	cout << LCS << endl;
}