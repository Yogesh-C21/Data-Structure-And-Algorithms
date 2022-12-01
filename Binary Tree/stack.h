#include<bits/stdc++.h>
#define stackSize 100  // here we have defined the size of stack
using namespace std;

struct Stack {
    int size;
    int top;
    struct Node **S;
};

void createStack(struct Stack* st) {
    st->size = stackSize;
    st->top = -1;
    st->S = new Node*[st->size];
}

/* Push -> adding element at top of stack*/

void push(struct Stack* st, struct Node* element) {
    if(st->top == st->size-1) cout<<"Stack Overflow";
    else {
        st->top++;
        st->S[st->top] = element;
    }
}

/* Pop -> removing element from top of stack */

struct Node* pop(struct Stack* st) {
    struct Node* popAddress = NULL;
    if(st->top == -1) cout<<"Stack Underflow\n";
    else {
        popAddress = st->S[st->top];
        st->top--;
    }
    return popAddress;
}

int isEmpty(struct Stack st) {
    return (st.top == -1) ? 1 : 0;
}
