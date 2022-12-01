#include<bits/stdc++.h>
using namespace std;

void Insert(int A[], int n) {
    int temp, i = n;
    temp = A[n];
    while(i>1 && temp > A[i/2]) {
        A[i] = A[i/2];
        i = i/2;
    }
    A[i] = temp;
}

int deletion(int A[], int n) {
    int i,j,deletedValue;
    deletedValue = A[1];
    A[1] = A[n]; // taking the last element of heap
    i = 1;
    j = 2*i;
    while(j<n-1) {
        if(A[j+1] > A[j]) j = j + 1;
        if(A[i] < A[j]) {
            swap(A[i], A[j]);
            i = j;
            j = 2*i;
        } else break;
    }
    A[n] = deletedValue; 
    return deletedValue;
}

int main() {

    int arr[] = {0,2,5,8,9,4,10,7};

    int size = sizeof(arr) / sizeof(arr[0]) - 1;
    for(int i = 2; i<=size; i++) {  // here i = 2 since index is starting from 1 instead of 0 and only one element in heap is already in heap so we need a minimum of 2 elements.
        Insert(arr,i);
    }

    /* heap sort */
    for(int i = size; i>1; i--) {
        deletion(arr,i);
    }
    
    for(int i =1; i<=size; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}