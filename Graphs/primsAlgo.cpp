#include<bits/stdc++.h>
#define I INT_MAX // I = taken as inf number
using namespace std;

int cost[6][6] = {{I,I,I,I,I,I},
                  {I,I,12,I,6,4},
                  {I,12,I,8,I,14},
                  {I,I,8,I,11,9},
                  {I,6,I,11,I,I},
                  {I,4,14,9,I,I}};


int main() {
    int t[2][5];
    int near[6] = {I,I,I,I,I,I};
    int mini = I,u,v;
    for(int i=1; i<=5; i++) {         // code for upper triangular matrix
        for(int j=i+1; j<=5; j++) {
            if(cost[i][j]<mini) {
                mini = cost[i][j];
                u = i;
                v = j;
            }
        }
    }
    int x; //for traversing in array t along x axis
    t[0][0] = u;
    t[1][0] = v;
    near[u] = near[v] = 0;

        for(int i =1; i<6; i++) {
            if(near[i]!=0) {
                near[i] = (cost[i][u]<cost[i][v]) ? u : v;
            }
        }
/* till now were initial steps */

for(x=1;x<5;x++){
    int k;
    mini = I;
        for(int i=1; i<6; i++) {
            if(near[i]!=0 && mini>cost[i][near[i]]) {
                mini = cost[i][near[i]];
                k = i;
            }    
        }
        t[0][x] = k;
        t[1][x] = near[k];
        near[k] = 0;
        for(int i=0; i<6;i++){
            if(near[i]!=0 && cost[i][near[i]]>cost[i][k]) near[i] = k;
        }
    }
    for(x=0;x<5;x++){
    cout<<t[0][x]<<" "<<t[1][x]<<endl;
    }
}