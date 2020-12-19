#include <iostream>
#include <algorithm>
using namespace std;

int cmp(const void* a, const void* b){
	return (*(char*)a - *(char*)b);
}

void heapify(int* arr, int idx, int heap_size){
	int tmp = idx;
	int left = 2*idx+1;
	int right = 2*idx +2;
	if (left < heap_size && arr[left] > arr[tmp]) tmp = left;  // max heap
	if (right < heap_size && arr[right] > arr[tmp]) tmp = right;
	if (tmp != idx) // if changed
	{
		swap(arr[tmp], arr[idx]);
		heapify(arr,tmp, heap_size);
	}
}

// down to up
void insert_node (int* h, int val, int heap_size) {
	int idx = heap_size; // insert last node
	h[idx] = val;
	while((idx != 0) && h[idx] > h[idx/2])  // max heap  /   value compare with parent node
	{
		swap(h[idx],h[idx/2]); // swap child with parent
		idx /= 2; // going parent node position
	}
}

// up to down

int delete_node(int* h, int heap_size){
	int res = h[0];
	h[0] = h[heap_size]; // last node to root
	heap_size--;
	int maxnode = 0;
	int current = 0; // start from root node
	int child = 0; // leftchild = child / rightchild = child + 1

	while (child <= heap_size) // If leftchild is smaller than heapsize 
	{
		if (h[maxnode] < h[child+1]) maxnode = child+1;  // leftchild is bigger than currnet
		if (child+2 <= heap_size && h[maxnode] < h[child+2]) maxnode = child+2; // maxnode vs rightchild
		if (maxnode == current) break; // parent is bigger than childs
		swap(h[maxnode], h[current]);
		current = maxnode;
		child = current*2;
	}
	return res;
}


int main(){
	char arr[9] = {'a','c','e','k','k','b','z','s','a'};
	heapsort(arr, 9 ,sizeof(char),cmp);
	for (int i=0; i<9 ; i++){
		cout << arr[i] << " ";
	}
	cout << endl;

	const int N = 11;
	int arr2[N] = {2, 4, 7, 1, 2, 10, 2, 2, 5,1, 3};
	// building heap
	for (int i= N/2; i >=0; i--){  // start from n/2 ... -> root
		heapify(arr2,i,N);
	}

	// array
	int heap_size = N;
	while(heap_size > 0) {
		swap(arr2[0], arr2[--heap_size]); // 0 -> last
		heapify(arr2, 0, heap_size);
	}
	for (int i=0; i<N; i++) cout << arr2[i] << " ";
	cout << endl;

	int arr3[N] = {2, 4, 7, 1, 2, 10, 2, 2, 5, 1, 3};
	int heap_size2 = 0;
	int heap[N] = {0,};
	for (int i=0; i<N; ++i){ // insert 
		insert_node(heap,arr3[i],heap_size2++);
	}
	for (int i=N-1; i>=0; i--){
		arr3[i] = delete_node(heap,heap_size2); 
	}
	for (int i=0; i<N; i++){
		cout << arr3[i] << " ";
	}
	cout << endl;
}