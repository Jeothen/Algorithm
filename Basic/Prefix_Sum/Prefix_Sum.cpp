#include <iostream>
using namespace std;
const int N = 10001;
int psum[N];

void presum(){
	int n = 20;
	for (int i=0; i<n; i++){
		int val = 2; // scanf or cin
		psum[i+1] = psum[i] + val;  // psum[3] = summary betwwen 0 to 2
	}
	for (int i=1; i<=n; i++){
		cout << psum[n] - psum[i-1] << endl; 
		// i == 1, 0 to n
		// i == 2, 1 to n
		// i == n, n-1 to n
	}
}