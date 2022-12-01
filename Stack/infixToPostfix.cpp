#include<bits/stdc++.h>
using namespace std;

struct Stack {
    int size;
    int top;
    char *S;
};

void create(struct Stack* st) {
    cout<<"Enter Size of stack -> ";
    cin>>st->size;
    st->top = -1;
    st->S = new char[st->size];
}

/* Push -> adding element at top of stack*/

void push(struct Stack* st, char element) {
    if(st->top == st->size-1) cout<<"Stack Overflow";
    else {
        st->top++;
        st->S[st->top] = element;
    }
}

/* Pop -> removing element from top of stack */

int pop(struct Stack* st) {
    char popElement = 32; // space
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

int isOperand(char x) {
    return (x >= 42 && x<=47) ? 0 : 1; // in terms of ASCII codes  (extra symbols are included but its okay for this case)
}


int pre(char x) {
    if(x == '+' || x == '-') return 1;
    else if(x == '*' || x == '/') return 2;
    return 0;
}

int stackTop(struct Stack st){
    return (st.top == -1) ? -1 : st.S[st.top];
}

int isEmpty(struct Stack st) {
    return (st.top == -1) ? 1 : 0;
}


/*********** infix to postfix conversion *********/



char* convert(char* infix, struct Stack* st1) {
    char* postfix = new char[strlen(infix) + 1];
    int i=0, j=0;
    while(infix[i] != '\0') {
        if(isOperand(infix[i])) postfix[j++] = infix[i++];
        else {
            if(pre(infix[i]) > pre(stackTop(&st1))) push(&st1, infix[i++]);
            else postfix[j++] = pop(&st1);
        }
    }
    while(!isEmpty(st1)) {
        postfix[j++] = pop(&st1);
        postfix[j] = '\0';
    }
    return postfix;
}


int main() {
    struct Stack st;
    create(&st); // create and initialize stack

    string infix = "a+b*c-d/e";
    string postfix = convert(infix, &st);
    cout<<postfix;


/* 
    cout<<pre('a')<<" precendence func\n";

    push(&st, 32);
    push(&st, 12);
    display(st);

    cout<<stackTop(st)<<endl;
    cout<<isEmpty(st)<<endl; */

    


}