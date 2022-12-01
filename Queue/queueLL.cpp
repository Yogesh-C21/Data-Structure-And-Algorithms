#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
}*front = NULL, *rear = NULL;

void enqueue(int element) {
	struct Node* temp = new Node;
	if(!temp) cout<<"Queue is Full\n";
	else {
		temp->data = element;
		temp->next = NULL;
		if(!front) front = rear = temp;
		else {
			rear->next = temp;
			rear = temp;
		}
	}
}

int dequeue() {
	int deletedNode = -1;
	struct Node* p;
	if(!front) cout<<"Queue is Empty\n";
	else {
		p = front;
		front = front->next;
		deletedNode = p->data;
		delete p;
	}
	return deletedNode;
}

void display() {
	struct Node* p = front;
	while(p) {
		cout<<p->data<<" ";
		p = p->next;
	}
}

int main() {
	enqueue(5);
	enqueue(1);
	enqueue(4);
	enqueue(7);
	enqueue(8);
	dequeue();
	dequeue();
	dequeue();

	display();

	
}
