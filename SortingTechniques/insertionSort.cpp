#include<bits/stdc++.h>
using namespace std;

void insertionSort(int A[], int n) {
    int x,j;
    for(int i = 1; i<n; i++) {
        j = i - 1;
        x = A[i];
        while(j>-1 && A[j]>x) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}

int main() {
    int arr[] = {2,4,13,6,7,11,3,5,9};
    int size = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr,size);

    for(auto i:arr) cout<<i<<" ";
    return 0;
}