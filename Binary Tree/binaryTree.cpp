#include<bits/stdc++.h>
#include "queue.h"
#include "stack.h"
using namespace std;

struct Node *root = NULL;
/* -1 denotes null value of data inside node for tree */
void treeCreate() {
    struct Node *p, *temp;
    int dataValue;
    struct Queue q;
    createQueue(&q);
    cout<<"Enter root value -> ";
    cin>>dataValue;
    root = new Node;
    root->data = dataValue;
    root->leftChild = root->rightChild = NULL;
    enqueue(&q, root);
    while(!isEmpty(q)) {                                        
        p = dequeue(&q);
        cout<<"Enter Left Child of "<<p->data<<" ";
        cin>>dataValue;
        if(dataValue!=-1) {
            temp = new Node;
            temp->leftChild = temp->rightChild = NULL;
            temp->data = dataValue;
            p->leftChild = temp;
            enqueue(&q, temp);
        }
        cout<<"Enter Right Child of "<<p->data<<" ";
        cin>>dataValue;
        if(dataValue!=-1) {
            temp = new Node;
            temp->leftChild = temp->rightChild = NULL;
            temp->data = dataValue;
            p->rightChild = temp;
            enqueue(&q, temp);
        }
    }
}

/* **NOTE: in above -1 is the null condition for all nodes except root */

/*--------------- Pre Order -----------------------*/
void RpreOrder(struct Node *p) {
    if(p) {
        cout<<p->data<<" ";
        RpreOrder(p->leftChild);
        RpreOrder(p->rightChild);
    }
}

void IpreOrder(struct Node *p) {
    struct Stack St;
    createStack(&St);
    while(p || !isEmpty(St)) {
        if(p) {
            cout<<p->data<<" ";
            push(&St, p);
            p = p->leftChild;
        } else {
            p = pop(&St);
            p = p->rightChild;
        }
    }
}


/*--------------- Post Order -----------------------*/

void RpostOrder(struct Node *p) {
    if(p) {
        RpostOrder(p->leftChild);
        RpostOrder(p->rightChild);
        cout<<p->data<<" ";
    }
}

/* void IpostOrder(struct Node *p) {
    struct Stack St;
    createStack(&St);
    struct Node *temp;
    while(p || !isEmpty(St)) {
        if(p) {
            push(&St, p);
            p = p->leftChild;
        } else {
            temp = pop(&St);
            if(temp>0) {
                push(&St, -temp);
                p = temp->leftChild;
            } else {
                cout<<temp->data;
                p = NULL;
            }
        }
    }
} */

void RinOrder(struct Node *p) {
    if(p) {
        RinOrder(p->leftChild);
        cout<<p->data<<" ";
        RinOrder(p->rightChild);
    } 
}

int recursiveCountNodes(struct Node *p) {
    if(p) {
        return recursiveCountNodes(p->leftChild) + recursiveCountNodes(p->rightChild) + 1;
    } return 0;
}

int height(struct Node *p) {
    int x,y;
    // x = y = -1;
    if(!p) return -1;
    x = height(p->leftChild);
    y = height(p->rightChild);
    if(x>y) return x + 1;
    else return  y + 1;
}

int level(struct Node *p) {
    int x,y;
    // x = y = 0;
    if(!p) return 0;
    x = height(p->leftChild);
    y = height(p->rightChild);
    if(x>y) return x + 1;
    else return  y + 1;
}

int leafNodeCount(struct Node *p) {   //nodes with degree 0
    int x,y;
    if(p) {
        x = leafNodeCount(p->leftChild);
        y = leafNodeCount(p->rightChild);
        if(!p->leftChild && !p->rightChild) return x+y+1;
        else return x+y;
    }
    return 0;
}

int nodesWithDegree2(struct Node *p) {
    int x,y;
    if(p) {
        x = leafNodeCount(p->leftChild);
        y = leafNodeCount(p->rightChild);
        if(p->leftChild && p->rightChild) return x+y+1;
        else return x+y;
    }
    return 0;

}



int main() {

    treeCreate();

    cout<<recursiveCountNodes(root)<<" are the no. of nodes\n";
    cout<<height(root)<<" is the height of tree\n";
    cout<<level(root)<<" is the level of tree\n";

    cout<<leafNodeCount(root)<<" is the number of leaf nodes\n";

    cout<<nodesWithDegree2(root)<<" are the nodes with degree 2\n";




    /* RpreOrder(root);
    cout<<" this is recursive pre order\n";

    IpreOrder(root);
    cout<<" this is iterative pre order\n"; */

    /* RpostOrder(root);
    cout<<" this is recursive post order\n";

    IpostOrder(root);
    cout<<" this is iterative post order\n"; */



    /*RinOrder(root);
    cout<<" this is recursive in order\n"; */


    return 0;
}
