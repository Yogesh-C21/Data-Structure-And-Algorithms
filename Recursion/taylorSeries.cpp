#include<bits/stdc++.h>
using namespace std;

double taylor(int x, int n) {
    static double num = 1;
    static double deno = 1;
    double result;
    if(n==0) return 1;
    result = taylor(x, n-1);
    deno = deno * n;
    num = num * x;
    return result + num/deno;
}

int main() {
    cout<<taylor(4, 100);
    return 0;
}