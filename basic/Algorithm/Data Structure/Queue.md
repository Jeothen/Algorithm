# Queue

 queue라는 자료구조의 용도는 보통 임시로 자료를 저장해둔다는 맥락을 가집니다.

버퍼역시 queue라는 자료구조로 구현되게 되는데 그 말인 즉슨 버퍼를 가지는 모든

데이터에서 이 큐를 사용하게 된다는 겁니다.

뭔 말인고 하면 어짜피 데이터는 이번꺼 처리하면 다음 데이터를 처리하게 되 있는데

그걸 잠시 저장해두는 공간이라는 거죠.



**3.큐의 시간복잡도**

![img](https://mblogthumb-phinf.pstatic.net/20151016_264/justkukaro_14449633775997CTG2_PNG/%C5%A5%28%C0%DA%B7%E1%B1%B8%C1%B6%29__queue.png?type=w2)

**출처-https://namu.wiki/w/%ED%81%90(%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0)**

큐 역시 스택과 마찬가지로 push와 pop이라는 개념이 있습니다.

그러나 push와 pop이라는 표현은 잘 쓰지 않고 enqueue dequeue라고 씁니다.

즉 enqueue는 큐에 집어넣고 dequeue는 큐에서 빼는거죠.

물론 push와 pop이라고 표현하는 사람도 있으니 만든사람 마음대로긴 하지만

약간 어감의 차이라고 할까요? stack을 프로그래머들은 입구가 하나인 상자를 생각하지만

queue는 통로로 생각하기 때문이죠.



보통 queue를 구현할 때 dequeue와 enqueue 외에도 스택에서 사용한 peek와 empty가 있습니다.

물론 여기서 peek라는 표현은 사용하지 않고 getfront라고 합니다. 물론 peek라 표현한곳도 존재는 합니다.

그리고 양면에서 삽입과 삭제가 가능한 queue는 getfront외에도 getrear도 존재합니다.



**※그럼 rear를 보여주는 getrear는 없나요?**

물론 만들 수는 있겠고 구현도 매우 쉽겠지만 조금만 생각해보면 필요없다는걸 알 수 있습니다.

어쨋던 큐도 내부의 구조나 누가 추가됬는지는 관심없고 앞으로 누가 나갈건지

누구를 쓸건지만 관심이 있습니다.

즉 getrear는 만들 수 있고 deque라는 큐가 양면으로 가능한 자료구조에서는 getrear가 존재합니다.



즉 사용하는 메소드는

**1-enqueue**

**2-dequeue**

**3-empty(full)**

**4-getfront**

**5-size(level)**



정도가 되겠네요.

스택의 예에서도 알겠지만 1번과 2번,그리고 4번의 경우 역시 각각의 front와 rear의 존재로 단 한번만에 체크가 가능합니다.

따라서 시간복잡도는 O(1)가 되므로 상수시간이됩니다.

그러면 나머지를 봅시다.



**3-empty(full)**

empty역시 시간복잡도가 1이나옵니다. 구현도 매우쉽습니다. front가 null이면 비어있는겁니다. 물론 큐의 특성상 비어있다면

frunt가 null이면 rear도 null입니다. full의 경우에는 rear의 첨자가 배열의 크기를 벗어났다면 full이므로  시간복잡도는 1이됩니다.



**5-size(level)**

rear첨자 - front첨자 = size

따라서 시간복잡도는 1이나옵니다.



근데 문제는 사실 1번이 시간복잡도가 다를 수 있습니다. 이는 아래에서 큐의 구현 in C에서 상세히 다루도록하겠습니다. 



**4.queue의 구현 in C**

![img](https://mblogthumb-phinf.pstatic.net/20151016_250/justkukaro_1444963524885Wfkh5_PNG/queue.png?type=w2)



보통 queue의 구현은 배열로 하게 됩니다. queue의 구현은 front와 rear를 첨자로 두고 왔다갔다 하게 됩니다.

첫 queue의 생성시 front와 rear는 같은 첨자를 하게됩니다. 여기서 front와 rear모두 첫 첨자는 -1로 시작하는데

배열의 시작넘버가 0이기 때문입니다. 이는 스택과 같죠.

그리고 추가하면 rear를 증가하고 삭제할 때는 front를 증가시킵니다.

그리고 empty를 확인하는 방법 (보통isempty 메소드로 구현)하는 방법은 front와 rear가 같을경우입니다.

그 이유는 간단합니다. 맨처음 자료가 없는상태에서 둘의 첨자는 -1로 동일합니다.

그러나 자료가 들어오면 rear의 값이 0가 됩니다. 여기서 자료를 꺼집어 내면 front의 값이 0가 되므로 둘의 값은 동등하게 0이되고

이 경우 자료가 비어있는 상태가 됩니다.

getfront는 enqueue와 비슷하게 구현하면 되고 size의 경우 rear-front를 해주면 됩니다.

```c
#include<stdbool.h>
#include<stdio.h>
#ifndef QUEUE_H
#define QUEUE_H
#define NUM 10

int queue[NUM];
static int front = -1;
static int rear = -1;

bool queue_empty() {
	if (front == rear) return true;
	else return false;
}

bool queue_full() {
	if (rear == NUM - 1) return true;
	else return false;
}

bool queue_enqueue(int data) {
	if (queue_full()) return false;
	else {
        queue[++rear] = data;
        return true;
	}
}

int queue_dequeue(){
	if (queue_empty()) return NULL;
	return queue[++front];
}

int queue_getfront() {
	return queue[front+1];
}

int queue_size() {
	return rear-front;
}

```









* Source Code

```c
typedef struct node{
	node *pre;
	int data;
	node *next;
}node;

node *head;
node *t;
node *tail;

void createnodes() {
	t = (node *)malloc(sizeof(node));
	t->next = (node *)malloc(sizeof(node));
	t->next->pre = t;
	head = t;
	t->data = 111;
	t = t->next;
	t->data = 222;
	tail = t;
	t = head;
}

void push(int num) {
	node *ne = (node *)malloc(sizeof(node));
	ne->next = tail;
	tail->pre = ne;
	t->next = ne;
	ne->pre = t;
	ne->data = num;
	t = ne;
}

void pop() {
	node *temp;
	temp = head->next;
	temp->next->pre = head;
	printf("%d\n", temp->data);
	head->next = temp->next;
	free(temp);
	t = tail->pre;
}
```









```c++


typedef struct node {
	node *pre;
	node *next;
	node *t;
	node *head;
	node * tail;
	int data;

	node() {
		t = (node *)malloc(sizeof(node));
		t->next = (node *)malloc(sizeof(node));
		t->data = NULL;
		t->next->pre = t;
		head = t;
		t = t->next;
		t->data = NULL;
		tail = t;
		t = head;
	}
	~node() {
		while (!empty()) {
			printf("%d", pop());
		}
	}

	void push(int val) {
		node *ne = (node *)malloc(sizeof(node));
		ne->next = tail;
		tail->pre = ne;
		t->next = ne;
		ne->pre = t;
		ne->data = val;
		t = ne;
	}
	int pop() {
		node *tmp;
		tmp = head->next;
		int val = tmp->data;
		tmp->next->pre = head;
		head->next = tmp->next;
		free(tmp);
		return val;
	}
	bool empty() {
		if (head->next == tail) return true;
		return false;
	}
}node;

node queue[30];
```

