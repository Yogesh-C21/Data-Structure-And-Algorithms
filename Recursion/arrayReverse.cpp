#include<bits/stdc++.h>
using namespace std;

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void reverseArrayByRotation(int arr[], int n) {
    int index = 0;
    while(index<n) {
        int start = arr[0];
        for(int i = 0; i < n-1; i++) {
            arr[i] = arr[i+1];
        }
        arr[n-1] = start;
        index++;
    }
    for(int i = 0; i < n; i++) {
        cout<<arr[i];
    }   
}

void reverseArray(int arr[], int n) {
    int start = 0;
    int end = n - 1;
    while(start<=end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
}

int main() {
    int arr[] = {2,6,4,2,1,-1,5,3,6,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    // reverseArray(arr, size);
    reverseArrayByRotation(arr, size);
    return 0;
}