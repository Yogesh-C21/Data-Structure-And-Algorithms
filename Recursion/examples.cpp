#include<iostream>
using namespace std;

int sum(int n) {
    if(n>0) {
        return n + sum(n-1);
    }
    return 0;

}

int factorial(int n) {
    if(n>1) {
        return n*factorial(n-1);
    }
    return 1;
}

int fibonacci(int n) {
    static int sum = 0;
    if(n<=1) return n;
    return fibonacci(n-2) + fibonacci(n-1);
}


int power(int m, int n) {
    if(n>0) {
        return m*power(m, n-1);
    }
    return 1;
}

int FIB[10];

int main() {
    int n;
    cin>>n;
    for(
    cout<<sum(n)<<" is sum\n";
    cout<<factorial(n)<<" is factorial\n";
    cout<<fibonacci(n)<<" is the term fibonacci series\n";
    cout<<power(2,n)<<" is the final value by power using recursion";
}