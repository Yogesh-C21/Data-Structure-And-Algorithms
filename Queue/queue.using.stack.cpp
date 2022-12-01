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

void push(struct Stack* st, int element) {
    if(st->top == st->size-1) cout<<"Stack Overflow";
    else {
        st->top++;
        st->S[st->top] = element;
    }
}

void enqueue(struct Stack* st1, struct Stack* st2) {
	st2->top = -1;
	st2->S = new int[st1->size];
	while((st1->top) > -1) {
		st2->top++;
		st2->S[st2->top] = st1->S[st1->top--];
	}
}

void display(struct Stack st) {
    while(st.top > -1) {
        cout<<st.S[st.top--]<<" ";
    }
}

int main() {
	struct Stack st,st2;
	create(&st);
	push(&st, 10);
	push(&st, 20);
	push(&st, 30);
	push(&st, 40);
	
	enqueue(&st,&st2);
	
	display(st2);
	
		
	return 0;
}
