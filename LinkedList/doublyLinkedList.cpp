#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *prev, *next;
}*first = NULL, *last = NULL;

void create(int arr[], int n) {
    struct Node* t = new Node;
    struct Node* temp;
    t->data = arr[0];
    t->prev = t->next = NULL;
    first = last = t;
    for(int i=1; i<n; i++) {
        temp = new Node;
        temp->data = arr[i];
        temp->next = NULL;
        temp->prev = t;
        t->next = temp;
        t = temp;
        last = t;  // last is for having a pointer pointing to last element in DLL. Not compulsory.
    }
}

void insertion(struct Node* p, int value, int index) {
    struct Node* temp = new Node;
    temp->data = value;
    if(index == 0) {
        temp->next = p;
        p->prev = temp;
        temp->prev = NULL;
        first = temp;
    } else {
        first = p;
        for(int i=0; i<index-1; i++) p = p->next;
        temp->next = p->next;
        if(p->next) {
            p->next->prev = temp;
            p->next = temp;
            temp->prev = p;
        } else {
            p->next = temp;
            temp->prev = p;
            last = temp;
        }
    }
}

void deletion(struct Node* p, int index) {
    if(index == 0) {
        first = p->next;
        p->next = p->next->prev = NULL;
        delete p;
    } else {
        for(int i=0; i<index; i++) p = p->next;
        p->prev->next = p->next;
        if(p->next) p->next->prev = p->prev;
        else {
            last = p->prev;
            p->prev = NULL;
        }
        delete p;
    }
}

void reverse(struct Node* p) {
    struct Node* temp;
    while(p) {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if(p && (!p->next)) first = p;
    }
}

void display(struct Node* p) {
    while(p) {
        cout<<p->data<<"  <->  ";
        p = p->next;
    }
}

int main() {

    int arr[] = {-2,1,0,4,7};
    int size = sizeof(arr) / sizeof(arr[0]);
    create(arr,size);

    // insertion(first, 11, 1);


    // deletion(first, 2);
    
    reverse(first);

    display(first);




}