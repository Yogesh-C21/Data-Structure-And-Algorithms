#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int A[], int n) {
    int i,j;
    int flag; // flag for checking adaptiveness of the algorithm
    for(i=0; i<n-1; i++) {
        flag = 0;
        for(j=0; j<n-i-1; j++) {
            if(A[j]>A[j+1]) {
                swap(A[j],A[j+1]);
                flag = 1;
            }
        }
        if(flag == 0) break;
    }
}

int main() {
    int arr[] = {2,4,1,6,0,11,3,5,9};
    int size = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr,size);

    for(auto i:arr) cout<<i<<" ";

}