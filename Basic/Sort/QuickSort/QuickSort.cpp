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

int main(){
	int arr[] = {2, 1, 7, 13, 5, 1, 242, 63, 11, 2};
	quicksort(arr,0,10-1);
	for (int i=0; i<10; i++){
		cout << arr[i] << " ";
	}	
}