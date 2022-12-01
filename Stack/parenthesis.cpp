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

/*
This method don't checks whether the parenthesis is proper or not it only checks no of backets are matching or not (i.e., balance)
*/

bool parenthesis(char* exp) {
	int i = 0;
	while(exp[i]!='\0') {
		if(exp[i] == '(') {
			push('(');
			i++;
		} else if(exp[i] == ')') {
			if(!Top) return false;
            pop();
			i++;
		} else i++;
	}
	return (!Top) ? true : false;
}


/* Method 2 : For checking every type of bracked and their occurance */
bool parenthesis2(char* exp) {
	int i = 0;
	while(exp[i]!='\0') {
		if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
			push(exp[i]);
		} else if(exp[i] == ')') {
			if(!Top) return false;
			if((exp[i] - 1) == Top->data) {
				pop();
			} else return false;
		} else if(exp[i] == ']' || exp[i] == '}') {
			if(!Top) return false;
			if((exp[i] - 2) == Top->data) {
				pop();
			} else return false;
		}
		i++;
	}
	return (!Top) ? true : false;
}

/* Method 2.2 : Negative Code: optimized method 2 */

bool parenthesis2NegCode(char* exp) {
	int i = 0;
	while(exp[i]!='\0') {
		if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{') push(exp[i]);
		else if(exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
			if(!Top) return false;
			if((exp[i] - ((exp[i] == ')') ? 1 : 2)) == Top->data) pop();
            else return false;
		}
        i++;
	}
	return (!Top) ? true : false;
}

int main() {
    char* str = "({)(}(a+b)*(c-d))";
    cout<<parenthesis2NegCode(str);


    return 0;
}