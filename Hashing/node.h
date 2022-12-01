#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

void sortedInsert(struct Node **H, int key) {
    struct Node *newNode, *q=NULL, *p = *H;
    newNode = new Node(key);
    if(!*H) {
        *H = newNode;
    } else {
        while(p &&p->data < key) {
            q = p;
            p = p->next;
        }
        newNode->next = q->next;
        q->next = newNode;
    }
}

struct Node* search(struct Node *p, int key) {
    while(p) {
        if(key == p->data) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

int deletion(struct Node* p, int key) {
    int deletedValue = -1;
    struct Node* q = NULL;
    while(p) {
        if(key == p->data) {
            deletedValue = p->data;
            q->next = p->next;
            p->next = NULL;
            delete p;
            return deletedValue;
        }
        q = p;
        p = p->next;
    }
    return deletedValue;
}
