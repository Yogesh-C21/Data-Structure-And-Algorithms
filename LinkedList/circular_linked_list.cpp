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

// void addAtTail(node* &tail, node* &head, int val){
//     node* temp = new node(val);
//     tail->next = temp;             //adding at tail
//     tail = temp;
    
// }

void insertNode(node* &tail, int val, int element){
    // if the list is empty
    if(tail==NULL){
        node* newNode = new node(val);
        tail = newNode;
        newNode->next = newNode;
    }

    // if the list is not empty
    else{
        node* current = tail;
        while(current->data!=element){
            current = current->next;
        }

        // hurray we found the element.
        node* temp = new node(val);
        temp->next = current->next;
        current->next=temp;
    }

}

// void deletion(node* &head, node* &tail, int pos){
//     if(pos==1){
//         node* temp = head;
//         head = temp->next;
//         temp->next = NULL;
//         delete temp;
//         return;  
//     }

//     int count = 1;
//     node* prev = NULL;
//     node* curr = head;
//     while(count< pos){
//            prev = curr;
//            curr = curr->next;
//            count++;
//     }
//     if(curr==tail){
//         prev->next = NULL;
//         tail = prev;
//         delete curr;    
//         return;
//     }
//     else{
//     prev->next = curr->next;
//     curr->next=NULL;
//     delete curr;
//     }

//     }

// // void addAtPosition(node* &head, node* &tail, int pos, int val){
// //     if(pos==1){
// //         addAtHead(head,val);
// //         return;
// //     }
                                             
// //     int count = 1;
// //     node* temp = head;
// //     while(count<pos-1){
// //           temp = temp->next;
// //           count++;
// //     } 
// //      if(temp->next==NULL){
// //         addAtTail(tail,val);
// //         return;
// //     }
// //     node* insert = new node(val);
// //     insert->next = temp->next;
// //     temp->next = insert;
// // }


void print(node* &tail){
    node* temp=tail;
    int i=0;
    do{
        cout<<temp->data<<" -> ";
        temp=temp->next;
        i++;
    }while(temp!=tail);
    cout<<"NULL\n"<<i<<" are the number of nodes\n";  
}

int main()
{
    node* tail = NULL;
    insertNode(tail, 32, 0);
    insertNode(tail, 11, 32);
    insertNode(tail, 41, 11);
    insertNode(tail, 10, 41);
    insertNode(tail, 65, 11);
    insertNode(tail, 99, 41);
    insertNode(tail, 87, 65);

    
    print(tail);


    //printing head and tail data
//    cout<<head->data<<"\n";
//    cout<<tail->data<<"\n";
   

    

    
   
    
}