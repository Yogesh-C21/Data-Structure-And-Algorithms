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

    //destructor

    ~node(){
        int val = data;
        if(next!=NULL){
            next = NULL;
            delete next;
        }
         cout<<"Destructor is evoked for "<<val<<"\n";
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


    //deletion of DLL

    void deletion(node* &head, node* &tail, int pos){
    if(pos==1){
        node* temp = head;
        head = temp->next;
        temp->next = NULL;
        head->prev = NULL;
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
        tail = tail->prev;
        prev->next=NULL;
        curr->prev=NULL;
        delete curr;
    }
     else{
        prev->next = curr->next;
        curr->prev = NULL;
        curr->next=NULL;
        delete curr;
     }
    
    }


    // void insertAtPosition(node* &head,node* &tail, int val, int pos){
    //       if(pos==1){
    //       addAtHead(head,val);
    //       return;
    // }
    // node* temp = head;
    // int count = 1 ;
    // while(count<pos-1){
    //     temp = temp->next;
    //     count++;
    // }
    // if(temp==tail){
    //     addAtTail(tail,val);
    //     return;
    // }
    // node* insert = new node(val);
    // node* temp2 = temp->next;
    // insert->next = temp->next;
    // temp->next = insert;
    // insert->prev = temp;
    // temp2->prev = insert;

    // }


    // void printLinkedList(node* head){
    //     node* temp = head;
    //     while(temp!=NULL){
    //         cout<<temp->data<<" -> ";    //print method 1
    //         temp = temp->next;
    //     }
    //     cout<<"NULL\n";
    // }
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


    //insertion at any position in Doubly LL

    // insertAtPosition(head,tail,55,5);   // insertion in between
    // insertAtPosition(head,tail,32,1);  // insertion at first position
    // insertAtPosition(head,tail,161,13); // insertion at last position


     for(node* temp=head; temp!=NULL; temp=temp->next){
        cout<<temp->data<<" -> ";
    }                                         // print method 2
     cout<<"NULL\n";


    //deletion at any position in Doubly LL


    

    cout<<head->data<<" is the head node\n";
    cout<<tail->data<<" is the tail node\n";
    
    
    deletion(head,tail,5);
    deletion(head,tail,1);
    deletion(head,tail,8);

    cout<<head->data<<" is the head node\n";
    cout<<tail->data<<" is the tail node\n";

    // printLinkedList(head);

    //printing final doubly linked list
    
    for(node* temp=head; temp!=NULL; temp=temp->next){
        cout<<temp->data<<" -> ";
    }                                         // print method 2
     cout<<"NULL\n";





    // for(node* temp=tail; temp!=NULL; temp=temp->prev){
    //     cout<<temp->data<<" -> ";                  //printing reversed linked list
    // }
    // cout<<"NULL\n";   
    
    
    


     /// the time complexity of this algorithm is O(n).
    
}