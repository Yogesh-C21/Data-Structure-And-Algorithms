#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
    Node* next;
}*Top = NULL;

void push(int element) {
        struct Node* temp = new Node;
        if(!temp) cout<<"Stack Overflow\n"; // will check whether temp node is created inside heap
        else {
            temp->data = element;
            temp->next = Top;
            Top = temp;
        }
    }

	int pop() {
    	int deletedNodeData = -1;
        if(!Top) cout<<"Stack Is Empty\n";
        else{
            deletedNodeData = Top->data;
            struct Node* temp = Top;
            Top = Top->next;
            delete temp;
        }
        return deletedNodeData;
    } 

    void display() {
        Node* p = Top;
        while(p) {
            cout<<p->data<<endl;
            p = p->next;
        }
    }


int main() {
    push(10);
    push(20);
    display();




    return 0;
}