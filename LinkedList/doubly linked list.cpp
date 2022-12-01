#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;

    //constructor
    node(int val){
        data = val;
        next= NULL;
        prev= NULL;
    }
};

    //add at head
    void addAtHead(node* &head, int val){
        node* temp = new node(val);
        temp->next = head;
        head->prev = temp;
        head = temp;

    // add at tail
    }
    void addAtTail(node* &tail, int val){
        node* temp = new node(val);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }

    void printLinkedList(node* head){
        node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" -> ";    //print method 1
            temp = temp->next;
        }
        cout<<"NULL\n";
    }
int main()
{
    node* head = new node(10);
    node* tail = head;
    addAtTail(tail,20);
    addAtHead(head,34);
    addAtTail(tail,265);
    addAtHead(head,11);
    addAtTail(tail,24);
    addAtHead(head,206);
    addAtTail(tail,204);
    addAtHead(head,211);
    addAtTail(tail,343);
    printLinkedList(head);
    
    for(node* temp=head; temp!=NULL; temp=temp->next){
        cout<<temp->data<<" -> ";
    }                                         // print method 2
     cout<<"NULL\n";

    for(node* temp=tail; temp!=NULL; temp=temp->prev){
        cout<<temp->data<<" -> ";                  //printing reversed linked list
    }
    cout<<"NULL\n";    /// the time complexity of this algorithm is BigO(n)
    
}