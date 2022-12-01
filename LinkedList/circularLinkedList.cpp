#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
}*head;

void create(int arr[], int n) {
    head = new Node;
    struct Node* temp;
    head->data = arr[0];
    head->next = head;   // will point to itself
    struct Node* last = head;
    for(int i=1; i<n; i++) {
        temp = new Node;
        temp->data = arr[i];
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}

void insert(struct Node* p, int index, int ele) {
    struct Node* temp = new Node;
    temp->data = ele; // temp node to be inserted

    /* procedure for insertion of node on zero index or nth position in the linked list */
    if(index == 0) { // insertion at head so will make new node inserted at zero index as new node
        if(!head) {
            head = temp;
            head->next = head;   // pointing to self will also create a circular linked list
        } else {
            while(p->next != head) p = p->next;
            p->next = temp;
            temp->next = head;
            head = temp;
        }
    } else {
        for(int i = 0; i < index - 1; i++) p = p->next;
        temp->next = p->next;
        p->next = temp;
    }
}

int deletion(struct Node* p, int pos) {
    struct Node* q = NULL;
    int deletedData;
    if(pos == 1) {
        while(p->next != head) p = p->next;
        deletedData = head->data;
        if(p == head) {
            delete head;
            head = NULL;
        } else {
            p->next = head->next;
            delete head;
            head = p->next;
        }
    } else {
        for(int i=0; i<pos-2; i++) p = p->next;
        q = p->next;
        p->next = q->next;
        deletedData = q->data;
        delete q;
    }
    return deletedData;
}

void display(struct Node* p) {
    do {
        cout<<p->data<<" ";
        p = p->next;
    } while(p!=head);
}

void recursiveDisplay(struct Node *p) {
    static bool flag = false;
    if(p!=head || flag==false) {
        flag = true;
        cout<<p->data<<" ";
        recursiveDisplay(p->next);
    }
    flag = false;
}

int main() {
    int arr[] = {2,3,7,5,6};
    int size = sizeof(arr) / sizeof(arr[0]);
    create(arr,size);

    // display(head);
    deletion(head, 2);

   /*  insert(head, 2, 10); */

    recursiveDisplay(head);



}