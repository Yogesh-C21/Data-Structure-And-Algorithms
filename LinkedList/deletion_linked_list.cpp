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

    //destructor
    ~node(){
        int val = data;
        // memory free
        if(next!=NULL){
            delete next;
            next = NULL;
        }
    cout<<"Destructor is called and memory is free for data "<<val<<endl;
    }
};

// void addAtHead(node* &head, int val){
//     node* temp = new node(val);
//     temp->next = head;
//     head = temp;                    //adding at head
// }

void addAtTail(node* &tail, int val){
    node* temp = new node(val);
    tail->next = temp;             //adding at tail
    tail = temp;
}

void deletion(node* &head, node* &tail, int pos){
    if(pos==1){
        node* temp = head;
        head = temp->next;
        temp->next = NULL;
        delete temp;
        return;  
    }

    int count = 1;
    node* prev = NULL;
    node* curr = head;
    while(count< pos){
           prev = curr;
           curr = curr->next;
           count++;
    }
    if(curr==tail){
        prev->next = NULL;
        tail = prev;
        delete curr;    
        return;
    }
    else{
    prev->next = curr->next;
    curr->next=NULL;
    delete curr;
    }

    }

// void addAtPosition(node* &head, node* &tail, int pos, int val){
//     if(pos==1){
//         addAtHead(head,val);
//         return;
//     }
                                             
//     int count = 1;
//     node* temp = head;
//     while(count<pos-1){
//           temp = temp->next;
//           count++;
//     } 
//      if(temp->next==NULL){
//         addAtTail(tail,val);
//         return;
//     }
//     node* insert = new node(val);
//     insert->next = temp->next;
//     temp->next = insert;
// }


void print(node* &head){
    node* temp=head;
    int i=0;
    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp=temp->next;
        i++;
    }
    cout<<"NULL\n"<<i<<" are the number of nodes\n";
    
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

    //printing linked list

     print(head);

    // deletion of nodes of linked list
    deletion(head,tail,6);  //deletion from between
    deletion(head,tail,1);  //deletion of head node

    cout<<head->data<<" is the head node\n";
    cout<<tail->data<<" is the tail node\n";


    // cout<<head->data<<" is the head node\n";
    deletion(head,tail,10);  //deletion of last node
    
    print(head);

    cout<<head->data<<" is the head node\n";
    cout<<tail->data<<" is the tail node\n";
    
   
    
}