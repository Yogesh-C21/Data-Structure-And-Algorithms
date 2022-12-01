#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
};

class Stack {
    private:
    Node *Top;
    public:
    Stack() {
        Top = NULL;
    }
    void push(int element) {
        Node* temp = new Node;
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
        else {
            deletedNodeData = Top->data;
            Node* temp = Top;
            Top = Top->next;
            delete temp;
        }
        return deletedNodeData;
    } 

    void Display() {
        Node* p = Top;
        while(p) {
            cout<<p->data<<endl;
            p = p->next;
        }
    }
};


int main() {
    Stack St;
    St.push(5);
    St.push(3);
    St.push(6);
    St.push(1);
    St.push(44);

    St.pop();
    St.pop();

    St.Display();




    return 0;
}