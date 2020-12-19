#include <iostream>
#include <algorithm>
using namespace std;

void quicksort(int *arr, int start, int end) {
	int left = start;
	int right = end;
	int pivot = arr[(left + right) / 2];
	while (left < right)
	{
		while (arr[left] < pivot) left++;
		while (arr[right] > pivot) right--;
		if (left <= right) {
			swap(arr[left], arr[right]);
			++left;
			--right;
		}
	}
	if (start < right) quicksort(arr, start, right);
	if (left < end) quicksort(arr, left, end);
}


int cmp(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int cmp2(const void *a, const void *b)
{
	if ((char *)a < (char *)b)
		return -1;
	else if ((char *)a > (char *)b)
		return 1;
	else return 0;

//	return strcmp((char*)a,(char*)b);
}

int main(){
	int arr[] = {2, 1, 7, 13, 5, 1, 242, 63, 11, 2};
	int arr2[] = {2, 1, 7, 13, 5, 1, 242, 63, 11, 2};
	qsort(arr2, 10, sizeof(int), cmp);
	for (int i = 0; i < 10; i++)
	{
		cout << arr2[i] << " ";
	}
	cout << endl;

	const int N = 9;
	char arr3[N][10] = {"aa", "Ab", "Bc", "ss", "es", "ds", "cas", "ca", "csa"};
	heapsort(arr3, N, sizeof(arr3[0]), cmp2);
	for (int i = 0; i < N; i++)
	{
		cout << arr3[i] << " ";
	}
	cout << endl;



	quicksort(arr,0,10-1);
	for (int i=0; i<10; i++){
		cout << arr[i] << " ";
	}	
}