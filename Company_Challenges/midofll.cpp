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

//adding elements at tail

void addAtTail(node* &tail, int val){
    node* temp = new node(val);
    tail->next = temp;             //adding at tail
    tail = temp;
}

node* getMiddle(node* &head){

    if(head==NULL || head->next==NULL){
        return head;
    }
    else if(head->next->next==NULL){
        return head->next;
    }
    else{
        node* slow = head;
        node* fast = head->next;
        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
            }
            slow=slow->next;
        }
        return slow;
    }
    
}
/*node* midOfLinkedList(node* &head){
    node* temp=head;
    int length = 0;
    while(temp!=NULL){
        temp=temp->next;
        length++;
    }
    node* temp2=head;
    for(int i=1; i<((length+1)/2); i++){            method 1
           temp2=temp2->next;
    }
    return temp2;
}*/

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
    addAtTail(tail,32);
    addAtTail(tail,321);
    // node* middle = midOfLinkedList(head);

    node* middle = getMiddle(head);
    cout<<middle->data;
}