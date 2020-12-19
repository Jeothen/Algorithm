#include <iostream>
#pragma warning(disable:4996)

void merge(int *arr, int start, int mid, int end) {
	int left = start, right = mid + 1;
	int idx = start;
	int temp[10];
	while (left <= mid && right <= end) {
		if (arr[left] <= arr[right]) temp[idx++] = arr[left++];
		else if (arr[left] >= arr[right]) temp[idx++] = arr[right++];
	}
	if (left > mid) {
		while (right <= end) temp[idx++] = arr[right++];
	}
	else {
		while (left <= mid) temp[idx++] = arr[left++];
	}
	for (int i = start; i <= end; i++) arr[i] = temp[i];
}

void merge2(int* arr, int start, int mid, int end){
	int left = start, right = mid + 1;
	int idx = start;
	int tmp[10];
	while (left <= mid || right <= end)
	{
		if (right > end || (left <= mid && arr[left] < arr[right]))
			tmp[idx++] = arr[left++];
		else
			tmp[idx++] = arr[right++];
	}
	for (int i = start; i <= end; i++) arr[i] = tmp[i];
}

void merge_sort(int *arr, int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		merge_sort(arr, left, mid);
		merge_sort(arr, mid + 1, right);
		// using only one function merge2 -> source code
		merge2(arr, left, mid, right);
	}
}


int cmp(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int main() {
	int arr[9] = {2, 4, 7, 1, 2, 10, 2, 2, 5};
	int arr2[9] = {2, 4, 7, 1, 2, 10, 2, 2, 5};
	
	mergesort(arr2,9,sizeof(int),cmp);
	for (int i = 0; i < 9; i++)
		printf("%d ", arr2[i]);
	printf("\n");


	merge_sort(arr, 0, 8);
	for (int i = 0; i < 9; i++)
		printf("%d ", arr[i]);
}
