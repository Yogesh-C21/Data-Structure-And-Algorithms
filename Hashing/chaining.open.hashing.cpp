#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

struct Node* insertionSortedLinkedList(struct Node *p, int ele) {
    struct Node* first = p;
    struct Node* q = NULL;
    while(p && p->data< ele) {
        q = p;
        p = p->next;
    }
    struct Node* temp = new Node;
    temp->data = ele;
    temp->next = q->next;
    q->next = temp;
    return first;
}

int main() {
	
}
