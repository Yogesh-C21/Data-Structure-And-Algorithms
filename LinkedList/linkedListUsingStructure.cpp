#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

struct Node* linkedListCreation(int arr[], int n) {      
    struct Node *t= new Node;
    t->data = arr[0];
    t->next = NULL;
    struct Node *first = t;
    for(int i =1; i<n; i++) {
        struct Node *temp = new Node; // 
        temp->data = arr[i];         // in classes we can do this using constructor
        temp->next = NULL;          //
        t->next = temp;
        t = temp;
    }
    return first;
}

struct Node* insertionAtLast(struct Node* p, int ele) {
   // **CONDITION: any node in the LL should not point to NULL
   struct Node* first = p;
    while(p->next!=NULL) {
        p = p->next;
    }
    struct Node *last = new Node;
    last->data = ele;
    last->next = NULL;
    p->next = last;
    p = last;
    return first;
}

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

struct Node* deletionLinkedList(struct Node *p, int pos) {
    struct Node *first = p;
    if(pos==1) {
        first = p->next;
        p->next = NULL;
        delete p;
        return first; // will return the linked list with deleted Node on first position
    }
    else {
        Node *q =NULL;
        for(int i = 1; i<pos && p; i++) {
            q = p;
            p = p->next;
        }
        if(p) {
            q->next = p->next;
            delete p;
        }
        return first;  // will return the linked list with deleted Node on nth position
    }
}

bool checkSorted(struct Node *p) {
    int data = INT_MIN;
    while(p) {
        if(p->data < data) return false;
        data = p->data;
        p = p->next;
    }
    return true;
}

struct Node* removeDuplicateSortedLinkedList(struct Node* p) {
    struct Node* first = p;
    struct Node* q = p->next;
    while(q) {
        if(p->data!=q->data) {
        p = q;
        q = q->next;
        } else {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
    return first;
}

struct Node* reverseLinkedList(struct Node* p) {
    struct Node* q = NULL;
    struct Node* r = NULL;
    while(p) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    struct Node* first = q; // since on  reversal q will become first node
    return first;
}

/* struct Node* reverseRecursionLinkedList(struct Node* p, struct Node* q) {
    if(p) {
        reverseRecursionLinkedList()
    }
} */

struct Node* concatenate(struct Node* first, struct Node* second) {
    struct Node* concate = first;
    while(first) first = first->next;
    first->next = second;
    while(concate) cout<<concate->data<<" ";
    return concate;
}



struct Node* mergeLinkedList(struct Node* first, struct Node* second) {
    struct Node* merged = NULL;
    struct Node* last = NULL;
    merged = ((first->data<second->data) ? first : second);
    while(first && second) {
        if(first->data < second->data) {
            last->next = first;
            last = first;
            first = first->next;
            last->next = NULL;
        } else {
            last->next = second;
            last = second;
            second = second->next;
            last->next = NULL;
        }
    }
    last->next = first ? first : second;
    return merged;
}

int main() {
    int arr[] = {-22,2,3,3,5,7,8,8,8,9,108};
    int arr2[] = {4,10,11,23};
    int size = sizeof(arr) / sizeof(arr[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    struct Node* linkedList = linkedListCreation(arr,size);
    struct Node* linkedList2 = linkedListCreation(arr2,size2);

    struct Node* concate = concatenate(linkedList, linkedList2);

    /* for(struct Node* itr = linkedList2; itr!=NULL; itr=itr->next) {
        cout<<itr->data<<" ";
    }  */ 



    // struct Node* insertion = insertionSortedLinkedList(linkedList, 4);

    /* for(struct Node* itr = insertion; itr!=NULL; itr=itr->next) {
        cout<<itr->data<<" ";
    } */ 



    /* struct Node * deletion = deletionLinkedList(insertion, 4);

    for(struct Node* itr = deletion; itr!=NULL; itr=itr->next) {
        cout<<itr->data<<" ";
    }  */
    /* while(start) {
        cout<<start->data<<" ";
        start = start->next;
    }  */


    /* check sorted */
   /*  string str = checkSorted(linkedList) ? "Sorted Linked List" : "Unsorted Linked List";
    cout<<str; */

    /* ##### */

    /* struct Node* remDuplicate = removeDuplicateSortedLinkedList(linkedList);

    for(struct Node* itr = remDuplicate; itr!=NULL; itr=itr->next) {
        cout<<itr->data<<" ";
    } */





    /*   Reversing a Linked List */

    /* struct Node* reverse = reverseLinkedList(linkedList);

    for(struct Node* itr = reverse; itr!=NULL; itr=itr->next) {
        cout<<itr->data<<" ";
    } */

    /* struct Node* merge = mergeLinkedList(linkedList, linkedList2);

    for(struct Node* itr = merge; itr!=NULL; itr=itr->next) {
        cout<<itr->data<<" ";
    }  */










    /* struct Node* insertionPointer = insertionAtLast(linkedListPointer, 66);
    while(insertionPointer) {
        cout<<insertionPointer->data<<endl;
        insertionPointer = insertionPointer->next;
    } */
}
