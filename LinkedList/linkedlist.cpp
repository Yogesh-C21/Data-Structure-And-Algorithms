#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val){        //constructor    
        data = val;
        next = NULL;     
    }  
};

void insertAtTail(node* &head, int val){ // function to insert node at tail
    if(head==NULL){
        head= new node(val);
        return;
    }
    node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next; 
    }
    temp->next= new node(val);
    
}

void display(node* head){
    node* temp =head;
    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL";
}

int main()
{
    node* head=NULL;
    insertAtTail(head,145);
    insertAtTail(head,212);
    insertAtTail(head,3);
    insertAtTail(head,4);
    display(head);
}