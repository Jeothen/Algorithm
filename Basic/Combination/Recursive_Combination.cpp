#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int data[10];
int t1[10], t2[10];
int n;
int count1, count2;

void repeat_combination1(int n, int k, int q)
{
	if (k == 0)
	{ // Picked all n
		count1++;
		for (int i = 0; i < q; i++)
			printf("%d ", t1[i]);
		printf("\n");
	}
	else if (n == 0) return;
	else
	{
		t1[k - 1] = data[n - 1];
		// have to pick one out of n so parameter is n-1
		repeat_combination1(n, k - 1, q); 	  // if data[n-1] is picked and data[n] can be repeated, so next is k-1
		repeat_combination1(n - 1, k, q);	  // if data[n-1] is not picked, so next is k
	}
}

void repeat_combination2(int n, int q, int k, int start)
{
	if (k == q)
	{ // k is filled to q
		count2++;
		for (int i = 0; i < q; i++)
			printf("%d ", t2[i]);
		cout << endl;
		return;
	}
	for (int i = start; i < n; i++)  
	{
		t2[k] = data[i];
		repeat_combination2(n, q, k+1, i); // insert t2[next_index]  by data[index] : index start from next_index
	}
}

int main()
{
	n = 7;
	count1 = 0, count2 = 0;
	for (int i = 0; i < n; i++)
	{
		data[i] = i + 1;
	}
	// nC3
	repeat_combination1(n, 3, 3);
	repeat_combination2(n, 3, 0, 0);
	printf("%d %d\n", count1, count2);
}
