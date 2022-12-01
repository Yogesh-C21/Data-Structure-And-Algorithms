#include<bits/stdc++.h>
using namespace std;

class Queue {
	private:
		int size;
		int front;
		int rear;
		int *Q;
	public:
		Queue() {
			front = rear = -1;
			size = 10;
			Q = new int[size];
		}
		Queue(int s) {
			front = rear = -1;
			size = s;
			Q = new int[size];
		}
		void enqueue(int element) {
	if(rear == size - 1) cout<<"Queue is Full\n";
	else {
		rear++;
		Q[rear] = element;
	}
}

int dequeue() {
	int deletedEle = -1;
	if(front == rear) {
		cout<<"Queue is Empty\n";
	} else {
		front++;
		deletedEle = Q[front];
	}
	return deletedEle;
}

void display() {
	front = (front == -1) ? 0 : front;
	for(int i = front+1; i<=rear; i++) {
		cout<<Q[i]<<" <-> ";
	}
}
};

int main() {
	Queue q;
	q.enqueue(32);
	q.enqueue(3);
	q.enqueue(23);
	q.enqueue(4);
	q.enqueue(112);
	cout<<q.dequeue()<<" ";
	cout<<q.dequeue()<<" ";
	cout<<q.dequeue()<<endl;
	
	q.display();
	
}
