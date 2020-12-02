#include <iostream>
#include <algorithm>
using namespace std;


void swap(int* a, int* b){
	int* tmp = a;
	a = b; b = tmp;
}

void quicksort(int *arr, int start, int end) {
	int left = start;
	int right = end;
	int pivot = arr[(left + right) / 2];
	for (int i = 0; i < 9; i++) printf("%d ", arr[i]);
	printf("\n");
	printf("left = %d , pivot = %d, right = %d\n", left, pivot, right);
	while (left < right) {
		while (arr[left] < pivot) left++;
		while (arr[right] > pivot) right--;
		if (left <= right) {
			swap(&arr[left], &arr[right]);
			++left;
			--right;
		}
	}
	if (start < right) quicksort(arr, start, right);
	if (left < end) quicksort(arr, left, end);
}