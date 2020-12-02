#include <stdio.h>

#define MAX_SIZE 100

typedef struct priority_queue {
	int heap[MAX_SIZE];
	int size;

	priority_queue() {
		size = 0;
	}

	void swap(int *a, int *b) {
		int tmp = *a;
		*a = *b;
		*b = tmp;
	}

	int push(int value) {
		if (size + 1 > MAX_SIZE) {
			return 0;
		}

		heap[size] = value;

		int current = size;
		int parent = (size - 1) / 2;

		while (current > 0 && heap[current] > heap[parent]) {
			swap(&heap[current], &heap[parent]);
			current = parent;
			parent = (parent - 1) / 2;
		}

		size++;

		return 1;
	}

	int pop() {
		if (size <= 0) return -1;

		int ret = heap[0];
		size--;

		heap[0] = heap[size];
		int current = 0;
		int leftChild = current * 2 + 1;
		int rightChild = current * 2 + 2;
		int maxNode = current;

		while (leftChild < size) {
			if (heap[maxNode] < heap[leftChild]) {
				maxNode = leftChild;
			}
			if (rightChild < size && heap[maxNode] < heap[rightChild]) {
				maxNode = rightChild;
			}

			if (maxNode == current) {
				break;
			}
			else {
				swap(&heap[current], &heap[maxNode]);
				current = maxNode;
				leftChild = current * 2 + 1;
				rightChild = current * 2 + 2;
			}
		}

		return ret;
	}

	int empty() {
		if (size == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
}priority_queue;


int main(int argc, char* argv[])
{
	int T, N;

	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++)
	{
		scanf("%d", &N);

		priority_queue pq;

		for (int i = 0; i < N; i++)
		{
			int value;
			scanf("%d", &value);
			pq.push(value);
		}

		printf("#%d\n", test_case);
		while (!pq.empty()) printf("%d ", pq.pop());

		printf("\n");
	}

	return 0;
}

// class library 사용

// 조건이 복잡할 땐 연산자 오버로딩을 통해 조건을 설정할 수 있다.
// int뿐만 아니라 struct를 통해 원하는 구조를 추가하면 됨
/*
#include <iostream>
#include <queue>
#include <string>
#include <tuple>
using namespace std;

typedef struct cmp {
	bool operator()(tuple <int, int, string> a, tuple<int, int, string> b) {
		if (get<0>(a) > get<0>(b)) return true;
		if (get<0>(a) < get<0>(b)) return false; // 오름차순
		if (get<1>(a) < get<1>(b)) return true; // 내림차순
		if (get<1>(a) > get<1>(b)) return false;
		if (get<2>(a) > get<2>(b)) return true; // 오름차순
		return false;
	}
};

int main() {
	priority_queue <tuple<int, int,string>, vector<tuple<int, int,string>>, cmp> pq;
	pq.push({ 3,2,"asd" });
	pq.push({ 3,5,"qwe" });
	pq.push({ 3,1,"qweqw"});
	pq.push({ 2,2,"zfas" });
	pq.push({ 2,1,"asda" });
	pq.push({ 2,3,"asdfq" });
	pq.push({ 3,2,"safw" });
	pq.push({ 2,2,"sadas" });
	while (!pq.empty()) {
		cout << get<0>(pq.top()) << " " << get<1>(pq.top()) << " str : " << get<2>(pq.top())<< endl;
		pq.pop();
	}

}*/