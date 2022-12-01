/*********** infix to postfix conversion *********/



char* convert(char* infix) {
    char* postfix = new char[strlen(infix) + 1];
    int i=0, j=0;
    while(infix[i] != '\0') {
        if(isOperand(infix[i])) postfix[j++] = infix[i++];
        else {
            if(pre(infix[i]) > pre(stackTop(st))) push(&st, infix[i++]);
            else postfix[j++] = pop(&st);
        }
    }
    while(!isEmpty(st)) {
        postfix[j++] = pop(&st);
        postfix[j] = '\0';
    }
    return postfix;
}