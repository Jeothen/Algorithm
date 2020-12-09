#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int data[10];
int t1[10], t2[10], t3[10];
int n;
int count1, count2, count3, count4;

void combination1(int n, int k, int q)
{
	if (k == 0) { // Picked all n
		count1++;
		for (int i = 0; i < q; i++) 
			printf("%d ", t1[i]);
		printf("\n");
	}
	else if (n < k) return;  // n >= k
	else {
		t1[k - 1] = data[n - 1];
        // have to pick one out of n so parameter is n-1
		combination1(n - 1, k - 1, q);  // if data[n-1] is picked, so next is k-1
		combination1(n - 1, k, q);      // if data[n-1] is not picked, so next is k
	}
}

void combination2(int n, int q, int k, int start)
{
	if (k == q) {  // k is filled to q
		count2++;
		for (int i = 0; i < q; i++)
			printf("%d ", t2[i]);
		cout << endl;
		return;
	}
	for (int i = start; i < n; i++) //  0 
	{
		t2[k] = data[i];
		combination2(n,q, k+1, i+1);  // insert t2[next_index]  by data[index] : index start from next_index
	}
}

bool visited[10];

void combination3(int n, int q, int k, int start)
{
	if (k == q){ // visited count is q
		count3++;
		for (int i =0; i<n; i++){
			if (visited[i]) cout << data[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i=start; i<n; i++){
		if (visited[i]) continue;
		else {
			visited[i] = true;  // visited check
			t3[k] = data[i];
			combination3(n,q,k+1,i+1);
			visited[i] = false;  // uncheck
		}
	}

}

void combination4(int n, int k) {
    vector <bool> chk(n);
	for (int i=0; i<k; i++){
		chk[i] = true;
	}
	do {
		for (int i=0; i<n; i++){
			if (chk[i]) cout << data[i] << " ";
		}
		count4++;
		cout << endl;
	} while(prev_permutation(chk.begin(),chk.end()));
}

int main() {
	n = 7;
	count1 = 0, count2 = 0, count3 =0, count4 = 0;
	for (int i = 0; i < n; i++) {
		data[i] = i + 1;
	}
    // nC3
	combination1(n, 3, 3);
	combination2(n, 3, 0, 0);
	memset(visited,0,sizeof(visited));
	combination3(n, 3,0, 0);
	combination4(n, 3);
	printf("%d %d %d %d\n", count1, count2, count3, count4);   
}
