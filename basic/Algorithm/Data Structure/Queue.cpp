#include <iostream>
using namespace std;

typedef struct qnode {
	int value; qnode *next;
}qnode;

class Queue {
public:
	qnode *front, *rear;
	Queue() {
		front = rear = NULL;
	}
	void insert(int data);
	int pop();
	bool empty();
	~Queue();
};

void Queue::insert(int data) {
	qnode *tmp = new qnode;
	if (tmp == NULL) { return; }
	tmp->value = data;
	tmp->next = NULL;
	if (front == NULL) {
		front = rear = tmp;
	}
	else {
		rear->next = tmp;
		rear = tmp;
	}

}

int Queue::pop() {
	int tmp = NULL;
	if (front == NULL) { return NULL; }
	if (front == rear) {
		front = rear = NULL;
		return tmp;
	}
	else {
		qnode *del = front;
		tmp = front->value;
		front = front->next;
		free(del);
		return tmp;
	}
}

Queue::~Queue() {
	while (front != NULL) {
		qnode *tmp = front;
		front = front->next;
	}
	rear = NULL;
}

bool Queue::empty() {
	if (front == rear) return true;
	return false;
}

int main() {
	Queue Q;
	Q.insert(1);
	Q.insert(22);
	Q.insert(5);
	Q.insert(4);
	Q.insert(6);
	while (!Q.empty()) {
		cout << Q.pop() << endl;
	}
}



typedef struct node {
	int data; node *next;
};

struct Queue {
	node *front, *rear;
	int len = 0;
	Queue() {
		front = rear = NULL;
	}
	int size() {
		return len;
	}
	bool isempty() {
		return !len;
	}
	void push(int val) {
		node *ne = (node *)malloc(sizeof(node));
		ne->data = val;
		ne->next = NULL;
		if (isempty()) {
			front = rear = ne;
		}
		else {
			rear->next = ne;
			rear = rear->next;
		}
		len++;
	}
	int pop() {
		if (isempty()) return -1;
		node *tmp = front;
		int ret = tmp->data;
		front = tmp->next;
		free(tmp);
		len--;
		return ret;
	}
};