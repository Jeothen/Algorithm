#include <iostream>
#include <algorithm>
using namespace std;


int* bubblesort(int arr[], int length) {
	for (int i=length-1; i > 0; i--){
		for (int j=0; j < i ; j++){
			if (arr[j+1] < arr[j]) swap(arr[j],arr[j+1]);
		}
	}
	return arr;
}

int main(){
	int arr[20] = {4,1,2,6,1,2,4,4,4,6};
	int* res;
	res = bubblesort(arr,10);
	for (int i=0; i<10; i++){
		cout << res[i] << " ";
	}
}