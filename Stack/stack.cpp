#include<bits/stdc++.h>
using namespace std;

struct Stack {
    int size;
    int top;
    int *S;
};

void create(struct Stack* st) {
    cout<<"Enter Size of stack\n";
    cin>>st->size;
    st->top = -1;
    st->S = new int[st->size];
}

/* Push -> adding element at top of stack*/

void push(struct Stack* st, int element) {
    if(st->top == st->size-1) cout<<"Stack Overflow";
    else {
        st->top++;
        st->S[st->top] = element;
    }
}

/* Pop -> removing element from top of stack */

int pop(struct Stack* st) {
    int popElement = 0;
    if(st->top == -1) cout<<"Stack Underflow\n";
    else {
        popElement = st->S[st->top];
        st->top--;
    }
    return popElement;
}

void display(struct Stack st) {
    while(st.top > -1) {
        cout<<st.S[st.top--]<<" is element of stack of index "<<st.top<<endl;
    }  // decrement will be done after the above line in entirety will execute
}


int main() {
    struct Stack st;

    create(&st);

    push(&st, 3);
    push(&st, 6);
    push(&st, 4);


    push(&st, 3);   // push call
    
    cout<<pop(&st)<<" is the element popped from the stack\n";   //pop call


    /* final stack display*/

    display(st);
}