#include <iostream>
#include <vector>
using namespace std;


int data[10];
int t1[10], t2[10];
int n;
int count1, count2, count3;

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void permutation1(int n, int q, int k)
{ // q is just number of print count
	if (k == q) {
		count1++;
		for (int i = 0; i < q; i++) {
			printf("%d ", t1[i]);
		}
		printf("\n");
	}
	else {
		for (int i = k; i <n; i++) {
			swap(&t1[i], &t1[k]);  // order swap
			permutation1(n, q, k + 1);  // recursion // pick i, so next is k+1
			swap(&t1[i], &t1[k]);  // recover
		}
	}
}

// powerset
bool visited[10];
void permutation2(int n, int q, int k){

	if (k == q) {
		count2++;
		for (int i = 0; i < q; i++)
		{
			printf("%d ", t2[i]);
		}
		printf("\n");
	}
	for (int i=0; i < n ; i++){
		if (visited[i]) continue;
		else {
			visited[i] = true;
			t2[k] = data[i];
			permutation2(n,q,k+1);
			visited[i] = false;
		}
	}
}

void permutation3(int n, int k){
	vector<int> vc(n);
	for (int i=0; i<n; i++) vc[i] = data[i];
	sort(vc.begin(), vc.end());

	do
	{
		count3++;
		for (int i = 0; i < k; i++)
		{
			cout << vc[i] << " ";
		}
		cout << endl;
		reverse(vc.begin() +k, vc.end()); // stl library doesn't support nPr, so this line needed
	} while (next_permutation(vc.begin(), vc.end()));
}

int main() {
	n = 5;
	count1 = 0, count2 = 0, count3 = 0;
	for (int i = 0; i < n; i++) {
		data[i] = i + 1;
		t1[i] = data[i];
		t2[i] = 0;
	}
	permutation1(n, 3, 0);
	permutation2(n, 3, 0);
	permutation3(n,3);
	printf("%d %d %d\n", count1, count2, count3);
}
