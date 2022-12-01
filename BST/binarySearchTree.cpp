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

struct Node *insert(struct Node *p, int key) {
    struct Node *t = NULL;
    if(!p) {
        t = new Node(key);
        return t;
    }
    if(key < p->data) {
        p->leftChild = insert(p->leftChild, key);
    } else if(key > p->data) {
        p->rightChild = insert(p->rightChild, key);
    }
    return p;
}

void RinOrder(struct Node *p) {
    if(p) {
        RinOrder(p->leftChild);
        cout<<p->data<<" ";
        RinOrder(p->rightChild);
    } 
}

int main() {
    root = insert(root , 10);
    insert(root,30);
    insert(root,20);
    insert(root, 8);
    insert(root, 35);

    RinOrder(root);


}
