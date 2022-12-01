#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

void addAtHead(node* &head, int val){
    node* temp = new node(val);
    temp->next = head;
    head = temp;
}

void addAtTail(node* &tail, int val){
    node* temp = new node(val);
    tail->next = temp;
    tail = temp;
}

void addAtPosition(node* &head, int pos, int val){
    if(pos==1){
        addAtHead(head,val);
        return;
    }
    int count = 1;
    node* temp = head;
    while(count<pos-1){
          temp = temp->next;
          count++;
    } 
    node* insert = new node(val);
    insert->next = temp->next;
    temp->next = insert;
}

void print(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<"NULL";
}
int main()
{
   node* head = new node(10);
   node* tail = head;
    addAtTail(tail,45);
    addAtTail(tail,74);
    addAtTail(tail,99);
    addAtTail(tail,33);
    addAtTail(tail,43);
    addAtTail(tail,65);
    addAtTail(tail,77);
    addAtTail(tail,87);
    addAtTail(tail,98);
    addAtTail(tail,19);
    addAtTail(tail,22);
    addAtPosition(head,1,50);
    print(head);
}