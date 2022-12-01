#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){                  //constructor 
        data = val;
        next = NULL;
    }
};

void addAtTail(node* &tail, int val){
    node* temp = new node(val);
    tail->next = temp;             //adding at tail
    tail = temp;
}


 //writing reverse 
node* reverse(node* &head){
    node* prev = NULL;
    node* curr = head;
    node* foreward = NULL;
    while(curr!=NULL){
        foreward = curr->next;
        curr->next=prev;
        prev = curr;
        curr = foreward;
    }
    head = prev;
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

    
    reverse(head);
    

    print(head);
}