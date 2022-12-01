#include<bits/stdc++.h>
using namespace std;

struct term {
    int exp;
    int coeff;
};

struct poly {
    int n;
    struct term *terms;
};

void create(struct poly *p) {
    cout<<"No. of Terms\n";
    cin>>p->n;
    p->terms = new term[p->n];
    for(int i=0; i<p->n; i++) {
        cin>>p->terms[i].coeff>>p->terms[i].exp;
    }
}

struct poly *add(struct poly *p1, struct poly *p2) {
    struct poly *sum;
    int i,j,k;
    sum = new poly;
    sum->terms = new term[p1->n + p2->n];
    i=j=k=0;
    while(i<p1->n && j<p2->n) {
        if(p1->terms[i].exp > p2->terms[j].exp) {
            sum->terms[k++] = p1->terms[i++];
        } else if(p1->terms[i].exp < p2->terms[j].exp) {
            sum->terms[k++] = p2->terms[j++];
        } else {
            sum->terms[k].exp = p1->terms[i].exp || p2->terms[j].exp;
            sum->terms[k++].coeff = p1->terms[i++].coeff + p2->terms[j++].coeff;
        }
    }
    
    for(;i<p1->n; i++) sum->terms[k++] = p1->terms[i];
    for(;j<p2->n; j++) sum->terms[k++] = p2->terms[j];
    sum->n = k;
    /* for(int i=0; i<(sum->n)-1; i++) {
      for(int j=0; j<sum->n; j++) {
        if(sum->terms[i].exp=sum->terms[j].exp) {
            sum->terms[i].coeff = sum->terms[i].coeff + sum->terms[j].coeff;
            k--;
        }
      }
    }
    sum->n = k; */
    return sum;
}

void display(struct poly p) {
    for(int i=0; i<p.n; i++) {
        cout<<p.terms[i].coeff<<"x"<<p.terms[i].exp<<"+ ";
    }
    cout<<endl;
}

int main() {
    struct poly *p1;  // m1 for pointer declaration
    p1 = new poly;  // pointer that will point to new memory block inside the heap
    create(p1);  // will use this since it will point to the dynamically created object (remember this notation and implementation)
    display(*p1);   // de-referencing


    struct poly p2, *p3;

    create(&p2);
    
    p3 = add(p1,&p2);
    display(*p3);
}