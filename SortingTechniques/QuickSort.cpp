#include<bits/stdc++.h>
using namespace std;

int partition(int A[], int l, int h) {
    int pivot = A[l];
    int i = l, j = h;
    do {
        do {
            i++;
        } while(A[i]<=pivot);
        do {
            j--;
        } while(A[j]>pivot);
        if(i<j) {
            swap(A[i],A[j]);
        }
    } while(i<j);
    swap(A[j], A[l]);
    return j;
}

void quickSort(int A[], int l, int h) {
    int j;
    if(l<h) {
        j = partition(A,l,h);
        quickSort(A,l,j); // the element at j will act as infinity for the elements smaller than itself
        quickSort(A,j+1,h);
    }
}

int main() {
    int arr[] = {2,4,13,6,7,11,3,5,9,INT_MAX};
    int size = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr,0,size-1);

    for(auto i:arr) cout<<i<<" ";
    return 0;
}