#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node *leftChild;
    struct Node *rightChild;
    Node(int val) {
        data = val;
        leftChild = rightChild = NULL;
    }
}*root = NULL;

void insert(int key) {
    struct Node *t = root; 
    struct Node *r = NULL, *p;   // r is the tail pointer
    if(!root) {
        p = new Node(key);
        root = p;
        return;
    }
    while(t) {
        r = t;
        if(key == t->data) return;
        else if(key < t->data) {
            t = t->leftChild;
        } else {
            t = t->rightChild;
        }
        /* t = (key < t->data) ? t->leftChild : t->rightChild; */
    }
    p = new Node(key);
    if(p->data < r->data) r->leftChild = p;
    else r->rightChild = p;
}

void RinOrder(struct Node *p) {
    if(p) {
        RinOrder(p->leftChild);
        cout<<p->data<<" ";
        RinOrder(p->rightChild);
    } 
}

int search(struct Node *p, int key) {
    while(p) {
        if(p->data == key) return p->data;
        p = (p->data < key) ? p->rightChild : p->leftChild;
    }
    return -1;
}

int height(struct Node *p) {
    if(!p) return -1;
    int x = height(p->leftChild);
    int y = height(p->rightChild);
    return (x>y) ? x+1 : y+1;
}

struct Node *InPre(struct Node *p) {
    while(p && p->rightChild) {
        p = p->rightChild;
    }
    return p;
}

struct Node *InSucc(struct Node *p) {
    while(p && p->leftChild) {
        p = p->leftChild;
    }
    return p;
}

struct Node *deletion(struct Node *p, int key) {
    struct Node *q = NULL;
    if(!p) return NULL;
    if(!p->leftChild && !p->rightChild) {
        if(p == root) root = NULL;
        delete p;
        return NULL;
    }
    if(key < p->data) {
        p->leftChild = deletion(p->leftChild, key);
    } else if(key > p->data) { 
        p->rightChild = deletion(p->rightChild, key);
    } else {
        if(height(p->leftChild) > height(p->rightChild)) {
            q = InPre(p->leftChild);
            p->data = q->data;
            p->leftChild = deletion(p->leftChild, q->data);
        } else {
            q = InSucc(p->rightChild);
            p->data = q->data;
            p->rightChild = deletion(p->rightChild, q->data);
        }
    }
    return p;
}

int main() {
    int arr[] {9,15,5,20,16};
    int size = sizeof(arr) / sizeof(arr[0]);

    for(int i=0; i<size; i++) {
        insert(arr[i]);
    }
    deletion(root, 20);
    RinOrder(root);

    cout<<search(root, 15);


    // cout<<search(root, 9);


}
