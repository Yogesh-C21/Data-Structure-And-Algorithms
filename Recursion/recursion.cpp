#include<bits/stdc++.h>
using namespace std;

void fun1(int n) {        // first print the value and then calls the function
    if(n>0) {
        cout<<n;
        fun1(n-1);
    }
}

void fun2(int n) {   // first function call then print the value of n
    if(n>0) {
        fun2(n-1);
        cout<<n;
    }
}

void funcTreeRecursion(int n) {
    if(n>0) {
        cout<<n;
        funcTreeRecursion(n-1);
        funcTreeRecursion(n-1);
    }
}

int main() {
    /* int x = 4;
    fun1(x);
    int y = 4;
    fun2(y); */
    int x = 3;
    funcTreeRecursion(x);
}