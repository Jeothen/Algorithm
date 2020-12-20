#include <iostream>
using namespace std;

const int N = 20;
const int K = 100;

void counting_sort(int* arr)
{
	int count[K + 1];
	int output[N];
	
	memset(count,0,sizeof(count));
	memset(output,0,sizeof(output));

	// register count
	for (int i=0; i<N; i++) {
		++count[arr[i]];
	}

	// presum - to find index
	for (int i=2; i<=K; i++){  // count start from 1, not 0
		count[i] += count[i-1];  
	}

	// sorting
	for (int i=0; arr[i]; i++) { // if not consisted by 0
		output[count[arr[i]]-1] = arr[i]; // count start from 1, but index start from 0
		--count[arr[i]];  // register one value, minus 1 index
	}

	
	for (int i=0; arr[i ]; i++){
		cout << output[i] << " ";
	}
	cout << endl;
}

int main(void) {
	int data[N] = { 5,3,4,5,3,4,1,5,4,1 };

	counting_sort(data);


	return 0;
}