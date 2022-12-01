#include<bits/stdc++.h>
using namespace std;

void selectionSort(int A[], int n) {
    int i,j,k;
    for(i = 0; i<n-1; i++) {
        for(j=k=i; j<n; j++) {
            if(A[j]<A[k]) k = j;
        }
        swap(A[i], A[k]);
    }
}

int main() {
    int arr[] = {2,4,13,6,7,11,3,5,9};
    int size = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr,size);

    for(auto i:arr) cout<<i<<" ";
    return 0;
}