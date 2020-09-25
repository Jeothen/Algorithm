#include <stdio.h>
#pragma warning(disable:4996)

void merge(int *arr, int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = left;
	int temp[9];
	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) temp[k++] = arr[i++];
		else if (arr[i] >= arr[j]) temp[k++] = arr[j++];
	}
	if (i > mid) {
		while (j <= right) temp[k++] = arr[j++];
	}
	else {
		while (i <= mid) temp[k++] = arr[i++];
	}
	for (int m = left; m <= right; m++) arr[m] = temp[m];
}

void mergesort(int *arr, int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergesort(arr, left, mid);
		mergesort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}
int main() {
	int arr[9] = { 2,4,7,1,2,10,2,2,5 };
	mergesort(arr, 0, 8);
	for (int i = 0; i < 9; i++) printf("%d ", arr[i]);
}

/* 참고

#include <iostream>

int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
int tmp[10];

void mergeSort(int start, int end) {
	if (start < end) {
		int mid = (start + end) >> 1;

		mergeSort(start, mid);
		mergeSort(mid + 1, end);

		int left = start, right = mid + 1;
		int idx = start;

		while (left <= mid || right <= end) {
			if (right > end || (left <= mid && arr[left] < arr[right]))
				tmp[idx++] = arr[left++];
			else
				tmp[idx++] = arr[right++];
		}
		for (int i = start; i <= end; i++)
			arr[i] = tmp[i];
	}
}

void print(int a) {
	printf("%s\n", !a ? "전" : "후");
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
int main() {
	print(0);
	mergeSort(0, 10 - 1);
	print(1);
	return 0;
}
*/