#include<bits/stdc++.h>
using namespace std;

struct Queue {
	int size;
	int front;
	int rear;
	int *Q;
};

create(struct Queue *q) {
	cout<<"Enter size -> ";
	cin>>q->size;
	q->Q = new int[q->size];
	q->front = q->rear = -1;
}

void enqueue(struct Queue *q, int element) {
	if(q->rear == q->size - 1) cout<<"Queue is Full\n";
	else {
		q->rear++;
		q->Q[q->rear] = element;
	}
}

int dequeue(struct Queue *q) {
	int deletedEle = -1;
	if(q->front == q->rear) {
		cout<<"Queue is Empty\n";
	} else {
		q->front++;
		deletedEle = q->Q[q->front];
	}
	return deletedEle;
}

void display(struct Queue q) {
	q.front = (q.front == -1) ? 0 : q.front;
	for(int i = q.front+1; i<=q.rear; i++) {
		cout<<q.Q[i]<<" <-> ";
	}
}

int main() {
	struct Queue q;
	create(&q);
	enqueue(&q, 32);
	enqueue(&q, 43);
	enqueue(&q, 52);
	enqueue(&q, 13);
	cout<<dequeue(&q)<<" ";
	cout<<dequeue(&q)<<" ";
	display(q);
}
