#include<bits/stdc++.h>
using namespace std;

class Diagonal {
    private:
    int *A;  // pointer to created dynamic array
    int n;  //size of n*n matrix
    public:
    Diagonal(int n) {
        this->n=n;
        A = new int[n];
    }
    void set(int i, int j, int x);
    int get(int i, int j);
    void Display();
    ~Diagonal() {
        delete []A;
    }
};

void Diagonal::set(int i, int j, int x) {
    if(i==j) {
        A[i-1] = x;
    }
}

int Diagonal::get(int i, int j) {
    if (i==j) return A[i-1];
    else return 0;
}

void Diagonal::Display() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i==j) cout<<A[i]<<" ";
            else cout<<"0 ";
        }
        cout<<endl;
    }
}

int main() {
    int n;
    cin>>n;
    Diagonal d(n);
    for(int i =1; i<=n; i++) {
        int element;
        cin>>element;
        d.set(i,i,element);
    }
    d.Display();
}