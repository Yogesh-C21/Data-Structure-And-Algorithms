#include<bits/stdc++.h>
using namespace std;

int maxElement(int A[], int n) {
    int maxEle = INT_MIN;
    for(int i=0; i<n; i++) {
        if(A[i]>maxEle) maxEle = A[i];
    }
    return maxEle;
}

void countSort(int A[], int n) {
    int i,j;
    int size = maxElement(A,n);
    int hash[size+1] = {0};

    for(i=0;i<n;i++) hash[A[i]]++;
    i = j= 0;
    while(i<size+1){
        if(hash[i]>0) {
            A[j++] = i;
            hash[i]--;
        } else i++;
    }
}

int main() {
    int arr[] = {3,10,23,14,16};
    int size = sizeof(arr) / sizeof(arr[0]);
    countSort(arr,size);

    for(auto i:arr) cout<<i<<" ";
    return 0;

}