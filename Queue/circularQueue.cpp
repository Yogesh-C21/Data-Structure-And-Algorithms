#include<bits/stdc++.h>
using namespace std;

/* Circular Queue Implementation */

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
	q->front = q->rear = 0;
}

void enqueue(struct Queue *q, int element) {
	if((q->rear + 1)%q->size == q->front) cout<<"Queue is Full\n";
	else {
		q->rear = (q->rear + 1)%q->size;
		q->Q[q->rear] = element;
	}
}

int dequeue(struct Queue *q) {
	int deletedEle = -1;
	if(q->front == q->rear) {
		cout<<"Queue is Empty\n";
	} else {
		q->front = (q->front + 1)%q->size;
		deletedEle = q->Q[q->front];
	}
	return deletedEle;
}

void display(struct Queue q) {
	int i = q.front + 1;
	/* here we are using do-while loop since the termination condition front = rear is same as starting condtion*/
	do {
		cout<<q.Q[i]<<" <-> ";
		i = (i + 1)%q.size;
	} while(i!= (q.rear +1)%q.size);
	cout<<"\n\n";
	cout<<"Front is "<<q.front<<endl;
	cout<<"Rear is "<<q.rear;
}

int main() {
	struct Queue q;
	create(&q);
	enqueue(&q, 32);
	enqueue(&q, 43);
	enqueue(&q, 52);
	enqueue(&q, 13);

	display(q);
}
