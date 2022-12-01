#include<bits/stdc++.h>
#define queueSize 100  // defined queue size here
using namespace std;
struct Node {
    int data;
    struct Node* leftChild;
    struct Node* rightChild;
};

struct Queue {
	int size;
	int front;
	int rear;
	struct Node** Q;
};

createQueue(struct Queue *q) {
	q->size = queueSize;
	q->Q = new Node*[q->size];
	q->front = q->rear = 0;
}

void enqueue(struct Queue *q, struct Node* element) {
	if((q->rear + 1)%q->size == q->front) cout<<"Queue is Full\n";
	else {
		q->rear = (q->rear + 1)%q->size;
		q->Q[q->rear] = element;
	}
}

struct Node* dequeue(struct Queue *q) {
	struct Node* deletedEle = NULL;
	if(q->front == q->rear) {
		cout<<"Queue is Empty\n";
	} else {
		q->front = (q->front + 1)%q->size;
		deletedEle = q->Q[q->front];
	}
	return deletedEle;
}

bool isEmpty(struct Queue q) {
    return q.front == q.rear;
}
