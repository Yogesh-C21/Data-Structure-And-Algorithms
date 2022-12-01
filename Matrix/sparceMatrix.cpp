#include<bits/stdc++.h>
using namespace std;

class element {
    public:
    int i;
    int j;
    int x;
};

class Sparse {
    private:
    int m;   // row
    int n;  // column
    int num;
    element *ele;
    public:
    Sparse(int m, int n, int num) {
        this->m = m;
        this->n = n;
        this->num = num;
        ele = new element[this->num];
    }
    void read() {
        cout<<"Enter the elements"<<endl;
        for(int i = 0; i<num; i++) {
            cin>>ele[i].i>>ele[i].j>>ele[i].x;
        }
    }
    void display() {
        int k =0;
        for(int i= 0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(ele[k].i == i && ele[k].j == j) cout<<ele[k++].x<<" ";
                else cout<<"0 ";
            }
            cout<<endl;
        }
    }
};

void add(Sparse *s1, Sparse *s2) {

}

int main() {
    Sparse s1(3,2,4);
    s1.read();
    s1.display();
}