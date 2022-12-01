#include<bits/stdc++.h>
using namespace std;

void merge(int A[], int l, int mid, int h) {
    int i,j,k;
    int B[h+1];
    i = l;
    j= mid + 1;
    k = l;
    while(i <= mid && j <= h) B[k++] = (A[i]<A[j]) ? A[i++] : A[j++];
    while(i<=mid) B[k++] = A[i++];
    while(j<=h) B[k++] = A[j++];
    for(i=l; i<=h; i++) A[i] = B[i];
}

void IMergeSort(int A[], int n) {
    int p,i,l,mid,h;   // here it create problems for n = 7 // do not sorts properly 
    for(p=2; p<=n; p*=2) {
        for(i=0; i+p-1<n; i=i+p) {
            l=i;
            h=i+p-1;
            mid = (l+h)/2;
            merge(A,l,mid,h);
        }
    }
    if(p/2<n) merge(A,0,p/2-1,n);   
}

void RmergeSort(int A[], int l,int h) {
    if(l<h) {            //**this is in the postorder form
        int mid = (l+h)/2;
        RmergeSort(A,l,mid);
        RmergeSort(A,mid+1,h);
        merge(A,l,mid,h);
    }
}

int main() {
    int arr[] = {3,10,23,14,16,-21,0};
    int size = sizeof(arr) / sizeof(arr[0]);
    RmergeSort(arr,0,size-1);

    for(auto i:arr) cout<<i<<" ";
    return 0;

}