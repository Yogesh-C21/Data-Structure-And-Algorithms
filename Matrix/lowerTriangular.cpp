#include<bits/stdc++.h>
using namespace std;

class lowerTriangular {
    private:
    int *A;
    int n;
    public:
    lowerTriangular(int n) {
        this->n=n;
        A = new int[n];
    }

    /* Column Major Implementation */
    void Cset(int i, int j, int x) {
        if(i>=j) A[n*(j-1) - (j-1)*(j-2)/2 + i-j] = x;
    }
    void Cdisplay() {
        for(int i=1; i<=n; i++) {
                for(int j=1; j<=n; j++) {
                    if(i>=j) {
                        if(i>=j) cout<<A[n*(j-1) - (j-1)*(j-2)/2 + i-j]<<" ";
                    }
                    else cout<<"0 ";
                }
                cout<<endl;
            }
    }

    /* Row Major Implementation */
    void Rset(int i, int j, int x) {
        if(i>=j) A[i*(i-1)/2 + j-1] = x;
    }
    void Rdisplay() {
        for(int i=1; i<=n; i++) {
                for(int j=1; j<=n; j++) {
                    if(i>=j) {
                        if(i>=j) cout<<A[i*(i-1)/2 + j-1]<<" ";
                    }
                    else cout<<"0 ";
                }
                cout<<endl;
            }
        cout<<sizeof(A)/sizeof(A[0]);
    }
    ~lowerTriangular() {
        delete []A;
    }
};

int main() {
    int dim, element;
    cout<<"Enter Dimensions\n";
    cin>>dim;
    lowerTriangular lowerT(dim);

    /* Row major implementation */

    for(int i=1; i<=dim; i++) {
        for(int j=1; j<=dim; j++) {
            if(i>=j) {
                cout<<"Enter element for "<<i<<" "<<j<<" address of the matrix\n";
                cin>>element;
                lowerT.Rset(i,j,element);
            }
        }
    }
    lowerT.Rdisplay();




    /* Column Major Implementation */

    /* for(int i=1; i<=dim; i++) {
        for(int j=1; j<=dim; j++) {
            if(i>=j) {
                cout<<"Enter element for "<<i<<" "<<j<<" address of the matrix\n";
                cin>>element;
                lowerT.Cset(i,j,element);
            }
        }
    }
    lowerT.Cdisplay(); */
}