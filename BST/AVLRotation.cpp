#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node *leftChild;
    struct Node *rightChild;
    int height;
    Node(int val) {
        data = val;
        leftChild = rightChild = NULL;
        height = 1;
    }
}*root = NULL;

/* considering the height starts from 1 instead of 0. */


int nodeHeight(struct Node *p, )

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
    p->height = nodeHeight()
    return p;
}

int main() {


    return 0;
}