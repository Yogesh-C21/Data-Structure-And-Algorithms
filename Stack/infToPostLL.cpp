#include<bits/stdc++.h>
using namespace std;

struct Node {
	char data;
    Node* next;
}*Top = NULL;

void push(char element) {
    struct Node* temp = new Node;
    if(!temp) cout<<"Stack Overflow\n"; // will check whether temp node is created inside heap
    else {
		temp->data = element;
        temp->next = Top;
        Top = temp;
    }
}

char pop() {
    int deletedChar = 32;
    if(!Top) cout<<"Stack Is Empty\n";
    else{
        deletedChar = Top->data;
        struct Node* temp = Top;
        Top = Top->next;
        delete temp;
    }
    return deletedChar;
}

void display() {
    Node* p = Top;
    while(p) {
        cout<<p->data<<endl;
        p = p->next;
    }
}

int isOperand(char x) {
    return (x >= 42 && x<=47) ? 0 : 1; // in terms of ASCII codes  (extra symbols are included but its okay for this case)
}


int pre(char x) {
    if(x == '+' || x == '-') return 1;
    else if(x == '*' || x == '/') return 2;
    return 0;
}

/*********** infix to postfix conversion *********/

char* convert(char* infix) {
    char* postfix = new char[strlen(infix) + 1];
    int i=0, j=0;
    while(infix[i] != '\0') {
        if(isOperand(infix[i])) postfix[j++] = infix[i++];
        else {
            if(pre(infix[i]) > pre(Top->data)) push(infix[i++]);
            else postfix[j++] = pop();
        }
    }
    while(Top) postfix[j++] = pop();
    postfix[j] = '\0';
    return postfix;
}

int main() {
//	push(66);
//	push(110);
//	display();

    push(32); // space in ASCII
    char* infix = "a+b*c-d/e";
    char* postfix = convert(infix);
    cout<<postfix;

 
//    cout<<pre('a')<<" precendence func\n";

/*    push(&st, 34);
    push(&st, 112);
    display(st);

    cout<<stackTop(st)<<endl;
    cout<<isEmpty(st)<<endl; */

    


}